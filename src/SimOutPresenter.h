#ifndef _SYMOUTPRESENTER_H_
#define _SYMOUTPRESENTER_H_

#include "DataTypeObjects.h"


void WriteCartesian(char* OutFileName, Planet* PlanetsTable, int planetCount);
void WriteGnuplot(char* OutFileName, Planet* PlanetsTable, int planetCount);

#endif
