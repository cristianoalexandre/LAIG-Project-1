#include "Torus.h"


Torus::Torus(){

}

Torus::~Torus(){
}

Torus::Torus(float iRadius, float oRadius, int slcs, int loops){

	this->innerRadius = iRadius;
	this->outerRadius = oRadius;
	this->slices = slcs;
	this->loops = loops;

}

void Torus::draw(){

	glutSolidTorus(this->innerRadius, this->outerRadius, this->slices, this->loops);

}
