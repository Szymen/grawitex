/****************************************************
 *  Main.c
 *  Created on: 25-mar-2017 02:06:28
 *  Implementation of the Class Main
 *  Original author: szym
 ****************************************************/

#include <stdio.h>

#include "DataParser.h"
#include "DataTypeObjects.h"
#include "Symulator.h"



int main(int arc, char* argv[]){


    //printf("Hello world!\n");

    Planet *Planet_tab;
    int planet_count;
    planet_count = ReadPlanetDataCartesian("data/all_planets.in",Planet_tab);
/*    int i; 
    for( i = 0; i < 207; i++){
		printf(
			"Planet_tab[%d] %s\t%g %g %g %g %g %g %g\n",
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
    } */
    char* OutFileName = "PlikWyjsciowy.out";
    Simulate( Planet_tab, planet_count ,1 , OutFileName);




    return 0;
}
