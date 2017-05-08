#ifndef _MATHFUNCTIONS_H_
#define _MATHFUNCTIONS_H_

#include "Symulator.h"
#include "Collider.h"
#include "DataTypeObjects.h"

void actualisePos(Planet* Planet, double dt);
void calcGrav(Planet* A, Planet* B);

#endif 
