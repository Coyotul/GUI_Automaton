#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QComboBox>  
#include "ui_GUI_Automaton.h"
#include "Automaton.h"
#include "AFN.h"
#include "AFD.h"
#include "LambdaAFN.h"
#include "APD.h"
#include <queue>

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
    void createAutomatonInstance(const QString& type);
    void mouseReleaseEvent(QMouseEvent* e);
    void paintEvent(QPaintEvent* e);
    void keyPressEvent(QKeyEvent* event);
    Automaton convertIntoDFA();
    void preluareFisier();


private:
    Ui::GUI_AutomatonClass ui;
    Automaton automaton;
    Automaton* automaton2;
    std::pair<int, int> primaStare = std::make_pair(0, 0);
    int indexStareSelectata = -1;
    QComboBox* automatonTypeComboBox;
};
