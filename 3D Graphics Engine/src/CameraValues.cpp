#include <map>

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

}

CameraValues::~CameraValues()
{

}

void CameraValues::addPerspectiveValues(char* attribute, char* value)
{
    if (!strcmp("id", attribute))
    {
        CGFcamera * cam = new CGFcamera();
        cams.insert(pair <string, CGFcamera*>((string) attribute, cam));
    }
    else
    {
        double valued = atof(value);

        /*
        if (!strcmp("near", attribute))
            
        else if (!strcmp("far", attribute))
            
        else if (!strcmp("angle", attribute))
         */

    }
}

void CameraValues::addFromValues(char* attribute, char* value)
{
    double valued = atof(value);

    /*
    if (!strcmp("x", attribute))
        
    else if (!strcmp("y", attribute))
       
    else if (!strcmp("z", attribute))
     */
}

void CameraValues::addToValues(char* attribute, char* value)
{
    double valued = atof(value);

    /*    if (!strcmp("x", attribute))
        
        else if (!strcmp("y", attribute))
       
        else if (!strcmp("z", attribute))
     */
}

void CameraValues::addOrthoValues(char* attribute, char* value)
{
    double valued = atof(value);

    if (!strcmp("id", attribute))
    {
        CGFcamera * cam = new CGFcamera();
        cams.insert(pair <string, CGFcamera*>((string) attribute, cam));
    }
    else
    {
        /*if (!strcmp("near", attribute))

        else if (!strcmp("far", attribute))
            
        else if (!strcmp("left", attribute))
            
        else if (!strcmp("right", attribute))
            
        else if (!strcmp("top", attribute))
            
        else if (!strcmp("bottom", attribute))
         */
    }
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
    /*
    if (!strcmp("cameras", element))
        
    if (!strcmp("perspective", element))
        
    else if (!strcmp("from", element))
        
    else if (!strcmp("to", element))
        
    else if (!strcmp("ortho", element))
     */
}