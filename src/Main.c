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

    Planet *Planet_tab;
    Planet_tab = malloc(sizeof(Planet) * PLANET_LIMIT);
    int planet_count;
    planet_count = ReadPlanetDataCartesian("data/small_data.in",Planet_tab);
    }
    char* OutFileName = "PlikWyjsciowy.out";
    Simulate( Planet_tab, planet_count, 2, 1 ,1 , OutFileName);

    return 0;
}
