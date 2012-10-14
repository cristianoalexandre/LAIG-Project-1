#include <GL/glew.h>
#include <map>

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
        appearances.insert(pair <string,Appearance*> ((string) value, new Appearance(string(value))));
    }
    else if (!strcmp("emissive", element))
    {
        appearances.rbegin()->second->addEmissiveValue(attribute, value_f);
    }
    else if (!strcmp("ambient", element))
    {
        appearances.rbegin()->second->addAmbientValue(attribute, value_f);
    }
    else if (!strcmp("diffuse", element))
    {
        appearances.rbegin()->second->addDiffuseValue(attribute, value_f);
    }
    else if (!strcmp("specular", element))
    {
        appearances.rbegin()->second->addSpecularValue(attribute, value_f);
    }
    else if (!strcmp("shininess", element))
    {
        appearances.rbegin()->second->setShininess(value_f);
    }
    else if (!strcmp("texture", element))
    {
        appearances.rbegin()->second->addTexture(attribute, value);
    }
    else
    {
        cerr << "ERROR: appearance values - unknown element: " << element;
    }
    
}


Appearance* AppearanceValues::getAppearance(string id){
	
	if(id == "inherit"){
		return NULL;
	}else{
		return this->appearances.at(id);
	}
}

void AppearanceValues::apply()
{
    for (lsf_appearances::iterator it = appearances.begin(); it != appearances.end(); it++)
    {
        it->second->apply();
    }
}