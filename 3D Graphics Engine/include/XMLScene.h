#ifndef _XMLSCENE_H_
#define _XMLSCENE_H_

#include "tinyxml.h"
#include "GlobalValues.h"
#include "CameraValues.h"
#include "AppearanceValues.h"
#include "LightValues.h"
#include "SceneGraph.h"
#include "CGFscene.h"

#include <set>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>


using namespace std;

class XMLScene : public CGFscene
{
public:
    XMLScene(char *filename);
    virtual ~XMLScene();

    void initParser(TiXmlElement* elem);
    void parsingCycle(TiXmlElement* elem, SceneValues &val);
    void singleElementAttributeParser(SceneValues &val, TiXmlElement* elem);
    void parsingNodesCycle(TiXmlElement* elem, Node* node);
    void nodeAttributeParser(char* name, TiXmlElement* elem, Node* no);
    void applyRefs(TiXmlElement* elem);
    void display();
	void drawScene(Node* root);
protected:

    bool preParserCompleted;

    set <TiXmlElement*> elements;
	queue<Node*> nodeInOrderOfProcessing;
	stack<Primitive*> toDraw;

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
    AppearanceValues av;
    //SceneValues sv;

    SceneGraph sGraph;
};

#endif