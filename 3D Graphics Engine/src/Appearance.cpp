#include "Appearance.h"

#include "GL/glew.h"

Appearance::Appearance(string id){

	this->id = id;
}


void Appearance::addAmbientValue(char* attribute, float value)
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

void Appearance::addDiffuseValue(char* attribute, float value)
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

void Appearance::addEmissiveValue(char* attribute, float value)
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

void Appearance::addSpecularValue(char* attribute, float value)
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

void Appearance::applyValues()
{
    setAmbient(ambient);
    setDiffuse(diffuse);
    setShininess(shininess);
    setSpecular(specular);
    //setTexture(texture_file);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emissive);
    apply();
}

void Appearance::setShininess(float value)
{
    shininess = value;
}