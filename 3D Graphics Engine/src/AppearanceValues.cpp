#include <GL/glew.h>

#include "AppearanceValues.h"

AppearanceValues::AppearanceValues()
{

}

AppearanceValues::~AppearanceValues()
{

}

void AppearanceValues::addValues(char* element, char* attribute, char* value)
{
    float value_f = atof(value);

    if (!strcmp("appearance", element))
    {
        id = (string) value;
    }
    else if (!strcmp("emissive", element))
    {
        addEmissiveValue(attribute, value_f);
    }
    else if (!strcmp("ambient", element))
    {
        addAmbientValue(attribute, value_f);
    }
    else if (!strcmp("diffuse", element))
    {
        addDiffuseValue(attribute, value_f);
    }
    else if (!strcmp("specular", element))
    {
        addSpecularValue(attribute, value_f);
    }
    else if (!strcmp("shininess", element))
    {
        shininess = value_f;
    }
    else if (!strcmp("texture", element))
    {
        texture_file = (string) value;
    }
    else
    {
        cerr << "ERROR: appearance values - unknown element: " << element;
    }

}

void AppearanceValues::addAmbientValue(char* attribute, float value)
{
    if (!strcmp("r", attribute))
        ambient[R] = value;
    else if (!strcmp("g", attribute))
        ambient[G] = value;
    else if (!strcmp("b", attribute))
        ambient[B] = value;
    else if (!strcmp("a", attribute))
        ambient[A] = value;
    else
    {
        cerr << "ERROR: appearance ambient values - unknown attribute: " << attribute;
    }
}

void AppearanceValues::addDiffuseValue(char* attribute, float value)
{
    if (!strcmp("r", attribute))
        diffuse[R] = value;
    else if (!strcmp("g", attribute))
        diffuse[G] = value;
    else if (!strcmp("b", attribute))
        diffuse[B] = value;
    else if (!strcmp("a", attribute))
        diffuse[A] = value;
    else
    {
        cerr << "ERROR: appearance diffuse values - unknown attribute: " << attribute;
    }
}

void AppearanceValues::addEmissiveValue(char* attribute, float value)
{
    if (!strcmp("r", attribute))
        emissive[R] = value;
    else if (!strcmp("g", attribute))
        emissive[G] = value;
    else if (!strcmp("b", attribute))
        emissive[B] = value;
    else if (!strcmp("a", attribute))
        emissive[A] = value;
    else
    {
        cerr << "ERROR: appearance emissive values - unknown attribute: " << attribute;
    }
}

void AppearanceValues::addSpecularValue(char* attribute, float value)
{
    if (!strcmp("r", attribute))
        specular[R] = value;
    else if (!strcmp("g", attribute))
        specular[G] = value;
    else if (!strcmp("b", attribute))
        specular[B] = value;
    else if (!strcmp("a", attribute))
        specular[A] = value;
    else
    {
        cerr << "ERROR: appearance specular values - unknown attribute: " << attribute;
    }
}

void AppearanceValues::apply()
{
    setAmbient(ambient);
    setDiffuse(diffuse);
    setShininess(shininess);
    setSpecular(specular);
    setTexture(texture_file);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emissive);
}