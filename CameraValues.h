#ifndef CAMERAVALUES_H
#define	CAMERAVALUES_H

#include "SceneValues.h"

class CameraValues : public SceneValues
{
private:

public:
    CameraValues();
    virtual ~CameraValues();
    void apply();
    void addValues(char* element, char* attribute, char* value);
};

#endif	/* CAMERAVALUES_H */