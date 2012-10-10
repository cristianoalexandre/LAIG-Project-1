#include "CameraValues.h"

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
        setID(value);
    else
    {
        if (!strcmp("near", attribute))
            setOrthoNear(valued);
        else if (!strcmp("far", attribute))
            setOrthoFar(valued);
        else if (!strcmp("left", attribute))
            setOrthoLeft(valued);
        else if (!strcmp("right", attribute))
            setOrthoRight(valued);
        else if (!strcmp("near", attribute))
            setOrthoNear(valued);
        else if (!strcmp("near", attribute))
            setOrthoNear(valued);
    }
}

void CameraValues::setID(char* newID)
{
    id = string(newID);
}

void CameraValues::setPerspectiveNear(double newNear)
{
    perspective[P_NEAR] = newNear;
}

void CameraValues::setPerspectiveFar(double newFar)
{
    perspective[P_FAR] = newFar;
}

void CameraValues::setPerspectiveAngle(double newAngle)
{
    perspective[ANGLE] = newAngle;
}

void CameraValues::setFromX(double newX)
{
    from[X] = newX;
}

void CameraValues::setFromY(double newY)
{
    from[Y] = newY;
}

void CameraValues::setFromZ(double newZ)
{
    from[Z] = newZ;
}

void CameraValues::setToX(double newX)
{
    to[X] = newX;
}

void CameraValues::setToY(double newY)
{
    to[Y] = newY;
}

void CameraValues::setToZ(double newZ)
{
    to[Z] = newZ;
}

void CameraValues::setOrthoNear(double newNear)
{
    ortho[O_NEAR] = newNear;
}

void CameraValues::setOrthoFar(double newFar)
{
    ortho[O_FAR] = newFar;
}

void CameraValues::setOrthoLeft(double newLeft)
{
    ortho[LEFT] = newLeft;
}

void CameraValues::setOrthoRight(double newRight)
{
    ortho[RIGHT] = newRight;
}

void CameraValues::setOrthoTop(double newTop)
{
    ortho[TOP] = newTop;
}

void CameraValues::setOrthoBottom(double newBottom)
{
    ortho[BOTTOM] = newBottom;
}

void CameraValues::apply()
{

}

void CameraValues::addValues(char* element, char* attribute, char* value)
{
    if (!strcmp("perspective", element))
        addPerspectiveValues(attribute, value);
    else if (!strcmp("from", element))
        addFromValues(attribute, value);
    else if (!strcmp("to", element))
        addToValues(attribute, value);
    else if (!strcmp("ortho", element))
        addOrthoValues(attribute, value);
}