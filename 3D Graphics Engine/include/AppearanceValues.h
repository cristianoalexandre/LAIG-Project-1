#ifndef APPEARANCEVALUES_H
#define APPEARANCEVALUES_H

#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "SceneValues.h"
#include "CGFappearance.h"
#include "Appearance.h"

using namespace std;

typedef map <string,Appearance*> lsf_appearances;

class AppearanceValues : public SceneValues
{
private:
    lsf_appearances appearances;
public:
    AppearanceValues();
    virtual ~AppearanceValues();
    
	Appearance* getAppearance(string id);
    void apply();
    void addValues(char* element, char* attribute, char* value);
	
};

#endif	/* APPEARANCEVALUES_H */

