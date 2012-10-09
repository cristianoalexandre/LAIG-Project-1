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
    
    if (!strcmp("R",attribute))
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

void GlobalValues::setBackgroundA(int newA)
{
    background.at(A) = newA;
}

void GlobalValues::setBackgroundB(int newB)
{
    background.at(B) = newB;
}

void GlobalValues::setBackgroundG(int newG)
{
    background.at(G) = newG;
}

void GlobalValues::setBackgroundR(int newR)
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

}

void GlobalValues::addValues(char* element, char* attribute, char* value)
{
    if (!strcmp("background",element))
        addBackgroundValues(attribute,value);
    else if(!strcmp("polygon", element))
        addBackgroundValues(attribute,value);
    else if(!strcmp("culling",element))
        addBackgroundValues(attribute,value);
}