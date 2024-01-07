// AFD.h
#pragma once

#include <set>
#include <map>
#include <iostream>
#include <vector>
#include "Automaton.h"

class AFD : public Automaton {
private:
    std::vector<char> states;
    std::vector<char> alphabet;
    std::map<std::pair<char, char>, char> transitions;
    char initialState;
    std::set<char> finalStates;

public:
    AFD();
    AFD(Automaton a);
    void addState(char state);
    void addAlphabetSymbol(char symbol);
    void addTransition(char fromState, char symbol, char toState);
    void setInitialState(char state);
    void addFinalState(char state);

    void display() const;
};
