#include "GUI_Automaton.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUI_Automaton w;
    w.show();
    return a.exec();
}
