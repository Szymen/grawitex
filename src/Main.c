/****************************************************
 *  Main.c
 *  Created on: 25-mar-2017 02:06:28
 *  Implementation of the Class Main
 *  Original author: szym
 ****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "DataParser.h"
#include "DataTypeObjects.h"
#include "Symulator.h"

#define PLANET_LIMIT 1000

int main(int arc, char* argv[]){


    //printf("Hello world!\n");

    Planet *Planet_tab;
    Planet_tab = malloc(sizeof(Planet) * PLANET_LIMIT);
    int planet_count;
//    printf("Czytamy!\n");
    planet_count = ReadPlanetDataCartesian("data/small_data.in",Planet_tab);
 /*   int i; 

    for( i = 0; i < 3; i++){
		printf("Planet_tab[%d] %s\t masa:%g x:%g y:%g z:%g vx:%g vy:%g vz:%g\n",
			i,
			Planet_tab[i].name,
			Planet_tab[i].mass,
			Planet_tab[i].coords->x,
			Planet_tab[i].coords->y,
			Planet_tab[i].coords->z,
			Planet_tab[i].velocity->x,
			Planet_tab[i].velocity->y,
			Planet_tab[i].velocity->z
		);
    }*/
    char* OutFileName = "PlikWyjsciowy.out";
    //printf("Test: %s\n", Planet_tab[3].name);
    Simulate( Planet_tab, planet_count, 2, 1 ,1 , OutFileName);




    return 0;
}
