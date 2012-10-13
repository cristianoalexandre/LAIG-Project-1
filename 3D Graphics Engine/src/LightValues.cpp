#include <map>

#include "LightValues.h"

LightValues::LightValues()
{
    for (int i = 0; i < 3; i++)
        ambient_light.push_back(0);
}

LightValues::~LightValues()
{

}

void LightValues::apply()
{
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, &ambient_light[0]);

    for (lsf_lights::iterator it = lights.begin(); it != lights.end(); it++)
    {
        it->second->draw();
    }
}

void LightValues::addValues(char* element, char* attribute, char* value)
{
    bool ambient_light = true;

    if (!strcmp("lighting", element))
    {

    }
    else if (!strcmp("ambient", element))
    {
        if (ambient_light)
        {
            ambient_light = false;
            setAmbientLight(attribute, value);
        }
        else
        {
            setLightAmbientComponent(attribute, value);
        }
    }
    else if (!strcmp("light", element))
    {
        setLightInitSettings(attribute, value);
    }
    else if (!strcmp("location", element))
    {
        setLightPositionSettings(attribute, value);
    }
    else if (!strcmp("diffuse", element))
    {
        setLightDiffuseComponent(attribute, value);
    }
    else if (!strcmp("specular", element))
    {
        setLightSpecularComponent(attribute, value);
    }
}

void LightValues::setLightInitSettings(char* attribute, char* value)
{
    if (!strcmp("id", attribute))
    {
        lights.insert(pair<string, Light*> (string(value), new Light(value)));
    }
    else if (!strcmp("enabled", attribute))
    {
        if (!strcmp("true", value))
        {
            lights.rbegin()->second->enable();
        }
        else if (!strcmp("false", value))
        {
            lights.rbegin()->second->disable();
        }
        else
        {
            cerr << "LightInitialValues: Unknown value - " << attribute;
            exit(1);
        }

    }
    else
    {
        cerr << "LightInitialValues: Unknown attribute - " << attribute;
        exit(1);
    }
}

void LightValues::setLightPositionSettings(char* attribute, char* value)
{
    float value_f = atof(value);

    cout << "Light " << lights.rbegin()->second->getID() << " - " << attribute << ": " << value;
    
    if (!strcmp("x", attribute))
    {
        lights.rbegin()->second->setLocationX(value_f);
    }
    else if (!strcmp("y", attribute))
    {
        lights.rbegin()->second->setLocationY(value_f);
    }
    else if (!strcmp("z", attribute))
    {
        lights.rbegin()->second->setLocationZ(value_f);
    }
    else
    {
        cerr << "LightComponentValues: Unknown attribute - " << attribute;
        exit(1);
    }
}

void LightValues::setAmbientLight(char* attribute, char* value)
{
    float value_f = atof(value);

    if (!strcmp("r", attribute))
        ambient_light[R] = value_f;
    else if (!strcmp("g", attribute))
        ambient_light[G] = value_f;
    else if (!strcmp("b", attribute))
        ambient_light[B] = value_f;
    else if (!strcmp("a", attribute))
        ambient_light[A] = value_f;
    else
    {
        cerr << "AmbientLight : Unknown attribute - " << attribute;
        exit(1);
    }
}

void LightValues::setLightAmbientComponent(char* attribute, char* value)
{
    float value_f = atof(value);

    if (!strcmp("r", attribute))
        lights.rbegin()->second->setAmbientR(value_f);
    else if (!strcmp("g", attribute))
        lights.rbegin()->second->setAmbientG(value_f);
    else if (!strcmp("b", attribute))
        lights.rbegin()->second->setAmbientB(value_f);
    else if (!strcmp("a", attribute))
        lights.rbegin()->second->setAmbientA(value_f);
    else
    {
        cerr << "AmbientComponent : Unknown attribute - " << attribute;
        exit(1);
    }
}

void LightValues::setLightDiffuseComponent(char* attribute, char* value)
{
    float value_f = atof(value);

    if (!strcmp("r", attribute))
        lights.rbegin()->second->setDiffuseR(value_f);
    else if (!strcmp("g", attribute))
        lights.rbegin()->second->setDiffuseG(value_f);
    else if (!strcmp("b", attribute))
        lights.rbegin()->second->setDiffuseB(value_f);
    else if (!strcmp("a", attribute))
        lights.rbegin()->second->setDiffuseA(value_f);
    else
    {
        cerr << "DiffuseLight : Unknown attribute - " << attribute;
        exit(1);
    }
}

void LightValues::setLightSpecularComponent(char* attribute, char* value)
{
    float value_f = atof(value);

    if (!strcmp("r", attribute))
        lights.rbegin()->second->setDiffuseR(value_f);
    else if (!strcmp("g", attribute))
        lights.rbegin()->second->setDiffuseG(value_f);
    else if (!strcmp("b", attribute))
        lights.rbegin()->second->setDiffuseB(value_f);
    else if (!strcmp("a", attribute))
        lights.rbegin()->second->setDiffuseA(value_f);
    else
    {
        cerr << "Specular Light : Unknown attribute - " << attribute;
        exit(1);
    }
}