// APD.h
#pragma once

#include <stack>
#include "AFN.h" // Poți să incluzi și alte dependențe

class APD : public AFN {
private:
    std::stack<char> stack;

public:
    void pushStack(char symbol);
    void popStack();
    char getTopOfStack() const;
    
};
