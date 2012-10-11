#ifndef TRANSFORMVALUES_H
#define TRANSFORMVALUES_H

#include "SceneValues.h"

#include <map>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

class TransformValues : public SceneValues
{
private:

	map<string, double> scale;
	map<string, double> translate;
	map<string, double> rotate;

public:
	TransformValues();
	
	void addValues(char* elem, char* attr, char* val);
	void addScalingValues(char* attr, char* val);
	void addRotationValues(char* attr, char* val);
	void addTranslationValues(char* attr, char* val);
	void apply();
};







#endif