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

void printHelp(){

		printf("Usage:\n\t-h prints help\n\t-s simulation time step\n\t-t whole simulation time\n\t-i path to input file\n\t-o path to output file\n\t-g output will be formated in gnuplot usage friendly style\n");
		printf("Example:\"$ ./ grawitex -s 10 -t 100 -i data.in -o data.out\"\n");

}


int main(int argc, char* argv[]){
	/* -h -s dlugosc kroku  -t czas -i input -o output -g gnuplot  */
	double timeStep, simTime;
	char *inFileName, *outFileName;
	int c, outType, obligatoryArgs ;
        int planet_count;
	
	obligatoryArgs = 0;
	timeStep = 0; 
	outType = 0; /* 0 means print in same style after given time; 1 - gnuplot friendly */
    while((c = getopt (argc, argv, "hs:i:t:o:g")) != -1){
	switch(c){

		case 'h':
			printHelp();
			return 0;
		break;
	
		case 's':
			timeStep = atof(optarg);
		break;	

		case 'i':
			inFileName = optarg;
			obligatoryArgs += 1;
		break;

		case 't':
			obligatoryArgs += 1;
			simTime = atof(optarg);
		break;	

		case 'o':
			obligatoryArgs += 1;
			outFileName = optarg;
		break;
	
		case 'g':
			outType = 1;	
		break;	
	}	
	}
	/*printf("Opcje:\n\tin:%s out:%s timeStep:%lf simTime:%lf\n",inFileName, outFileName, timeStep, simTime);*/
	if(obligatoryArgs != 3){
		printf("Not all arguments were given! These are obligatory arguments:\n\t-> path to input file\n\t-> path to ouput file\n\t-> simulation time\n");
		printHelp();
		return 0;
		}
 
	if(timeStep == 0){
		printf("Time step not given. Took 1.0 by default.\n");
		timeStep = 1.0;
		}

	if(timeStep < 0 || simTime < 0 ){
		printf("Time should be greater than 0. Non negative.\n"); 
		return 0;}


    Planet *Planet_tab;
    Planet_tab = malloc(sizeof(Planet) * PLANET_LIMIT);

    planet_count = ReadPlanetDataCartesian(inFileName,Planet_tab);
   
    Simulate( Planet_tab, planet_count, simTime, timeStep ,outType , outFileName);

    return 0;
}
