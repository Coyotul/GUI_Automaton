// APD.cpp
#include "APD.h"

void APD::pushStack(char symbol) {
    stack.push(symbol);
}

void APD::popStack() {
    if (!stack.empty()) {
        stack.pop();
    }
}

char APD::getTopOfStack() const {
    return stack.empty() ? '\0' : stack.top();
}

