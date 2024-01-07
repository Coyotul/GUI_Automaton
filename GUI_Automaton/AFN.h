#pragma once
#include <set>
#include <map>
#include <vector>
#include <string>

class AFN
{
public:
    AFN(std::set<char> states,
        std::set<char> alphabet,
        std::map<std::pair<char, char>, std::set<char>> transitions,
        char initialState,
        std::set<char> finalStates);

private:
    std::set<char> states;
    std::set<char> alphabet;
    std::map<std::pair<char, char>, std::set<char>> transitions;
    char initialState;
    std::set<char> finalStates;
};
