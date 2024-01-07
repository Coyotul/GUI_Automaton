#include "AFN.h"

AFN::AFN(std::set<char> states,
    std::set<char> alphabet,
    std::map<std::pair<char, char>, std::set<char>> transitions,
    char initialState,
    std::set<char> finalStates)
    : states(states),
    alphabet(alphabet),
    transitions(transitions),
    initialState(initialState),
    finalStates(finalStates) {}
