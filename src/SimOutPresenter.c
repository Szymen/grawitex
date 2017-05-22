/****************************************************
 *  SimOuPresenter.c                                         
 *  Created on: 25-mar-2017 02:06:29                      
 *  Implementation of the Class SimOuPresenter       
 *  Original author: szym                     
 ****************************************************/
#include <stdio.h>

#include "DataTypeObjects.h"
#include "SimOutPresenter.h"

void WriteByStep(char* OutFileName, Planet* PlanetsTable, int planetCount){
	printf("Wypiszmy do: %s\n", OutFileName);	
	FILE * f_out = fopen(OutFileName, "a");
	
	if (f_out == NULL){
    		printf("Error during WriteByStep to file!\n");
    		return ;
	}
	int i;
	double radius = 1.5;
	for(i = 0; i < planetCount; i++){
		fprintf(f_out, "%lf %lf %lf %lf\n",PlanetsTable[i].coords->x,PlanetsTable[i].coords->y, PlanetsTable[i].coords->z, radius );
	}
	fprintf(f_out,"\n");
	fclose(f_out);

}

void WriteCartesian(char* OutFileName, Planet* PlanetsTable, int planetCount){

	
}

void WriteGnuplot(char* OutFileName, Planet* PlanetsTable, int planetCount){
	

} 

