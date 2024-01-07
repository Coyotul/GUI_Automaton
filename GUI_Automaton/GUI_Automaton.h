#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GUI_Automaton.h"
#include "Automaton.h"
#include "AFN.h"
#include "AFD.h"
#include "LambdaAFN.h"
#include "APD.h"

enum class AutomatonType
{
    AFN,
    AFD,
    LambdaAFN,
    PDA
};

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
    Automaton automaton;  // Modificat la pointer Automaton*
    std::pair<int, int> primaStare = std::make_pair(0, 0);
    int indexStareSelectata = -1;

    // Adăugat metoda pentru crearea instanței corecte a automatului
    
};
