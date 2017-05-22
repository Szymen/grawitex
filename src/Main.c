/****************************************************
 *  Main.c
 *  Created on: 25-mar-2017 02:06:28
 *  Implementation of the Class Main
 *  Original author: szym
 ****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "DataParser.h"
#include "DataTypeObjects.h"
#include "Symulator.h"

#define PLANET_LIMIT 1000

int main(int argc, char* argv[]){
	/* -h -s dlugosc kroku  -t czas -i input -o output -g gnuplot  */
	double timeStep, simTime;
	char *inFileName, *outFileName;
	int c, outType;

    int planet_count;
    while((c = getopt (argc, argv, "hs:i:t:o:g")) != -1){
	switch(c){

		case 'h':
		printf("Wypisuje helpa!\n");
		return 0;
		break;
	
		case 's':
			timeStep = atof(optarg);
			printf("s:%g\n", timeStep);
		break;	

		case 'i':
			inFileName = optarg;
		break;

		case 't':
			simTime = atof(optarg);
		break;	

		case 'o':
			outFileName = optarg;
		break;
	
		case 'g':
			outType = 1;	
		break;	
	}	
	}
	printf("Opcje:\n\tin:%s out:%s timeStep:%lf simTime:%lf\n",inFileName, outFileName, timeStep, simTime);

	return 0;

    Planet *Planet_tab;
    Planet_tab = malloc(sizeof(Planet) * PLANET_LIMIT);

    planet_count = ReadPlanetDataCartesian(inFileName,Planet_tab);
   
    Simulate( Planet_tab, planet_count, simTime, timeStep ,outType , outFileName);

    return 0;
}
