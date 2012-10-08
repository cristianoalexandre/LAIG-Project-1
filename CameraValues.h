#ifndef CAMERAVALUES_H
#define	CAMERAVALUES_H

#include "SceneValues.h"

#include <string>

using namespace std;

/* Polygon - mode */
#define FILL 0

/* Polygon - shading */
#define GORAUD 0

/* Culling - Front Face Order */
#define CCW 0

/* Culling - Cullface */
#define BACK 0

/* Culling - enabled */
#define FALSE 0
#define TRUE 1

class CameraValues : public SceneValues
{
private:
    vector <int> background; /* R,G,B,A */
    vector <int> polygon; /* mode, shading */
    vector <int> culling; /* frontfaceorder, cullface, enabled */

    addBackgroundValues(vector <int> values);
    addPolygonValues(vector <int> values);
    addCullingValues(vector <int> values);

public:
    CameraValues();
    void addBackgroundValues(vector <int> values);
    void addBackgroundValues(int R, int G, int B, int A);
    void addPolygonValues(vector <string> values);
    void addPolygonValues(string mode, string shading);
    void addCullingValues(vector <string> values);
    void addCullingValues(string frontfaceorder, string cullface, string enabled);
    
    void setBackgroundR(int R);
    void setBackgroundG(int G);
    void setBackgroundB(int B);
    void setBackgroundA(int A);
    void setPolygonMode(string mode);
    void setPolygonShading(string mode);
    void setCullingFrontFaceOrder(string frontfaceorder);
    void setCullingCullface(string cullface);
    void setCullingEnabled(string enabled);
};

#endif	/* CAMERAVALUES_H */