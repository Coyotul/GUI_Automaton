// AFN.h
#pragma once

#include <set>
#include <map>
#include <iostream>

class AFN {
private:
    std::set<char> states;
    std::set<char> alphabet;
    
    char initialState;
    std::set<char> finalStates;

public:
    std::map<std::pair<char, char>, std::set<char>> transitions;
    AFN();
    void addState(char state);
    void addAlphabetSymbol(char symbol);
    void addTransition(char fromState, char symbol, char toState);
    void setInitialState(char state);
    void addFinalState(char state);

    void display() const;
};
