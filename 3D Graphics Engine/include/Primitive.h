#ifndef PRIMITIVE_H
#define	PRIMITIVE_H

#include "CGFobject.h"

#include <string>

using namespace std;


typedef struct Vertex2D{

	float x;
	float y;
};


typedef struct Vertex3D{

	float x;
	float y;
	float z;
};



class Primitive : public CGFobject
{
private:
	string id;
protected:
    virtual void draw();
};

#endif	/* FIGURE_H */

