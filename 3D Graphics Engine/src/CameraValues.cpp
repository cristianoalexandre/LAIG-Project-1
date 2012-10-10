#include <map>
#include <GL/gl.h>

#include "CameraValues.h"
#include "CGFcamera.h"

string CameraValues::initial_cam_id = "";

CameraValues::CameraValues()
{


    /* <cameras initial="cam1" >
                <perspective id="cam1" near="0.1" far="0.2" angle="180">
                        <from x="30" y="30" z="30" />
                        <to x="0" y="0" z="0" />
                </perspective>
                <ortho id="cam2" near="0.1" far="0.2" left="20" right="20" top="20" bottom="20" />
        </cameras> */
    is_initial = false;

    id = "cam1";
    camera_type = PERSPECTIVE;
    perspective.push_back(0.1);
    perspective.push_back(0.2);
    perspective.push_back(180);

    from.push_back(30);
    from.push_back(30);
    from.push_back(30);

    to.push_back(0);
    to.push_back(0);
    to.push_back(0);

    ortho.push_back(0.1);
    ortho.push_back(0.2);
    ortho.push_back(20);
    ortho.push_back(20);
    ortho.push_back(20);
    ortho.push_back(20);

}

CameraValues::~CameraValues()
{

}

void CameraValues::addPerspectiveValues(char* attribute, char* value)
{
    if (!strcmp("id", attribute))
        setID(value);
    else
    {
        double valued = atof(value);

        if (!strcmp("near", attribute))
            setPerspectiveNear(valued);
        else if (!strcmp("far", attribute))
            setPerspectiveFar(valued);
        else if (!strcmp("angle", attribute))
            setPerspectiveAngle(valued);
    }
}

void CameraValues::addFromValues(char* attribute, char* value)
{
    double valued = atof(value);

    if (!strcmp("x", attribute))
        setFromX(valued);
    else if (!strcmp("y", attribute))
        setFromY(valued);
    else if (!strcmp("z", attribute))
        setFromZ(valued);
}

void CameraValues::addToValues(char* attribute, char* value)
{
    double valued = atof(value);

    if (!strcmp("x", attribute))
        setToX(valued);
    else if (!strcmp("y", attribute))
        setToY(valued);
    else if (!strcmp("z", attribute))
        setToZ(valued);
}

void CameraValues::addOrthoValues(char* attribute, char* value)
{


    double valued = atof(value);

    if (!strcmp("id", attribute))
    {
        CGFcamera * cam = new CGFcamera();
        cams.insert(pair((string) attribute, cam));
        setID(value);
    }
    else
    {
        if (!strcmp("near", attribute))

        else if (!strcmp("far", attribute))
            
        else if (!strcmp("left", attribute))
            
        else if (!strcmp("right", attribute))
            
        else if (!strcmp("top", attribute))
            
        else if (!strcmp("bottom", attribute))

        }
}

void CameraValues::setID(char* newID)
{
    if (string(newID) == this->initial_cam_id)
        is_initial = true;

    id = string(newID);
}

bool CameraValues::isInitial()
{
    return is_initial;
}

void CameraValues::setInitialCameraID(char* newID)
{
    initial_cam_id = string(newID);
}

void CameraValues::apply()
{

}

void CameraValues::addValues(char* element, char* attribute, char* value)
{
    if (!strcmp("cameras", element))
        setInitialCameraID(value);
    if (!strcmp("perspective", element))
        addPerspectiveValues(attribute, value);
    else if (!strcmp("from", element))
        addFromValues(attribute, value);
    else if (!strcmp("to", element))
        addToValues(attribute, value);
    else if (!strcmp("ortho", element))
        addOrthoValues(attribute, value);
}