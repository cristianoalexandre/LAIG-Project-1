#ifndef LIGHT_H
#define	LIGHT_H

#include <vector>
#include <iostream>

#include "CGFlight.h"

using namespace std;

#define X 0
#define Y 1
#define Z 2

#define R 0
#define G 1
#define B 2
#define A 3

class Light
{
protected:
    unsigned int static light_number;
    
    string id;
    CGFlight * light;
    vector <float> location;
    vector <float> ambient;
    vector <float> diffuse;
    vector <float> specular;
    
public:
    Light();
    Light(char* id);
    virtual ~Light() {};
    void setLocationX(float newX);
    void setLocationY(float newY);
    void setLocationZ(float newZ);
    
    void setAmbientR(float newR);
    void setAmbientG(float newG);
    void setAmbientB(float newB);
    void setAmbientA(float newA);
    
    void setDiffuseR(float newR);
    void setDiffuseG(float newG);
    void setDiffuseB(float newB);
    void setDiffuseA(float newA);
    
    void setSpecularR(float newR);
    void setSpecularG(float newG);
    void setSpecularB(float newB);
    void setSpecularA(float newA);
    
    void enable();
    void disable();
    
    static void addLightNumber();
    void draw();
    void applyValues();
    
    string getID() {return id;};
};

#endif	/* LIGHT_H */

