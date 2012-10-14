#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Primitive.h"


class Rectangle: public Primitive
{
private:
	Vertex2D upperLeftVertex;
	Vertex2D bottomRightVertex;

public:
	Rectangle();
	Rectangle(Vertex2D upLeftVertex, Vertex2D downRightVertex);
	virtual ~Rectangle();
	
	void setUpLeftX(float x);
	void setUpLeftY(float y);

	void setDownRightX(float x);
	void setDownRightY(float y);

	virtual int addValues(string attr, string val);
	
	void draw();
};


#endif

