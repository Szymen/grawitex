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
#include "SimOutPresenter.h"


void Simulate(Planet* PlanetsTable, int planetCount, double simLength, double timeStep, int OutType, char* OutFileName){
	int iteration, i, j;
	iteration = 0;
	while(iteration*timeStep < simLength){
		for(i = 0; i<planetCount; i++){
			for(j=0;j<planetCount;j++){
				if(i == j ){continue;}
				calcGrav(PlanetsTable+i, PlanetsTable+j);	
			}
		}
		for(i = 0; i<planetCount; i++){
			actualisePos(&PlanetsTable[i], timeStep);
		}
		/* Presentation control */
		char* OutFileName = "test_out.out";
		WriteByStep( OutFileName,  PlanetsTable, planetCount );
		iteration++;
	}

} 

