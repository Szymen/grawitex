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


    printf("Hello world!\n");

    Planet *Planet_tab;
    Planet_tab = ReadPlanetDataCartesian("/home/szym/Pulpit/grawitacja/grawitex/data.in");
    for(int  i = 0; i < 10; i++){
		printf("%s \n",Planet_tab[i].name);
	}
    //char *in_file = "/home/szym/Pulpit/grawitacja/grawitex/data.in";

    //wczytaj_shit(in_file);





    return 0;
}
