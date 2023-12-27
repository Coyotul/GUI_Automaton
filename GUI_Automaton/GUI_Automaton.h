#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GUI_Automaton.h"
#include "Automaton.h"

class GUI_Automaton : public QMainWindow
{
    Q_OBJECT

public:
    GUI_Automaton(QWidget *parent = nullptr);
    ~GUI_Automaton();
    void mouseReleaseEvent(QMouseEvent* e);
    void paintEvent(QPaintEvent* e);
private:
    Ui::GUI_AutomatonClass ui;
    Automaton automaton;
};
