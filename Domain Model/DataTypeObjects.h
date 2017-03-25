
#ifndef _DATATYPEOBJECTS_H_
#define _DATATYPEOBJECTS_H_

#include "DataParser.h"
#include "Main.h"
#include "MathFunctions.h"


typedef struct Place{
double x, y, z;
}

 typedef struct Velocity{
double vx, vy, vz;
}
typedef struct Planet{
char* Name;
double mass;
place* coords;
velocity* velocity;
}


float GravConst;
float TimeStep;
DataParser *m_DataParser;
Main *m_Main;
MathFunctions *m_MathFunctions;




#endif _DATATYPEOBJECTS_H_

