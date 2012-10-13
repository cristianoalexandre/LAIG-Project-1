#ifndef TRANSFORMVALUES_H
#define TRANSFORMVALUES_H

#include "SceneValues.h"
#include "CGFobject.h"

#include <map>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>

using namespace std;



class TransformValues : public SceneValues
{
private:
	float scale[3];
	float translate[3];
	float rotate[4];
	
	vector< pair<string, float*> > order;

public:
	TransformValues();
	
	void addValues(char* elem, char* attr, char* val);
	void addScalingValues(char* attr, char* val);
	void addRotationValues(char* attr, char* val);
	void addTranslationValues(char* attr, char* val);
	void apply();
};







#endif