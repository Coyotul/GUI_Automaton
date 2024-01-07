#pragma once
#include <set>
#include <map>
#include <unordered_set>
#include <vector>
#include <stack>

class APD
{
public:
    APD(std::set<char> states,
        std::set<char> alphabet,
        std::set<char> stackAlphabet,
        std::map<std::tuple<char, char, char>, std::vector<std::tuple<char, std::string>>> transitions,
        char initialState,
        char stackInitial,
        std::unordered_set<char> finalStates);

    bool processInput(const std::string& input);

private:
    std::set<char> states;
    std::set<char> alphabet;
    std::set<char> stackAlphabet;
    std::map<std::tuple<char, char, char>, std::vector<std::tuple<char, std::string>>> transitions;
    char initialState;
    char stackInitial;
    std::unordered_set<char> finalStates;
};
