#include "Sphere.h"


Sphere::Sphere(){
}

Sphere::~Sphere(){
}

Sphere::Sphere(float rad, int slcs, int stcks){

	this->radius = rad;
	this->slices = slcs;
	this->stacks = stcks;
}


void Sphere::draw(){

	gluSphere(gluNewQuadric(), this->radius, this->slices, this->stacks);

}