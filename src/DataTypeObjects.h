#ifndef _DATATYPEOBJECTS_H_
#define _DATATYPEOBJECTS_H_

typedef struct Vector_t {
	double x, y, z;
} Vector;

typedef struct Planet_t {
	char* name;
	double mass;
	Vector* coords;
	Vector* velocity;
	Vector* tmp_a;
} Planet;

extern const float TimeStep;

//extern const int PLANET_LIMIT = 1000;
extern const float GravConst;

#endif

