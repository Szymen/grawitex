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
    /* printf("Poprawnie otwarto plik: %s\n",InFileName); */

    Planet* Planet_tab = malloc(sizeof(Planet) * PLANET_LIMIT);
/*    Planet tmp;
    tmp.coords = malloc(sizeof(Place));
    tmp.name = malloc(sizeof(char) * 40 );
    tmp.velocity = malloc(sizeof(Velocity));*/
    //printf("A\n");
    
    i = 0;
    
    
    while( fgets(name, BUFF_SIZE, f_in) != NULL &&   
      fscanf(f_in,"%f %f %f %f %f %f %f ",&mass, &x, &y, &z, &vx, &vy, &vz) == 7 ){ /* firstly reads planets name due to spaces in some. Then reads all remaining data */
      
        if(i == PLANET_LIMIT){
            printf("ZA DUŻO PLANET!\n");
            return NULL;
        }
        //printf("B\n");
	Planet_tab[i].name = malloc(sizeof(char) * 40 );
	Planet_tab[i].coords = malloc(sizeof(Place));
	Planet_tab[i].velocity = malloc(sizeof(Velocity));
	
	name[strlen(name)-1]=0; /* deleting newline at the end */
	
	strcpy(Planet_tab[i].name,name);
	Planet_tab[i].mass = mass;
	Planet_tab[i].coords->x=x;
        Planet_tab[i].coords->y=y;
        Planet_tab[i].coords->z=z;
        Planet_tab[i].velocity->vx=vx;
        Planet_tab[i].velocity->vy=vy;
        Planet_tab[i].velocity->vz=vz;
	
	i++;
	
	//Planet_tab[i++] = tmp;
	
	//printf("Wczytano:[%d] %s predkosc :%d\n",i, tmp.name, tmp.velocity->vx);


        //printf("DataParser:[%d] %s\t%g %g %g %g %g %g %g\n",i,tmp.name, tmp.mass ,tmp.coords->x, tmp.coords->y, tmp.coords->z, tmp.velocity->vx, tmp.velocity->vy, tmp.velocity->vz);
    }



	return  Planet_tab;
}

