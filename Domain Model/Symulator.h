
#ifndef _SYMULATOR_H_
#define _SYMULATOR_H_


#include "SimOuPresenter.h"
#include "Collider.h"

SimOuPresenter *m_SimOuPresenter;
Collider *m_Collider;

SimOutPresenter *m_SimOutPresenter;


void Simulate(Planet* PlanetsTable, int OutType, char* OutFileName);


#endif _SYMULATOR_H_
