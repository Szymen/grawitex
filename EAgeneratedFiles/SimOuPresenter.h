/****************************************************
 *  SimOuPresenter.h                                         
 *  Created on: 25-mar-2017 02:06:28                      
 *  Implementation of the Class SimOuPresenter       
 *  Original author: szym                     
 ****************************************************/

#if !defined(EA_6DD63914_FBEF_4f4e_8640_24A1972869A2__INCLUDED_)
#define EA_6DD63914_FBEF_4f4e_8640_24A1972869A2__INCLUDED_


#ifdef __cplusplus
extern "C" {
#endif

#include "DataTypeObjects.h"

DataTypeObjects *m_DataTypeObjects;


void WriteByStep(char* OutFileName, Planets* PlanetsTable);
void WriteCartesian(char* OutFileName, Planet* PlanetsTable);
void WriteGnuplot(char* OutFileName, Planets* PlanetsTable);


#ifdef __cplusplus
}
#endif


#endif /*!defined(EA_6DD63914_FBEF_4f4e_8640_24A1972869A2__INCLUDED_)*/
 

DataTypeObjects *m_DataTypeObjects;


void WriteByStep(char* OutFileName, Planets* PlanetsTable);
void WriteCartesian(char* OutFileName, Planet* PlanetsTable);
void WriteGnuplot(char* OutFileName, Planets* PlanetsTable);