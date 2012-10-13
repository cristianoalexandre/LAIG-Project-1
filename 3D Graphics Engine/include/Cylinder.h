#ifndef CYLINDER_H
#define CYLINDER_H

#include "Primitive.h"

class Cylinder: public Primitive
{
private:
	float baseRadius;
	float topRadius;
	float height;
	int slices;
	int stacks;
public:
	Cylinder();
	Cylinder(float bRadius, float tRadius, float h, int slcs, int stcks);
	virtual ~Cylinder();

	void draw();
};

#endif