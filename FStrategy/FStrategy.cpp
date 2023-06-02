// FStrategy.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "FStrategy.h"


void FStrategy::Deflect(float& bulletHeading) {
    bulletHeading += 2;
}
void FStrategy::Destroy() {
    delete this;
}


extern "C" __declspec(dllexport) IDeflectionStrategy * CreateStrategy() {
    return new FStrategy();
}