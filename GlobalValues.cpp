#include "GlobalValues.h"

GlobalValues::GlobalValues()
{
    background.push_back(0);
    background.push_back(0);
    background.push_back(0);
    background.push_back(0);

    polygon.push_back(FILL);
    polygon.push_back(GORAUD);

    culling.push_back(CCW);
    culling.push_back(BACK);
    culling.push_back(TRUE);
}

void GlobalValues::addPolygonValues(vector<int> values)
{
    polygon = values;
}

void GlobalValues::addCullingValues(vector<int> values)
{
    culling = values;
}

void GlobalValues::addBackgroundValues(vector<int> values)
{
    background = values;
}

void GlobalValues::addBackgroundValues(int R, int G, int B, int A)
{
    vector <int> background_values;
    background_values.push_back(R);
    background_values.push_back(G);
    background_values.push_back(B);
    background_values.push_back(A);

    addBackgroundValues(background_values);
}

void GlobalValues::addPolygonValues(vector<string> values)
{
    vector <int> polygon_values;

    /* mode */
    if (values.at(0) == "fill")
        polygon_values.push_back(FILL);

    /* shading */
    if (values.at(0) == "goraud")
        polygon_values.push_back(GORAUD);

    addPolygonValues(polygon_values);
}

void GlobalValues::addPolygonValues(string mode, string shading)
{
    vector <string> polygon_values;
    polygon_values.push_back(mode);
    polygon_values.push_back(shading);

    addPolygonValues(polygon_values);
}

void GlobalValues::addCullingValues(vector<string> values)
{
    vector <int> culling_values;

    /* frontfaceorder */
    if (values.at(0) == "CCW")
        culling_values.push_back(CCW);

    /* cullface */
    if (values.at(1) == "back")
        culling_values.push_back(BACK);

    /* enabled */
    if (values.at(2) == "true")
        culling_values.push_back(TRUE);
    else if (values.at(2) == "false")
        culling_values.push_back(FALSE);
}

void GlobalValues::addCullingValues(string frontfaceorder, string cullface, string enabled)
{
    vector <string> culling_values;

    culling_values.push_back(frontfaceorder);
    culling_values.push_back(cullface);
    culling_values.push_back(enabled);

    addCullingValues(culling_values);
}

void GlobalValues::setBackgroundA(int newA)
{
    background.at(A) = newA;
}

void GlobalValues::setBackgroundB(int newB)
{
    background.at(B) = newB;
}

void GlobalValues::setBackgroundG(int newG)
{
    background.at(G) = newG;
}

void GlobalValues::setBackgroundR(int newR)
{
    background.at(R) = newR;
}

void GlobalValues::setCullingCullface(char* new_cullface)
{
    background.at(CULLFACE) = new_cullface;
}

void GlobalValues::setCullingEnabled(char* new_enabled)
{
    background.at(ENABLED) = new_enabled;
}

void GlobalValues::setCullingFrontFaceOrder(char* new_frontfaceorder)
{
    background.at(FRONTFACEORDER) = new_frontfaceorder;
}

void GlobalValues::setPolygonMode(char* new_mode)
{
    background.at(MODE) = new_mode;
}

void GlobalValues::apply()
{

}
