/****************************************************
 *  Main.c
 *  Created on: 25-mar-2017 02:06:28
 *  Implementation of the Class Main
 *  Original author: szym
 ****************************************************/

#include <stdio.h>

#include "DataParser.h"
#include "DataTypeObjects.h"




int main(int arc, char* argv[]){


    //printf("Hello world!\n");

    Planet *Planet_tab;
    
    Planet_tab = ReadPlanetDataCartesian("data/all_planets.in");
    
    for(int  i = 0; i < 207; i++){
		printf(
			"Planet_tab[%d] %s\t%g %g %g %g %g %g %g\n",
			i,
			Planet_tab[i].name,
			Planet_tab[i].mass,
			Planet_tab[i].coords->x,
			Planet_tab[i].coords->y,
			Planet_tab[i].coords->z,
			Planet_tab[i].velocity->vx,
			Planet_tab[i].velocity->vy,
			Planet_tab[i].velocity->vz
		);
    }
    //char *in_file = "/home/szym/Pulpit/grawitacja/grawitex/data.in";

    //wczytaj_shit(in_file);





    return 0;
}
