#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF_SIZE 40//1024

void wczytaj_shit(char *in){

    char *name[BUFF_SIZE];
    float x,y,z,vx,vy,vz, mass;
    FILE *f_in;
    f_in = fopen(in,"r");
    printf("Prooba!\n");
//    fscanf(f_in,"%s %f %f %f %f %f %f %f ", name, &mass, &x, &y, &z, &vx, &vy, &vz);
//    printf("Wczytał ja planete: %s\t%g %g %g %g %g %g %g\n",name, mass ,x, y, z, vx, vy, vz);


    while( fscanf(f_in,"%s %f %f %f %f %f %f %f ", name, &mass, &x, &y, &z, &vx, &vy, &vz) == 8  ){
        printf("Wczytał ja planete: %s\t%g %g %g %g %g %g %g\n",name, mass ,x, y, z, vx, vy, vz);
    }


}



int main()
{
    printf("Hello world!\n");

    char *in_file = "/home/szym/Pulpit/grawitacja/grawitex/data.in";

    wczytaj_shit(in_file);



    return 0;
}
