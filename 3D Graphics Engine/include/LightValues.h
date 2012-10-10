#ifndef LIGHTVALUES_H
#define	LIGHTVALUES_H

#include "SceneValues.h"
#include "CGFlight.h"

class LightValues : public SceneValues
{
private:
    
    vector <CGFlight*> lights;
public:
    LightValues();
    virtual ~LightValues();
    void apply();
    void addValues(char* element, char* attribute, char* value);
};

#endif	/* LIGHTVALUES_H */

