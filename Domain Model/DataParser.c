/****************************************************
 *  DataParser.c
 *  Created on: 25-mar-2017 02:06:28
 *  Implementation of the Class DataParser
 *  Original author: szym
 ****************************************************/
#include "DataParser.h"
#include "DataTypeObjects.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFF_SIZE 40 //1024
#define PLANET_LIMIT 1000

Planet* ReadPlanetDataCartesian(const char* InFileName)
{

    char name[BUFF_SIZE];
    int i;
    float x,y,z,vx,vy,vz, mass;
    FILE *f_in;

    f_in = fopen(InFileName,"r");


    Planet* Planet_tab = malloc(sizeof(Planet) * PLANET_LIMIT);
    Planet tmp;
    i = 0;
    while( fscanf(f_in,"%s %f %f %f %f %f %f %f ", name, &mass, &x, &y, &z, &vx, &vy, &vz) == 8  ){
        if(i == PLANET_LIMIT){
            printf("ZA DUŻO PLANET!\n");
            return NULL;
        }
        tmp.name=name;
        tmp.mass=mass;
        tmp.velocity->vx=vx;
        tmp.velocity->vy=vy;
        tmp.velocity->vz=vz;
        tmp.coords->x=x;
        tmp.coords->y=y;
        tmp.coords->z=z;
        //Planet_tab[i++] = tmp;

        printf("DataParser: %s\t%g %g %g %g %g %g %g\n",tmp.name, tmp.mass ,tmp.coords->x, tmp.coords->y, tmp.coords->z, tmp.velocity->vx, tmp.velocity->vy, tmp.velocity->vz);
    }



	return  Planet_tab;
}

