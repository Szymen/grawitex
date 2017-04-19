
#ifndef _DATATYPEOBJECTS_H_
#define _DATATYPEOBJECTS_H_


typedef struct Place_t{
double x, y, z;
}Place;

 typedef struct Velocity_t{
double vx, vy, vz;
}Velocity;

typedef struct Planet_t{
char* name;
double mass;
Place* coords;
Velocity* velocity;
}Planet;

extern const float TimeStep;

//extern const int PLANET_LIMIT = 1000;
extern const float GravConst;

#endif

