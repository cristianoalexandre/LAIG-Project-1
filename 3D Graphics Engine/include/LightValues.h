#ifndef LIGHTVALUES_H
#define	LIGHTVALUES_H

#include <cstring>
#include <iostream>
#include <cstdlib>

#include "SceneValues.h"
#include "Light.h"

typedef map<string, Light*> lsf_lights;

class LightValues : public SceneValues
{
private:
    lsf_lights lights;
    vector <float> ambient_light;
    
public:
    LightValues();
    virtual ~LightValues();
    
    void setAmbientLight(char* attribute, char* value);
    void setLightInitSettings(char* attribute, char *value);
    void setLightPositionSettings(char* attribute, char *value);
    void setLightAmbientComponent(char* attribute, char *value);
    void setLightDiffuseComponent(char* attribute, char *value);
    void setLightSpecularComponent(char* attribute, char *value);
    
    void apply();
    void addValues(char* element, char* attribute, char* value);
};

#endif	/* LIGHTVALUES_H */

