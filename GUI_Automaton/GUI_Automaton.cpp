#include "GUI_Automaton.h"
#include <QMouseEvent>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QPainter>
#include <fstream>

char q = 'a';
char simbolTranzitie = 'b';


GUI_Automaton::GUI_Automaton(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    automatonTypeComboBox = new QComboBox(this);
    automatonTypeComboBox->addItem("AFN");
    automatonTypeComboBox->addItem("AFD");
    automatonTypeComboBox->addItem("LambdaAFN");
    automatonTypeComboBox->addItem("PDA");
    //ui.layout->addWidget(automatonTypeComboBox);  // Replace with your actual layout

    // Connect QComboBox signal to slot
    connect(automatonTypeComboBox, &QComboBox::currentTextChanged, this, &GUI_Automaton::createAutomatonInstance);
}

GUI_Automaton::~GUI_Automaton()
{
    if (automaton2 != nullptr) {
        delete automaton2;
    }


}

void GUI_Automaton::createAutomatonInstance(const QString& type) {
    // Delete any existing automaton
    /*if (automaton2 != nullptr) {
        delete automaton2;
        automaton2 = nullptr;
    }*/

    // Create instances based on the selected type
    if (type == "AFN") {
        automaton2 = new AFN();
    }
    else if (type == "AFD") {
        automaton2 = new AFD();
    }
    else if (type == "LambdaAFN") {
        automaton2 = new LambdaAFN();
    }
    else if (type == "PDA") {
        automaton2 = new APD();
    }
    else {
        // Handle invalid type
    }
}

void GUI_Automaton::mouseReleaseEvent(QMouseEvent* e)
{
    std::ofstream g("output.out");
    if (e->button() == Qt::LeftButton)
    {
        std::vector<std::pair<int, int>> posStari = automaton.getPozitieStari();
        for (int i=0;i<posStari.size();i++)
        {
            if (this->primaStare == std::make_pair(0, 0))
            {
                if (fabs(e->pos().x() - posStari[i].first) < 10 &&
                    fabs(e->pos().y() - posStari[i].second) < 10)
                {
                    primaStare = std::make_pair(e->pos().x(), e->pos().y());
                    indexStareSelectata = i;
                    break;
                }
            }
            else
            {
                if (fabs(e->pos().x() - posStari[i].first) < 10 &&
                    fabs(e->pos().y() - posStari[i].second) < 10)
                {
                    automaton.adaugaTranzitie(std::make_pair(automaton.getStari()[i], simbolTranzitie), automaton.getStari()[indexStareSelectata]);
                    indexStareSelectata = -1;
                    primaStare = std::make_pair(0, 0);
                    continue;
                    break;
                }
            }
        }
        update();
    }
    else if (e->button() == Qt::RightButton)
    {
        std::vector<char> stari = automaton.getStari();
        std::vector<std::pair<int, int>> posStari = automaton.getPozitieStari();
        g << stari.size();
        for (int i=0;i<stari.size();i++)
        {
            bool stareInvalida = false;
            for(auto& it:posStari)
            if (fabs(e->pos().x() - it.first) < 10 &&
                fabs(e->pos().y() - it.second) < 10)
            {
                stareInvalida = true;
            }
            if (!stareInvalida)
            {
                automaton.adaugaStare(q);
                automaton.addPozitieStare(std::make_pair(e->pos().x(), e->pos().y()));
                q++;
                break;
            }
        }
        if (stari.size() == 0)
        {
            automaton.adaugaStare(q);
            automaton.addPozitieStare(std::make_pair(e->pos().x(), e->pos().y()));
            q++;
        }
        update();
    }
    else if (e->button() == Qt::MiddleButton)
    {

    }

}


void GUI_Automaton::paintEvent(QPaintEvent* e)
{
    QPainter p(this);
    std::vector<char> stari = automaton.getStari();
    std::vector<std::pair<int, int>> posStari = automaton.getPozitieStari();
    char q0 = 'a';
    for (int i = 0; i < stari.size(); i++)
    {
        if (indexStareSelectata == i)
        {
            QPen pen;
            pen.setColor(Qt::red);
            pen.setWidth(2);
            p.setPen(pen);
        }
        else
        {
            QPen pen;
            pen.setColor(Qt::black);
            pen.setWidth(2);
            p.setPen(pen);
        }
        QRect r(posStari[i].first - 10, posStari[i].second - 10, 20, 20);
        p.drawEllipse(r);
        QString s;
        s = q0;
        p.drawText(r, Qt::AlignCenter, s);
        q0++;
    }

    for (auto& it : automaton.getTranzitii())
    {
        for (auto& iterator : it.second)
        {
            int index1 = 0, index2 = 0;
            for (int i = 0; i < stari.size(); i++)
            {
                if (it.first.first == stari[i])
                {
                    index1 = i;
                }
                if (iterator == stari[i])
                {
                    index2 = i;
                }
            }
            QPoint startPoint(posStari[index2].first,posStari[index2].second);
            QPoint endPoint(posStari[index1].first, posStari[index1].second);

            int arrowSize = 10;
            int angle = qAtan2(endPoint.y() - startPoint.y(), endPoint.x() - startPoint.x()) * 180 / 3.14159265;
            QPoint midPoint((startPoint.x() + endPoint.x()) / 2, (startPoint.y() + endPoint.y()) / 2);

            p.drawLine(startPoint, endPoint);
            angle += 180;
            QPolygon arrowHead;
            arrowHead << midPoint;
            arrowHead << midPoint + QPoint(cos((angle - 30) * 3.14159265 / 180) * arrowSize,
                sin((angle - 30) * 3.14159265 / 180) * arrowSize);
            arrowHead << midPoint + QPoint(cos((angle + 30) * 3.14159265 / 180) * arrowSize,
                sin((angle + 30) * 3.14159265 / 180) * arrowSize);

            p.drawPolygon(arrowHead);
        }
    }
}
