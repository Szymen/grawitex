#ifndef _SYMOUTPRESENTER_H_
#define _SYMOUTPRESENTER_H_

#include "DataTypeObjects.h"


void WriteByStep(char* OutFileName, Planet* PlanetsTable, int planetCount);
void WriteCartesian(char* OutFileName, Planet* PlanetsTable, int planetCount);
void WriteGnuplot(char* OutFileName, Planet* PlanetsTable, int planetCount);

#endif
