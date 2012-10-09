#ifndef GLOBALVALUES_H
#define	GLOBALVALUES_H

#include "SceneValues.h"

#include <string>
#include <vector>

using namespace std;

/* ======== VECTOR POSITIONS ======== */
/* Background */
const unsigned int R = 0;
const unsigned int G = 1;
const unsigned int B = 2;
const unsigned int A = 3;

/* Polygon */
const unsigned int MODE = 0;
const unsigned int SHADING = 1;

/* Culling */
const unsigned int FRONTFACEORDER = 0;
const unsigned int CULLFACE = 1;
const unsigned int ENABLED = 2;

/* ======== OPTIONS ========*/
/* Polygon - mode */
const unsigned int FILL = 0;

/* Polygon - shading */
const unsigned int GORAUD = 0;

/* Culling - Front Face Order */
const unsigned int CCW = 0;

/* Culling - Cullface */
const unsigned int BACK = 0;

/* Culling - enabled */
const unsigned int FALSE = 0;
const unsigned int TRUE = 0;

class GlobalValues : public SceneValues
{
private:
    vector <int> background; /* R,G,B,A */
    vector <int> polygon; /* mode, shading */
    vector <int> culling; /* frontfaceorder, cullface, enabled */

    void addPolygonValues(vector <int> values);
    void addCullingValues(vector <int> values);
    
    vector<int> parseCullingFrontFaceOrder(string value);
    vector<int> parseCullingCullFace(string value);

public:
    GlobalValues();
    void addBackgroundValues(vector <int> values);
    void addBackgroundValues(int R, int G, int B, int A);
    void addPolygonValues(vector <string> values);
    void addPolygonValues(string mode, string shading);
    void addCullingValues(vector <string> values);
    void addCullingValues(string frontfaceorder, string cullface, string enabled);

<<<<<<< HEAD
    void setBackgroundR(int newR);
    void setBackgroundG(int newG);
    void setBackgroundB(int newB);
    void setBackgroundA(int newA);
    void setPolygonMode(char* new_mode);
    void setPolygonShading(char* new_mode);
    void setCullingFrontFaceOrder(char* new_frontfaceorder);
    void setCullingCullface(char* new_cullface);
    void setCullingEnabled(char* new_enabled);
=======
	void setBackgroundR(int R);
    void setBackgroundG(int G);
    void setBackgroundB(int B);
    void setBackgroundA(int A);
    void setPolygonMode(string mode);
    void setPolygonShading(string mode);
    void setCullingFrontFaceOrder(string frontfaceorder);
    void setCullingCullface(string cullface);
    void setCullingEnabled(string enabled);
>>>>>>> 73a32f2fb6a6f013031166d76e030b8182f0d898
    
    void apply();
};

#endif	/* GLOBALVALUES_H */

