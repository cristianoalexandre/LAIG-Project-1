#ifndef CAMERAVALUES_H
#define	CAMERAVALUES_H

#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>

#include "SceneValues.h"

using namespace std;

/* ======== VECTOR POSITIONS ========= */
/* Perspective */
const unsigned int P_NEAR = 0;
const unsigned int P_FAR = 1;
const unsigned int ANGLE = 0;

/* From / To */
const unsigned int X = 0;
const unsigned int Y = 0;
const unsigned int Z = 0;

/* Ortho */
const unsigned int O_NEAR = 0;
const unsigned int O_FAR = 1;
const unsigned int LEFT = 2;
const unsigned int RIGHT = 3;
const unsigned int TOP = 4;
const unsigned int BOTTOM = 5;

/* ======= CAMERA TYPE ======== */

const unsigned int ORTHO = 0;
const unsigned int PERSPECTIVE = 1;

class CameraValues : public SceneValues
{
private:
    bool is_initial;
    
    string id;
    unsigned int camera_type;
    vector <double> perspective; /* near, far, angle */
    vector <double> from; /* x, y, z */
    vector <double> to; /* x, y, z */
    vector <double> ortho; /* near, far, left, right, top, bottom*/

public:
    CameraValues();
    virtual ~CameraValues();
    
    void addPerspectiveValues(char* attribute, char* value);
    void addFromValues(char* attribute, char* value);
    void addToValues(char* attribute, char* value);
    void addOrthoValues(char* attribute, char* value);

    void setID(char* newID);
    
    void setPerspectiveNear(double newNear);
    void setPerspectiveFar(double newFar);
    void setPerspectiveAngle(double newAngle);

    void setFromX(double newX);
    void setFromY(double newY);
    void setFromZ(double newZ);
    
    void setToX(double newX);
    void setToY(double newY);
    void setToZ(double newZ);

    void setOrthoNear(double newNear);
    void setOrthoFar(double newFar);
    void setOrthoLeft(double newLeft);
    void setOrthoRight(double newRight);
    void setOrthoTop(double newTop);
    void setOrthoBottom(double newBottom);

    void apply();
    void addValues(char* element, char* attribute, char* value);
};

#endif	/* CAMERAVALUES_H */