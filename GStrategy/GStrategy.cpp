// FStrategy.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "GStrategy.h"


void GStrategy::Deflect(float& bulletHeading) {
    bulletHeading *= -1;
}
void GStrategy::Destroy() {
    delete this;
}


extern "C" __declspec(dllexport) IDeflectionStrategy * CreateStrategy() {
    return new GStrategy();
}