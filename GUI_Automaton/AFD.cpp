// AFD.cpp
#include "AFD.h"

AFD::AFD() : initialState('\0') {}

AFD::AFD(Automaton a)
{
    this->states = a.getStari();
    this->alphabet = a.getSimboluri();

}

void AFD::addState(char state) {
    states.push_back(state);
}

void AFD::addAlphabetSymbol(char symbol) {
    alphabet.push_back(symbol);
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
