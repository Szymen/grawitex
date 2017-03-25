
#ifndef _MATHFUNCTIONS_H_
#define _MATHFUNCTIONS_H_


#include "Symulator.h"
#include "Collider.h"

Symulator *m_Symulator;
Collider *m_Collider;


void CalcNewPosition(Planet* Planet);
void EvalVelocity(Planet* A, Planet* B);




#endif 
