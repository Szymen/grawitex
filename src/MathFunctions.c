/****************************************************
 *  MathFunctions.c                                         
 *  Created on: 25-mar-2017 02:06:28                      
 *  Implementation of the Class MathFunctions       
 *  Original author: szym                     
 ****************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "MathFunctions.h"

void actualisePos(Planet* Planet, double dt){

	Planet->coords->x += Planet->velocity->x *dt  + (Planet->tmp_a->x *dt*dt)/2;
	Planet->coords->y += Planet->velocity->y *dt  + (Planet->tmp_a->y *dt*dt)/2;
	Planet->coords->z += Planet->velocity->z *dt  + (Planet->tmp_a->z *dt*dt)/2;


	Planet->velocity->x += Planet->tmp_a->x *dt;
	Planet->velocity->y += Planet->tmp_a->y *dt;
	Planet->velocity->z += Planet->tmp_a->z *dt;

	Planet->tmp_a->x = 0;
	Planet->tmp_a->y = 0;
	Planet->tmp_a->z = 0;
}

void calcGrav(Planet* A, Planet* B){
	double  G = 6.67408e-11;
	double	dx = fabs(A->coords->x - B->coords->x); 
	double	dy = fabs(A->coords->y - B->coords->y);
	double	dz = fabs(A->coords->z - B->coords->z);
	
	A->tmp_a->x += G * (B->mass / (dx*dx));
	A->tmp_a->y += G * (B->mass / (dy*dy));
	A->tmp_a->z += G * (B->mass / (dz*dz));

} 

