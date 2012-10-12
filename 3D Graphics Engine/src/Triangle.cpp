#include "Triangle.h"


Triangle::Triangle(){
}

Triangle::~Triangle(){
}


Triangle::Triangle(Vertex3D left, Vertex3D right, Vertex3D top){

	this->left = left;
	this->right = right;
	this->top = top;
}

void Triangle::draw(){

	glBegin(GL_TRIANGLES);
		glVertex3f(this->left.x, this->left.y, this->left.z);
		glVertex3f(this->right.x, this->right.y, this->right.z);
		glVertex3f(this->top.x, this->top.y, this->top.z);
	glEnd();
}

