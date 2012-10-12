#ifndef GLOBALVALUES_H
#define	GLOBALVALUES_H

#include "SceneValues.h"
#include "CGFscene.h"

#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

/* ======== VECTOR POSITIONS ======== */
/* Background */
const unsigned int R = 0;
const unsigned int G = 1;
const unsigned int B = 2;
const unsigned int A = 3;

/* Polygon */
const unsigned int MODE = 0;
const unsigned int SHADING = 1;

/* Culling */
const unsigned int FRONTFACEORDER = 0;
const unsigned int CULLFACE = 1;
const unsigned int ENABLED = 2;

class GlobalValues : public SceneValues
{
private:
    vector <float> background; /* R,G,B,A */
    vector <string> polygon; /* mode, shading */
    vector <string> culling; /* frontfaceorder, cullface, enabled */

public:
    GlobalValues();
    void addBackgroundValues(char* attribute, char* value);
    void addPolygonValues(char* attribute, char* value);
    void addCullingValues(char* attribute, char* value);

    void setBackgroundR(float newR);
    void setBackgroundG(float newG);
    void setBackgroundB(float newB);
    void setBackgroundA(float newA);
    void setPolygonMode(char* new_mode);
    void setPolygonShading(char* new_mode);
    void setCullingFrontFaceOrder(char* new_frontfaceorder);
    void setCullingCullface(char* new_cullface);
    void setCullingEnabled(char* new_enabled);

    void apply();
    void addValues(char* element, char* attribute, char* value);
};

#endif	/* GLOBALVALUES_H */

