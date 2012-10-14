#include "Rectangle.h"

Rectangle::Rectangle(){
}

Rectangle::~Rectangle(){
}

Rectangle::Rectangle(Vertex2D upLeftVertex, Vertex2D downRightVertex){

	this->upperLeftVertex = upLeftVertex;
	this->bottomRightVertex = downRightVertex; 
}


void Rectangle::setUpLeftX(float x){this->upperLeftVertex.x = x;}
void Rectangle::setUpLeftY(float y){this->upperLeftVertex.y = y;}

void Rectangle::setDownRightX(float x){this->bottomRightVertex.x = x;}
void Rectangle::setDownRightY(float y){this->bottomRightVertex.y = y;}


void Rectangle::draw(){

	glRectf(this->upperLeftVertex.x, this->upperLeftVertex.y, this->bottomRightVertex.x, this->bottomRightVertex.y);
}

int Rectangle::addValues(string attr, string val){

	if(attr == "x1"){
		setUpLeftX(atof(val.c_str()));
	}else{
		if(attr == "y1"){
			setUpLeftY(atof(val.c_str()));
		}else{
			if(attr == "x2"){
				setDownRightX(atof(val.c_str()));
			}else{
				if(attr == "y2"){
					setDownRightY(atof(val.c_str()));
					return 1;
				}
			}
		}
	}
	return 0;
}