#include "APD.h"
#include <tuple>
#include <iostream>

APD::APD(std::set<char> states,
    std::set<char> alphabet,
    std::set<char> stackAlphabet,
    std::map<std::tuple<char, char, char>, std::vector<std::tuple<char, std::string>>> transitions,
    char initialState,
    char stackInitial,
    std::unordered_set<char> finalStates)
    : states(std::move(states)),
    alphabet(std::move(alphabet)),
    stackAlphabet(std::move(stackAlphabet)),
    transitions(std::move(transitions)),
    initialState(initialState),
    stackInitial(stackInitial),
    finalStates(std::move(finalStates))
{
    // Additional initialization if needed
}

bool APD::processInput(const std::string& input)
{
    std::stack<char> stack;
    stack.push(stackInitial);
    char currentState = initialState;

    for (char inputSymbol : input)
    {
        char stackTop = stack.top();
        auto transitionKey = std::make_tuple(currentState, inputSymbol, stackTop);

        if (transitions.find(transitionKey) != transitions.end())
        {
            auto& nextStates = transitions[transitionKey];

            // Apply each possible transition
            for (const auto& nextState : nextStates)
            {
                char newState;
                std::string stackOperation;

                std::tie(newState, stackOperation) = nextState;

                stack.pop(); // Pop the current stack symbol
                for (char stackSymbol : stackOperation)
                {
                    stack.push(stackSymbol); // Push the new stack symbols
                }

                currentState = newState;
            }
        }
        else
        {
            // No valid transition for the current input, stack, and state
            return false;
        }
    }

    // Check if the final state is reached
    return finalStates.find(currentState) != finalStates.end();
}
