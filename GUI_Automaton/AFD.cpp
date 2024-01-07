#include "AFD.h"

AFD::AFD(std::set<char> states,
    std::set<char> alphabet,
    std::map<std::pair<char, char>, char> transitions,
    char initialState,
    std::set<char> finalStates)
    : states(std::move(states)),
    alphabet(std::move(alphabet)),
    transitions(std::move(transitions)),
    initialState(initialState),
    finalStates(std::move(finalStates))
{
    
}
