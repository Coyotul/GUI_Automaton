#include "GUI_Automaton.h"
#include <QMouseEvent>


char q = 'a';

GUI_Automaton::GUI_Automaton(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

GUI_Automaton::~GUI_Automaton()
{}


void GUI_Automaton::mouseReleaseEvent(QMouseEvent* e)
{
    if (e->button() == Qt::RightButton)
    {

    }
    else if (e->button() == Qt::LeftButton)
    {
        std::vector<char> stari = automaton.getStari();
        std::vector<std::pair<int, int>> posStari = automaton.getPozitieStari();
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
            }
        }
    }
    else if (e->button() == Qt::MiddleButton)
    {

    }

}

void GUI_Automaton::paintEvent(QPaintEvent* e)
{
    
}
