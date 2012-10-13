#ifndef SCENEGRAPH_H
#define	SCENEGRAPH_H

#include <map>
#include <string>
#include <iostream>

#include "Node.h"

using namespace std;

typedef map<string,Node*> lsfmap;

class SceneGraph
{
private:
    lsfmap scene_map;
    

public:
    
    SceneGraph();
    SceneGraph(lsfmap &scene_map);
    
    Node* getNodeById(string id);
    string getNodeID(Node* node);
    void addNode(Node* node);
	void printNodesID();
};

#endif	/* SCENEGRAPH_H */

