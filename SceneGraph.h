#ifndef SCENEGRAPH_H
#define	SCENEGRAPH_H

#include <map>
#include <string>

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
    
    Node* getNodeById(char* id);
    string getNodeID(Node* node);
    void addNode(Node* node);
};

#endif	/* SCENEGRAPH_H */

