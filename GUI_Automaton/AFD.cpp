﻿// AFD.cpp
#include "AFD.h"

AFD::AFD() : initialState('\0') {}

void AFD::addState(char state) {
    states.insert(state);
}

void AFD::addAlphabetSymbol(char symbol) {
    alphabet.insert(symbol);
}

void AFD::addTransition(char fromState, char symbol, char toState) {
    transitions[{fromState, symbol}] = toState;
}

void AFD::setInitialState(char state) {
    initialState = state;
}

void AFD::addFinalState(char state) {
    finalStates.insert(state);
}

void AFD::display() const {
    std::cout << "AFD States: ";
    for (char state : states) {
        std::cout << state << " ";
    }
    std::cout << std::endl;

    // Adaugă restul afișării pentru AFD
}