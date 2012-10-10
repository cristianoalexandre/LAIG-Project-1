#include "TransformValues.h"



TransformValues::TransformValues(){

}

void TransformValues::addValues(char* elem, char* attr, char* val){

	string tmp = string(elem);
	if(tmp == "scale"){
		addScalingValues(attr, val);
	}else{
		if(tmp == "rotate"){
			addRotationValues(attr,val);
		}else{
			if(tmp == "translate"){
				addTranslationValues(attr, val);
			}
		}
	}

}

void TransformValues::addScalingValues(char* attr, char* val){

	string key = string(attr);
	double value = atof(val);
	pair<string,double> pair(key,value);

	this->scale.insert(pair);
}

void TransformValues::addRotationValues(char* attr, char* val){

	string key = string(attr);
	double value = atof(val);
	pair<string,double> pair(key,value);

	this->rotate.insert(pair);
}

void TransformValues::addTranslationValues(char* attr, char* val){

	string key = string(attr);
	double value = atof(val);
	pair<string,double> pair(key,value);

	this->translate.insert(pair);
}

void TransformValues::apply(){
}