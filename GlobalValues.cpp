#include <vector>

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

}

void GlobalValues::setBackgroundA(int A)
{

}

void GlobalValues::setBackgroundB(int B)
{

}

void GlobalValues::setBackgroundG(int G)
{

}

void GlobalValues::setBackgroundR(int R)
{

}

void GlobalValues::setCullingCullface(string cullface)
{

}

void GlobalValues::setCullingEnabled(string enabled)
{

}

void GlobalValues::setCullingFrontFaceOrder(string frontfaceorder)
{

}

void GlobalValues::setPolygonMode(string mode)
{

}

void GlobalValues::apply()
{
    
}