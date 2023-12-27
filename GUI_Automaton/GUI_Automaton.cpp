#include "GUI_Automaton.h"

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
        
    }
    else if (e->button() == Qt::MiddleButton)
    {

    }

}

void GUI_Automaton::paintEvent(QPaintEvent* e)
{
    
}
