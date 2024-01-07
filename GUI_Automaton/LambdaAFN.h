#pragma once
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>

class LambdaAFN
{
public:
    LambdaAFN(std::set<char> states,
        std::set<char> alphabet,
        std::map<std::pair<char, char>, std::unordered_set<char>> transitions,
        char initialState,
        std::unordered_set<char> finalStates);

private:
    std::set<char> states;
    std::set<char> alphabet;
    std::map<std::pair<char, char>, std::unordered_set<char>> transitions;
    char initialState;
    std::unordered_set<char> finalStates;
};
