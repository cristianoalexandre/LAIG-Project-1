#ifndef TORUS_H
#define TORUS_H

#include "Primitive.h"

class Torus: protected Primitive
{
private:
	float innerRadius;
	float outerRadius;
	int slices;
	int loops;

public:
	Torus();
	Torus(float iRadius, float oRadius, int slcs, int loops);
	virtual ~Torus();

	void draw();
};

#endif