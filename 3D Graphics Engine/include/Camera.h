#ifndef CAMERA_H
#define	CAMERA_H

#include <string>
#include <iostream>

#include "CGFcamera.h"
#include "CGFapplication.h"

#define X 0
#define Y 1
#define Z 2

#define NEAR 0
#define FAR 1
#define ANGLE 2

#define LEFT 2
#define RIGHT 3
#define TOP 4
#define BOTTOM 5

using namespace std;

class Camera : public CGFcamera
{
public:
    string id;
    
    Camera();
    virtual ~Camera();
    virtual void apply() = 0;
};

class PerspectiveCamera : public Camera
{    
public:
    float perspective[3];
    float from[3];
    float to[3];
    
    PerspectiveCamera();
    virtual ~PerspectiveCamera();
    void updateProjectionMatrix(int width, int height);
    void apply();
};

class OrthoCamera : public Camera
{
public:
    float ortho[6];
    
    OrthoCamera();
    virtual ~OrthoCamera();
    void apply();
};

#endif	/* CAMERA_H */

