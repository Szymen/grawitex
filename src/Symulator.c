/****************************************************
 *  Symulator.c                                         
 *  Created on: 25-mar-2017 02:06:29                      
 *  Implementation of the Class Symulator       
 *  Original author: szym                     
 ****************************************************/
#include <stdio.h>
#include <string.h>

#include "Symulator.h"
#include "MathFunctions.h"

void Simulate(Planet* PlanetsTable, int planetCount, double simLength, double timeStep, int OutType, char* OutFileName){
	printf("Zaczynamy symulacje typ %d, wypisujemy do %s.\n", OutType, OutFileName);
	printf("Planet jest: %d\n", planetCount);
	printf("Dlugosc symulacji %lf z krokiem %lf\n", simLength, timeStep);
	int iteration, i, j;
	iteration = 0;
	//printf("Dupa\n");
	while(iteration*timeStep < simLength){

		//printf("A\n");
		for(i = 0; i<planetCount; i++){
			//printf("B\n");
			for(j=0;j<planetCount;j++){
				//printf("C\n");
				if(i == j ){continue;}
				//printf("Liczymy dla %d i %d \n",i,j); //, &PlanetsTable[i].name, PlanetsTable[j].name);
				calcGrav(PlanetsTable+i, PlanetsTable+j);	
			}
		}
		for(i = 0; i<planetCount; i++){
			actualisePos(&PlanetsTable[i], timeStep);
		}
		iteration++;
	}

} 

