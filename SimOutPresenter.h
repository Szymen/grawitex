#ifndef _SYMOUTPRESENTER_H_
#define _SYMOUTPRESENTER_H_

#include "DataTypeObjects.h"

void WriteByStep(char* OutFileName, Planet* PlanetsTable);
void WriteCartesian(char* OutFileName, Planet* PlanetsTable);
void WriteGnuplot(char* OutFileName, Planet* PlanetsTable);

#endif
