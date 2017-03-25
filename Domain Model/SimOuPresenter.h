
#ifndef _SYMOUTPRESENTER_H_
#define _SYMOUTPRESENTER_H_


#include "DataTypeObjects.h"

DataTypeObjects *m_DataTypeObjects;


void WriteByStep(char* OutFileName, Planets* PlanetsTable);
void WriteCartesian(char* OutFileName, Planet* PlanetsTable);
void WriteGnuplot(char* OutFileName, Planets* PlanetsTable);


DataTypeObjects *m_DataTypeObjects;


void WriteByStep(char* OutFileName, Planets* PlanetsTable);
void WriteCartesian(char* OutFileName, Planet* PlanetsTable);
void WriteGnuplot(char* OutFileName, Planets* PlanetsTable);



#endif
