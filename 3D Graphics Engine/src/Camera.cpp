#include <GL/glew.h>

#include "Camera.h"
#include "CGFappearance.h"

Camera::Camera()
{
    
}

Camera::~Camera()
{
    
}

PerspectiveCamera::PerspectiveCamera()
{
    
}

PerspectiveCamera::~PerspectiveCamera()
{
    
}

OrthoCamera::OrthoCamera()
{
    
}

OrthoCamera::~OrthoCamera()
{
    
}

void PerspectiveCamera::apply()
{
    cout << "applying camera at X:" << perspective[X] << " Y:" << perspective[Y] << " Z:" << perspective[Z];
    cout << "applying camera from X:" << from[X] << " Y:" << from[Y] << " Z:" << from[Z];
    cout << "applying camera from X:" << to[X] << " Y:" << to[Y] << " Z:" << to[Z];
    updateProjectionMatrix(CGFapplication::vph, CGFapplication::vpw);
}

void OrthoCamera::apply()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glOrtho(ortho[LEFT], ortho[RIGHT], ortho[BOTTOM], ortho[TOP], ortho[NEAR], ortho[FAR]);
}

void PerspectiveCamera::updateProjectionMatrix(int width, int height)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    gluPerspective(perspective[ANGLE], (float)width/(float)height, perspective[NEAR], perspective[FAR]);
    gluLookAt(from[X],from[Y],from[Z],to[X],to[Y],to[Z],0,1,0);
}