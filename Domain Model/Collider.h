
#ifndef _COLLIDER_H_
#define _COLLIDER_H_


void Bounce(Planet* PlanetA, Planet* PlanetB);
void CollideAndFracture(Planet* PlanetsTable, int PlanetAindex, int PlanetBindex);
void GlueUp(Planet* PlanetTable, int PlanetAindex, int PlanetBindex);


#endif _COLLIDER_H_
