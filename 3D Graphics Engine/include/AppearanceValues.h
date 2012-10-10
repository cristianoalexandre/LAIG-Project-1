#ifndef APPEARANCEVALUES_H
#define APPEARANCEVALUES_H

#include "SceneValues.h"

class AppearanceValues : public SceneValues
{
private:

public:
    AppearanceValues();
    virtual ~AppearanceValues();
    void apply();
    void addValues(char* element, char* attribute, char* value);
};

#endif	/* APPEARANCEVALUES_H */

