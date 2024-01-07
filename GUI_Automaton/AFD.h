// AFD.h
#pragma once

#include <set>
#include <map>
#include <iostream>
#include "Automaton.h"

class AFD : public Automaton {
private:
    std::set<char> states;
    std::set<char> alphabet;
    std::map<std::pair<char, char>, char> transitions;
    char initialState;
    std::set<char> finalStates;

public:
    AFD();
    void addState(char state);
    void addAlphabetSymbol(char symbol);
    void addTransition(char fromState, char symbol, char toState);
    void setInitialState(char state);
    void addFinalState(char state);

    void display() const;
};
