#include "Cylinder.h"


Cylinder::Cylinder(){
}

Cylinder::~Cylinder(){
}

Cylinder::Cylinder(float bRadius, float tRadius, float h, int slcs, int stcks){
	this->baseRadius = bRadius;
	this->topRadius = tRadius;
	this->height = h;
	this->slices = slcs;
	this->stacks = stcks;
}


void Cylinder::draw(){


	gluCylinder(gluNewQuadric(), this->baseRadius, this->topRadius, this->height, this->slices, this->stacks);



}