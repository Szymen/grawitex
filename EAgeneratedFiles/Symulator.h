/****************************************************
 *  Symulator.h                                         
 *  Created on: 25-mar-2017 02:06:29                      
 *  Implementation of the Class Symulator       
 *  Original author: szym                     
 ****************************************************/

#if !defined(EA_689FE331_AB08_4be0_8EDE_6BEB08895961__INCLUDED_)
#define EA_689FE331_AB08_4be0_8EDE_6BEB08895961__INCLUDED_


#ifdef __cplusplus
extern "C" {
#endif

#include "SimOuPresenter.h"
#include "Collider.h"

SimOuPresenter *m_SimOuPresenter;
Collider *m_Collider;
SimOutPresenter *m_SimOutPresenter;


void Simulate(Planet* PlanetsTable, int OutType, char* OutFileName);


#ifdef __cplusplus
}
#endif


#endif /*!defined(EA_689FE331_AB08_4be0_8EDE_6BEB08895961__INCLUDED_)*/
 