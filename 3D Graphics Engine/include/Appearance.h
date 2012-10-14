#ifndef APPEARANCE_H
#define	APPEARANCE_H

#include "CGFappearance.h"
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

#define R 0
#define G 1
#define B 2
#define A 3

class Appearance : public CGFappearance
{
public:
    string id;
    float emissive[4];
    string texture_file;

    void addEmissiveValue(char *attribute, float value);
    void addAmbientValue(char *attribute, float value);
    void addDiffuseValue(char* attribute, float value);
    void addSpecularValue(char* attribute, float value);
    void setShininess(float value);
    void applyValues();
};

#endif	/* APPEARANCE_H */

