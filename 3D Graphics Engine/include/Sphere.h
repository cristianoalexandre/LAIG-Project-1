#ifndef SPHERE_H
#define SPHERE_H

#include "Primitive.h"

class Sphere: protected Primitive
{
private:
	float radius;
	int slices;
	int stacks;

public:
	Sphere();
	Sphere(float radius, int slcs, int stcks);
	virtual ~Sphere();

	void draw();
};

#endif