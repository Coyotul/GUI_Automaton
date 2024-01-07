// LambdaAFN.cpp
#include "LambdaAFN.h"

void LambdaAFN::addLambdaTransition(char fromState, char toState) {
    transitions[{fromState, '$'}].insert(toState);
}

