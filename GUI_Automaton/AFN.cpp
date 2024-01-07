
#include "AFN.h"

AFN::AFN() : initialState('\0') {}

void AFN::addState(char state) {
    states.insert(state);
}

void AFN::addAlphabetSymbol(char symbol) {
    alphabet.insert(symbol);
}

void AFN::addTransition(char fromState, char symbol, char toState) {
    transitions[{fromState, symbol}].insert(toState);
}

void AFN::setInitialState(char state) {
    initialState = state;
}

void AFN::addFinalState(char state) {
    finalStates.insert(state);
}

void AFN::display() const {
    std::cout << "AFN States: ";
    for (char state : states) {
        std::cout << state << " ";
    }
    std::cout << std::endl;

    // Adaugă restul afișării pentru AFN
}
