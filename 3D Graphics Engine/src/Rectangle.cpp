#include "Rectangle.h"

Rectangle::Rectangle(){
}

Rectangle::~Rectangle(){
}

Rectangle::Rectangle(Vertex2D upLeftVertex, Vertex2D downRightVertex){

	this->upperLeftVertex = upLeftVertex;
	this->bottomRightVertex = downRightVertex; 
}

void Rectangle::draw(){

	glRectf(this->upperLeftVertex.x, this->upperLeftVertex.y, this->bottomRightVertex.x, this->bottomRightVertex.y);

}