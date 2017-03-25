CC=gcc
CFLAGS=-I.

grawitex: DataParser.o 
	$(CC) Main.c DataParser.o -I. -o grawitex

DataParser.o:
	$(CC) -o DataParser.o -c DataParser.c
  
