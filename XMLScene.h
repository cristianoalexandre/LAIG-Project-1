#ifndef _XMLSCENE_H_
#define _XMLSCENE_H_

#include "tinyxml.h"
#include <string>

using namespace std;

class XMLScene
{
public:
    XMLScene(char *filename);
    ~XMLScene();

    static TiXmlElement *findChildByAttribute(TiXmlElement *parent, const char * attr, const char *val);

protected:


    TiXmlDocument* doc;

    TiXmlElement* globalsElement;
    TiXmlElement* camerasElement;
    TiXmlElement* lightningElement;
    TiXmlElement* appearancesElement;
    TiXmlElement* leavesElement;
    TiXmlElement* nodesElement;
    TiXmlElement* graphElement;
    TiXmlElement* lightsElement;
};

void queryStringValue(TiXmlElement* elem, string &attr, string &value);
void queryBoolValue(TiXmlElement* elem, string &attr, bool &value);

#endif