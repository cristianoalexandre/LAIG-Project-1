#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Primitive.h"

class Triangle: public Primitive
{
private:
	Vertex3D left;
	Vertex3D right;
	Vertex3D top;
public:
	Triangle();
	Triangle(Vertex3D left, Vertex3D right, Vertex3D top);
	virtual ~Triangle();

	void draw();
};

#endif