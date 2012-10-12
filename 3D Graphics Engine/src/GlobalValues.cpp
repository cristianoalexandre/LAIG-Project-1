#include <GL/glew.h>

#include "GlobalValues.h"

GlobalValues::GlobalValues()
{
    background.push_back(0);
    background.push_back(0);
    background.push_back(0);
    background.push_back(0);

    polygon.push_back("fill");
    polygon.push_back("goraud");

    culling.push_back("CCW");
    culling.push_back("back");
    culling.push_back("true");
}

void GlobalValues::addBackgroundValues(char* attribute, char* value)
{
    int value_int = atoi(value);

    if (!strcmp("R", attribute))
        setBackgroundR(value_int);
    else if (!strcmp("G", attribute))
        setBackgroundG(value_int);
    else if (!strcmp("B", attribute))
        setBackgroundB(value_int);
    else if (!strcmp("A", attribute))
        setBackgroundA(value_int);
}

void GlobalValues::addCullingValues(char* attribute, char* value)
{
    if (!strcmp("frontfaceorder", attribute))
        setCullingFrontFaceOrder(value);
    else if (!strcmp("cullface", attribute))
        setCullingCullface(value);
    else if (!strcmp("enabled", attribute))
        setCullingEnabled(value);
}

void GlobalValues::setBackgroundA(float newA)
{
    background.at(A) = newA;
}

void GlobalValues::setBackgroundB(float newB)
{
    background.at(B) = newB;
}

void GlobalValues::setBackgroundG(float newG)
{
    background.at(G) = newG;
}

void GlobalValues::setBackgroundR(float newR)
{
    background.at(R) = newR;
}

void GlobalValues::setCullingCullface(char* new_cullface)
{
    culling.at(CULLFACE) = string(new_cullface);
}

void GlobalValues::setCullingEnabled(char* new_enabled)
{
    culling.at(ENABLED) = string(new_enabled);
}

void GlobalValues::setCullingFrontFaceOrder(char* new_frontfaceorder)
{
    culling.at(FRONTFACEORDER) = string(new_frontfaceorder);
}

void GlobalValues::setPolygonMode(char* new_mode)
{
    polygon.at(MODE) = string(new_mode);
}

void GlobalValues::apply()
{
    glClearColor(background[R], background[G], background[B], background[A]);

    GLenum polygon_mode;
    GLenum polygon_shading;
    GLenum culling_ffo;
    GLenum culling_cullface;

    if (polygon[MODE] == "fill")
        polygon_mode = GL_FILL;
    else if (polygon[MODE] == "line")
        polygon_mode = GL_LINE;
    else if (polygon[MODE] == "point")
        polygon_mode = GL_POINT;
    else
    {
        cerr << "ERROR: unknown polygon mode";
        exit(1);
    }

    if (polygon[SHADING] == "goraud")
        polygon_shading = GL_SMOOTH;
    else if (polygon[SHADING] == "flat")
        polygon_shading = GL_FLAT;
    else
    {
        cerr << "ERROR: unknown polygon shading";
        exit(1);
    }

    if (culling[FRONTFACEORDER] == "CCW")
        culling_ffo = GL_CCW;
    else if (culling[FRONTFACEORDER] == "CW")
        culling_ffo = GL_CW;
    else
    {
        cerr << "ERROR: unknown culling frontfaceorder";
        exit(1);
    }

    if (culling[CULLFACE] == "back")
        culling_cullface = GL_BACK;
    else if (culling[CULLFACE] == "front")
        culling_cullface = GL_FRONT;
    else if (culling[CULLFACE] == "both")
        culling_cullface = GL_FRONT_AND_BACK;
    else
    {
        cerr << "ERROR: unknown culling cullface";
        exit(1);
    }

    if (culling[ENABLED] == "true")
        glPolygonMode(culling_cullface, polygon_mode);
    else if (culling[ENABLED] != "false")
    {
        cerr << "ERROR: unknown polygon mode";
        exit(1);
    }

    glShadeModel(polygon_shading);
    glFrontFace(culling_ffo);

}

void GlobalValues::addValues(char* element, char* attribute, char* value)
{
    if (!strcmp("background", element))
        addBackgroundValues(attribute, value);
    else if (!strcmp("polygon", element))
        addBackgroundValues(attribute, value);
    else if (!strcmp("culling", element))
        addBackgroundValues(attribute, value);
    else
    {
        cerr << "ERROR: globalvalues -> unknown element";
        exit(1);
    }
}