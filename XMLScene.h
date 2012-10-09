#ifndef _XMLSCENE_H_
#define _XMLSCENE_H_

#include "tinyxml.h"
#include <set>

using namespace std;

class XMLScene
{
public:
    XMLScene(char *filename);
    ~XMLScene();

    static TiXmlElement *findChildByAttribute(TiXmlElement *parent, const char * attr, const char *val);
	void parsingCycle(TiXmlElement* elem);

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
};

#endif