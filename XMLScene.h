#ifndef _XMLSCENE_H_
#define _XMLSCENE_H_

#include "tinyxml.h"
#include "GlobalValues.h"
#include "CameraValues.h"
#include "AppearanceValues.h"
#include "LightValues.h"
#include "SceneGraph.h"
#include <set>

using namespace std;

class XMLScene
{
public:
    XMLScene(char *filename);
    ~XMLScene();

    static TiXmlElement *findChildByAttribute(TiXmlElement *parent, const char * attr, const char *val);

	void initParser(TiXmlElement* elem);
	void parsingCycle(TiXmlElement* elem, SceneValues val);
	void attributeParser(SceneValues val, TiXmlElement* elem);

protected:

	set <TiXmlElement*> elements;

    TiXmlDocument* doc;

    TiXmlElement* globalsElement;
    TiXmlElement* camerasElement;
    TiXmlElement* lightningElement;
    TiXmlElement* appearancesElement;
    TiXmlElement* leavesElement;
    TiXmlElement* nodesElement;
    TiXmlElement* graphElement;

	GlobalValues gv;
	CameraValues cv;
	LightValues lv;
//	AppearanceValues av;
};

#endif