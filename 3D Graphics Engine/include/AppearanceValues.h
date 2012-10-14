#ifndef APPEARANCEVALUES_H
#define APPEARANCEVALUES_H

#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "SceneValues.h"
#include "CGFappearance.h"

using namespace std;

#define R 0
#define G 1
#define B 2
#define A 3

class AppearanceValues : public SceneValues, public CGFappearance
{
private:
    string id;
    float emissive[4];
    string texture_file;
public:
    AppearanceValues();
    virtual ~AppearanceValues();
    
    void addEmissiveValue(char *attribute, float value);
    void addAmbientValue(char *attribute, float value);
    void addDiffuseValue(char* attribute, float value);
    void addSpecularValue(char* attribute, float value);
    
    void apply();
    void addValues(char* element, char* attribute, char* value);
};

#endif	/* APPEARANCEVALUES_H */

