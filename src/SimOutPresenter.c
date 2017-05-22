/****************************************************
 *  SimOuPresenter.c                                         
 *  Created on: 25-mar-2017 02:06:29                      
 *  Implementation of the Class SimOuPresenter       
 *  Original author: szym                     
 ****************************************************/
#include <stdio.h>

#include "DataTypeObjects.h"
#include "SimOutPresenter.h"

void WriteCartesian(char* OutFileName, Planet* PlanetsTable, int planetCount){

//	printf("Wypiszmy do: %s\n", OutFileName);	
	FILE * f_out = fopen(OutFileName, "w");
	
	if (f_out == NULL){
    		printf("Error during writting results to file!\n");
    		return ;
	}
	int i;
	for(i = 0; i < planetCount; i++){
		fprintf(f_out, "%s\n%g\n%g\n%g\n%g\n%g\n%g\n%g\n\n",PlanetsTable[i].name,PlanetsTable[i].mass, PlanetsTable[i].coords->x,PlanetsTable[i].coords->y, PlanetsTable[i].coords->z, PlanetsTable[i].velocity->x, PlanetsTable[i].velocity->y, PlanetsTable[i].velocity->z );
	}
	fclose(f_out);
	
}

void WriteGnuplot(char* OutFileName, Planet* PlanetsTable, int planetCount){
	
//	printf("Wypiszmy do: %s\n", OutFileName);	
	FILE * f_out = fopen(OutFileName, "w");
	
	if (f_out == NULL){
    		printf("Error during writting gnuplot-friendly to file!\n");
    		return ;
	}
	int i;
	double earth_mass = 5.9e+24; 
	for(i = 0; i < planetCount; i++){
		fprintf(f_out, "%g %g %g %g\n",PlanetsTable[i].coords->x,PlanetsTable[i].coords->y, PlanetsTable[i].coords->z, PlanetsTable[i].mass/earth_mass );
	}
	fclose(f_out);

} 

