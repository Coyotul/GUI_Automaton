#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GUI_Automaton.h"

class GUI_Automaton : public QMainWindow
{
    Q_OBJECT

public:
    GUI_Automaton(QWidget *parent = nullptr);
    ~GUI_Automaton();

private:
    Ui::GUI_AutomatonClass ui;
};
