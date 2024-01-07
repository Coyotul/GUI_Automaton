// LambdaAFN.h
#pragma once

#include "AFN.h"

class LambdaAFN : public AFN {
public:
    void addLambdaTransition(char fromState, char toState);
    
};
