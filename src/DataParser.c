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

int ReadPlanetDataCartesian(const char* InFileName, Planet* tab){

	char name[BUFF_SIZE];
	int i;
	double x,y,z,vx,vy,vz, mass;
	FILE *f_in;

	f_in = fopen(InFileName,"r");
	/* printf("Poprawnie otwarto plik: %s\n",InFileName); */
	if( tab == NULL){printf("COS Z PAMIECIA! NIE MOGE WCZYTAC!\n"); return -2;}
/*	Planet tmp;
	tmp.coords = malloc(sizeof(Place));
	tmp.name = malloc(sizeof(char) * 40 );
	tmp.velocity = malloc(sizeof(Velocity));*/
	//printf("A\n");
	
	i = 0;
	
	
	while( fgets(name, BUFF_SIZE, f_in) != NULL &&   
		fscanf(
			f_in, "%lf %lf %lf %lf %lf %lf %lf ",
			&mass,
			&x, &y, &z,
			&vx, &vy, &vz) == 7 ) {
		/* firstly reads planets name due to spaces in some. Then reads all remaining data */
	  
		if(i == PLANET_LIMIT){
			printf("ZA DUŻO PLANET!\n");
			return -1;
		}
		//printf("B\n");
		tab[i].name = malloc(sizeof(char) * 40 );
		tab[i].coords = malloc(sizeof(Vector));
		tab[i].velocity = malloc(sizeof(Vector));
		tab[i].tmp_a = malloc(sizeof(Vector));

		tab[i].tmp_a->x = 0;	
		tab[i].tmp_a->y = 0;	
		tab[i].tmp_a->z = 0;	
	
		name[strlen(name)-1]=0; /* deleting newline at the end */
		
		strcpy(tab[i].name,name);
		tab[i].mass = mass;
		tab[i].coords->x=x;
		tab[i].coords->y=y;
		tab[i].coords->z=z;
		tab[i].velocity->x=vx;
		tab[i].velocity->y=vy;
		tab[i].velocity->z=vz;
	
		i++;
		
		//Planet_tab[i++] = tmp;
		
		//printf("Wczytano:[%d] %s predkosc :%d\n",i, tmp.name, tmp.velocity->vx);


		//printf("DataParser:[%d] %s\t%g %g %g %g %g %g %g\n",i,tmp.name, tmp.mass ,tmp.coords->x, tmp.coords->y, tmp.coords->z, tmp.velocity->vx, tmp.velocity->vy, tmp.velocity->vz);
	}



	return i;
}

