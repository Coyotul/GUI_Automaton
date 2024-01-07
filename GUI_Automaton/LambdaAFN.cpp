#include "LambdaAFN.h"

LambdaAFN::LambdaAFN(std::set<char> states,
    std::set<char> alphabet,
    std::map<std::pair<char, char>, std::unordered_set<char>> transitions,
    char initialState,
    std::unordered_set<char> finalStates)
    : states(std::move(states)),
    alphabet(std::move(alphabet)),
    transitions(std::move(transitions)),
    initialState(initialState),
    finalStates(std::move(finalStates))
{
    
}