#ifndef _SYMULATOR_H_
#define _SYMULATOR_H_

#include "SimOutPresenter.h"
#include "Collider.h"


void Simulate(Planet* PlanetsTable, int planetCount, double simLength, double timeStep  ,int OutType, char* OutFileName);

#endif 
