#ifndef TRANSFORMVALUES_H
#define TRANSFORMVALUES_H

#include "SceneValues.h"
#include "CGFobject.h"

#include <map>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

class TransformValues : public SceneValues
{
private:

	map<string, float> scale;
	map<string, float> translate;
	map<string, float> rotate;

public:
	TransformValues();
	
	void addValues(char* elem, char* attr, char* val);
	void addScalingValues(char* attr, char* val);
	void addRotationValues(char* attr, char* val);
	void addTranslationValues(char* attr, char* val);
	void apply();
};







#endif