#include "Light.h"

unsigned int Light::light_number = 0;

Light::Light()
{
    id = "not defined!";

    for (int i = 0; i < 3; i++)
        location.push_back(0);

    for (int i = 0; i < 4; i++)
        ambient.push_back(0);

    for (int i = 0; i < 4; i++)
        diffuse.push_back(0);

    for (int i = 0; i < 4; i++)
        specular.push_back(0);

    light = new CGFlight(GL_LIGHT0 + light_number, &location[0]);
    cout << "Creating light " << light_number << endl;
    addLightNumber();
}

Light::Light(char* id)
{
    this->id = string(id);
    for (int i = 0; i < 3; i++)
        location.push_back(0);

    for (int i = 0; i < 4; i++)
        ambient.push_back(0);

    for (int i = 0; i < 4; i++)
        diffuse.push_back(0);

    for (int i = 0; i < 4; i++)
        specular.push_back(0);

    light = new CGFlight(GL_LIGHT0 + light_number, &location[0]);
    addLightNumber();
}

void Light::setAmbientA(float newA)
{
    ambient[A] = newA;
    applyValues();
}

void Light::setAmbientR(float newR)
{
    ambient[R] = newR;
    applyValues();
}

void Light::setAmbientG(float newG)
{
    ambient[G] = newG;
    applyValues();
}

void Light::setAmbientB(float newB)
{
    ambient[B] = newB;
    applyValues();
}

void Light::setDiffuseR(float newR)
{
    diffuse[R] = newR;
    applyValues();
}

void Light::setDiffuseG(float newG)
{
    diffuse[G] = newG;
    applyValues();
}

void Light::setDiffuseB(float newB)
{
    diffuse[B] = newB;
    applyValues();
}

void Light::setDiffuseA(float newA)
{
    diffuse[A] = newA;
    applyValues();
}

void Light::setSpecularR(float newR)
{
    specular[R] = newR;
    applyValues();
}

void Light::setSpecularG(float newG)
{
    specular[G] = newG;
    applyValues();
}

void Light::setSpecularB(float newB)
{
    specular[B] = newB;
    applyValues();
}

void Light::setSpecularA(float newA)
{
    specular[A] = newA;
    applyValues();
}

void Light::setLocationX(float newX)
{
    location[X] = newX;
    applyValues();
}

void Light::setLocationY(float newY)
{
    location[Y] = newY;
    applyValues();
}

void Light::setLocationZ(float newZ)
{
    location[Z] = newZ;
    applyValues();
}

void Light::applyValues()
{
    light->setAmbient(&ambient[0]);
    light->setDiffuse(&diffuse[0]);
    light->setSpecular(&specular[0]);
}

void Light::draw()
{
    glPushMatrix();
    cout << "Drawing light " << id << endl;
    cout << "Location: " << location[X] << "," << location[Y] << "," << location[Z] << endl;
    glTranslatef(location[X], location[Y], location[Z]);
    light->draw();
    glPopMatrix();
}

void Light::enable()
{
    light->enable();
}

void Light::disable()
{
    light->disable();
}

void Light::addLightNumber()
{
    if (light_number > 7)
    {
        cerr << "Number of lights exceeded!";
        exit(1);
    }

    light_number++;
}