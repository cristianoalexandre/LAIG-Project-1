#include <map>

#include "CameraValues.h"
#include "CGFcamera.h"
#include "Camera.h"

string CameraValues::initial_cam_id = "";

CameraValues::CameraValues()
{

}

CameraValues::~CameraValues()
{

}

void CameraValues::addPerspectiveValues(char* attribute, char* value)
{
    if (!strcmp("id", attribute))
    {
        PerspectiveCamera * cam = new PerspectiveCamera();
        persp_cams.insert(pair <string, PerspectiveCamera*>((string) value, cam));
        persp_cams.rbegin()->second->id = (string) value;
    }
    else
    {
        double valued = atof(value);


        if (!strcmp("near", attribute))
            persp_cams.rbegin()->second->perspective[NEAR] = valued;
        else if (!strcmp("far", attribute))
            persp_cams.rbegin()->second->perspective[FAR] = valued;
        else if (!strcmp("angle", attribute))
            persp_cams.rbegin()->second->perspective[ANGLE] = valued;
        else
        {
            cerr << "unknown attribute - " << attribute;
            exit(1);
        }
    }
}

void CameraValues::addFromValues(char* attribute, char* value)
{
    double valued = atof(value);

    if (!strcmp("x", attribute))
        persp_cams.rbegin()->second->from[X] = valued;
    else if (!strcmp("y", attribute))
        persp_cams.rbegin()->second->from[Y] = valued;
    else if (!strcmp("z", attribute))
        persp_cams.rbegin()->second->from[Z] = valued;
    else
    {
        cerr << "unknown attribute - " << attribute;
        exit(1);
    }
}

void CameraValues::addToValues(char* attribute, char* value)
{
    double valued = atof(value);

    if (!strcmp("x", attribute))
        persp_cams.rbegin()->second->to[X] = valued;
    else if (!strcmp("y", attribute))
        persp_cams.rbegin()->second->to[Y] = valued;
    else if (!strcmp("z", attribute))
        persp_cams.rbegin()->second->to[Z] = valued;
    else
    {
        cerr << "unknown attribute - " << attribute;
        exit(1);
    }
}

void CameraValues::addOrthoValues(char* attribute, char* value)
{
    double valued = atof(value);

    if (!strcmp("id", attribute))
    {
        OrthoCamera * cam = new OrthoCamera();
        ortho_cams.insert(pair <string, OrthoCamera*>((string) value, cam));
    }
    else
    {
        if (!strcmp("near", attribute))
            ortho_cams.rbegin()->second->ortho[NEAR] = valued;
        else if (!strcmp("far", attribute))
            ortho_cams.rbegin()->second->ortho[FAR] = valued;
        else if (!strcmp("left", attribute))
            ortho_cams.rbegin()->second->ortho[LEFT] = valued;
        else if (!strcmp("right", attribute))
            ortho_cams.rbegin()->second->ortho[RIGHT] = valued;
        else if (!strcmp("top", attribute))
            ortho_cams.rbegin()->second->ortho[TOP] = valued;
        else if (!strcmp("bottom", attribute))
            ortho_cams.rbegin()->second->ortho[BOTTOM] = valued;
        else
        {
            cerr << "unknown attribute - " << attribute;
            exit(1);
        }
    }
}

void CameraValues::setInitialCameraID(char* newID)
{
    initial_cam_id = string(newID);
}

void CameraValues::apply()
{
    cout << "Camara inicial: " << initial_cam_id << endl;

    persp_cams.find(initial_cam_id)->second->apply();
}

void CameraValues::addValues(char* element, char* attribute, char* value)
{
    if (!strcmp("cameras", element))
    {
        initial_cam_id = (string) value;
    }
    else if (!strcmp("perspective", element))
        addPerspectiveValues(attribute, value);
    else if (!strcmp("from", element))
        addFromValues(attribute, value);
    else if (!strcmp("to", element))
        addToValues(attribute, value);
    else if (!strcmp("ortho", element))
        addOrthoValues(attribute, value);
    else
    {
        cerr << "unknown element - " << element;
        exit(1);
    }
}