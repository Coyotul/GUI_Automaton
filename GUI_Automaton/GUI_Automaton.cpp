#include "GUI_Automaton.h"
#include <QMouseEvent>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QPainter>
#include <fstream>

char q = 'a';
char simbolTranzitie = 'λ';
int automatonType = 0;


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
        automatonType = 1;
    }
    else if (type == "AFD") {
        automaton2 = new AFD();
        automatonType = 2;
    }
    else if (type == "LambdaAFN") {
        automaton2 = new LambdaAFN();
        automatonType = 3;

    }
    else if (type == "PDA") {
        automaton2 = new APD();
        automatonType = 4;
    }
    else 
{
        // Handle invalid type
    }
}


void GUI_Automaton::preluareFisier()
{
    std::ifstream f("input.txt");
    std::vector<std::string> words;
    std::string word;
    while (f >> word)
    {
        words.push_back(word);
    }
    std::ofstream g("VerificareCuvinte.txt");
    g << words.size() << '\n';
    for (auto it : words)
    {
        if (automaton.CheckWord(it, 0, 0))
            g << "Cuvantul " << it << " este acceptat de automat\n\n";
        else
            g << "Cuvantul " << it << " nu este acceptat de automat\n\n";
    }
}

void GUI_Automaton::mouseReleaseEvent(QMouseEvent* e)
{
    
    std::ofstream g("output.txt");
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
                    if(ui.input->text().size() == 0)
                        if (ui.input->text().size() != 0)
                        {
                            automaton.adaugaTranzitie(std::make_pair(automaton.getStari()[indexStareSelectata], ui.input->text().toStdString()[0]), automaton.getStari()[i]);
                            automaton.adaugaSimbol(ui.input->text().toStdString()[0]);
                        }
                        else
                        {
                            automaton.adaugaTranzitie(std::make_pair(automaton.getStari()[indexStareSelectata], simbolTranzitie), automaton.getStari()[i]);
                            automaton.adaugaSimbol(simbolTranzitie);
                        }
                    else
                        if(ui.input->text().size() == 1)
                            if (ui.input->text().size() != 0)
                            {
                                automaton.adaugaTranzitie(std::make_pair(automaton.getStari()[indexStareSelectata], ui.input->text().toStdString()[0]), automaton.getStari()[i]);
                                automaton.adaugaSimbol(ui.input->text().toStdString()[0]);
                            }
                            else
                            {
                                automaton.adaugaTranzitie(std::make_pair(automaton.getStari()[indexStareSelectata], simbolTranzitie), automaton.getStari()[i]);
                                automaton.adaugaSimbol(simbolTranzitie);
                            }
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
        if (stari.size() == 0)
        {
            if (automatonType != 3)
            {
                simbolTranzitie = 'b';
            }
            automaton.seteazaSimbolInitial(q);
        }
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
        std::vector<char> stari = automaton.getStari();
        std::vector<std::pair<int, int>> posStari = automaton.getPozitieStari();
        for (int i = 0; i < stari.size(); i++)
        {
            int index = -1;;
            for (int i = 0;i<stari.size();i++)
                if (fabs(e->pos().x() - posStari[i].first) < 10 &&
                    fabs(e->pos().y() - posStari[i].second) < 10)
                {
                    index = i;
                }
            if (index!=-1)
            {
                automaton.adaugaStareFinala(stari[i]);
                automaton.addPozitieStare(std::make_pair(e->pos().x(), e->pos().y()));
                q++;
                break;
            }
        }
    }

}


void GUI_Automaton::keyPressEvent(QKeyEvent* event) {
    std::ofstream f("output.out");

    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        if (automaton.CheckWord(ui.input_2->text().toStdString(), 0, 0))
            f << "Cuvantul " << ui.input_2->text().toStdString() << " este acceptat de automat\n\n";
        else
            f << "Cuvantul " << ui.input_2->text().toStdString() << " nu este acceptat de automat\n\n";
    }
    else if (event->key() == Qt::Key_Alt)
    {
        automaton.PrintAutomaton();
    }
    else if (event->key() == Qt::Key_Shift)
    {
        preluareFisier();
    }
    else if (event->key() == Qt::Key_Tab) //try to convert into DFA
    {
        std::map<std::pair<char, char>, std::vector<char>> currentTransitions = this->automaton.getTranzitii();
        if (automatonType==2)
            for (auto it : currentTransitions)
            {
                if (it.second.size() >= 2)
                {
                    f << "Automatul nu este bun";
                    this->automaton = convertIntoDFA();
                }
            }
        else {
            f << "Automatul nu este AFD";
        }
    }
    else {
        QWidget::keyPressEvent(event);
    }
}

Automaton GUI_Automaton::convertIntoDFA()
{
    Automaton& automaton = this->automaton;
    Automaton convertedAFN;

    // Funcție pentru calculul epsilon-closure al unei stări în AFN
    auto epsilonClosure = [&](char state) -> std::set<char> {
        std::set<char> closure;
        std::queue<char> stateQueue;
        stateQueue.push(state);
        closure.insert(state);

        while (!stateQueue.empty()) {
            char currentState = stateQueue.front();
            stateQueue.pop();

            auto transition = automaton.getTranzitii().find({ currentState, 'λ' });
            if (transition != automaton.getTranzitii().end()) {
                for (char nextState : transition->second) {
                    if (closure.find(nextState) == closure.end()) {
                        closure.insert(nextState);
                        stateQueue.push(nextState);
                    }
                }
            }
        }

        return closure;
        };

    // Funcție pentru verificarea dacă un set de stări conține cel puțin o stare finală în AFN
    auto containsFinalState = [&](const std::set<char>& states) -> bool {
        for (char state : states) {
            if (std::find(automaton.getStariFinale().begin(), automaton.getStariFinale().end(), state) != automaton.getStariFinale().end()) {
                return true;
            }
        }

        return false;
        };

    // Funcție pentru crearea unei noi stări în AFN și adăugarea acesteia
    auto createNewState = [&](const std::set<char>& state) -> char {
        char newState = 'A' + convertedAFN.getStari().size();  // Presupunem că stările sunt etichetate cu litere
        convertedAFN.adaugaStare(newState);

        for (char symbol : convertedAFN.getSimboluri()) {
            convertedAFN.adaugaTranzitie({ newState, symbol }, {});
        }

        return newState;
        };

    // Initializează starea inițială a AFN cu epsilon-closure a stării inițiale din AFN
    std::set<char> initialClosure = epsilonClosure(automaton.getStareInitiala());
    convertedAFN.seteazaSimbolInitial(createNewState(initialClosure));

    // Coada pentru explorarea noilor stări în AFN
    std::queue<std::set<char>> stateQueue;
    stateQueue.push(initialClosure);

    // Mapare între seturi de stări și stările corespunzătoare în AFN
    std::map<std::set<char>, char> stateMapping;
    stateMapping[initialClosure] = convertedAFN.getStareInitiala();

    // Explorează stările AFN
    while (!stateQueue.empty()) {
        std::set<char> currentState = stateQueue.front();
        stateQueue.pop();

        // Explorează fiecare simbol din alfabet
        for (char symbol : convertedAFN.getSimboluri()) {
            std::set<char> nextState;

            // Calculează epsilon-closure al noii stări pe baza tranzițiilor din AFN
            for (char state : currentState) {
                auto transition = automaton.getTranzitii().find({ state, symbol });
                if (transition != automaton.getTranzitii().end()) {
                    nextState.insert(transition->second.begin(), transition->second.end());
                }
            }

            nextState = [&](const std::set<char>& states) {
                std::set<char> result;
                for (char state : states) {
                    auto epsilonResult = epsilonClosure(state);
                    result.insert(epsilonResult.begin(), epsilonResult.end());
                }
                return result;
                }(nextState);

            if (!nextState.empty()) {
                char nextStateId;

                // Verifică dacă starea a fost deja adăugată în AFN
                auto it = stateMapping.find(nextState);
                if (it == stateMapping.end()) {
                    // Adaugă starea în AFN și în coada de explorare
                    nextStateId = createNewState(nextState);
                    stateQueue.push(nextState);
                    stateMapping[nextState] = nextStateId;
                }
                else {
                    // Starea deja există în AFN
                    nextStateId = it->second;
                }

                // Adaugă tranziția în AFN
                convertedAFN.adaugaTranzitie({ stateMapping[currentState], symbol }, nextStateId);
            }
        }
    }

    // Setează stările finale ale AFN
    for (const auto& entry : stateMapping) {
        if (containsFinalState(entry.first)) {
            convertedAFN.adaugaStareFinala(entry.second);
        }
    }

    return convertedAFN;
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
            int angle = qAtan2(startPoint.y() - endPoint.y(), startPoint.x() - endPoint.x()) * 180 / 3.14159265;
            QPoint midPoint((startPoint.x() + endPoint.x()) / 2, (startPoint.y() + endPoint.y()) / 2);
            QPoint midPoint2((startPoint.x() + endPoint.x()) / 2 + 10, (startPoint.y() + endPoint.y()) / 2 + 15);
            QString s = " ";
            s[0] = it.first.second;
            p.drawText(midPoint2, s);
            p.drawLine(startPoint, endPoint);
            angle += 180;
            QPolygon arrowHead;
            arrowHead << midPoint;
            arrowHead << midPoint + QPoint(cos((angle + 30) * 3.14159265 / 180) * arrowSize,
                sin((angle + 30) * 3.14159265 / 180) * arrowSize);
            arrowHead << midPoint + QPoint(cos((angle - 30) * 3.14159265 / 180) * arrowSize,
                sin((angle - 30) * 3.14159265 / 180) * arrowSize);

            p.drawPolygon(arrowHead);
        }
    }
}
