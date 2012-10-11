#ifndef CAMERAVALUES_H
#define	CAMERAVALUES_H

#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <map>

#include "CGFcamera.h"
#include "SceneValues.h"

using namespace std;

/* ======= CAMERA TYPE ======== */

const unsigned int ORTHO = 0;
const unsigned int PERSPECTIVE = 1;

typedef map <string, CGFcamera*> lsf_cams;

class CameraValues : public SceneValues
{
private:
    static string initial_cam_id;

    bool is_initial;
    lsf_cams cams;

public:
    CameraValues();
    virtual ~CameraValues();

    bool isInitial();

    void addPerspectiveValues(char* attribute, char* value);
    void addFromValues(char* attribute, char* value);
    void addToValues(char* attribute, char* value);
    void addOrthoValues(char* attribute, char* value);

    void setID(char* newID);

    void static setInitialCameraID(char* newID);

    void apply();
    void addValues(char* element, char* attribute, char* value);
};

#endif	/* CAMERAVALUES_H */