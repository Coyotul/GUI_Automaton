#pragma once
#include <set>
#include <map>
#include <vector>
#include <string>

class AFD
{
public:
    AFD(std::set<char> states,
        std::set<char> alphabet,
        std::map<std::pair<char, char>, char> transitions,
        char initialState,
        std::set<char> finalStates);

private:
    std::set<char> states;
    std::set<char> alphabet;
    std::map<std::pair<char, char>, char> transitions;
    char initialState;
    std::set<char> finalStates;
};