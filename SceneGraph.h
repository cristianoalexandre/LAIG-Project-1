#ifndef SCENEGRAPH_H
#define	SCENEGRAPH_H

#include <map>

#include "Node.h"

using namespace std;

class SceneGraph
{
private:
    map<char*,Node*> scene_map;
    
public:
    SceneGraph();
    SceneGraph(map<char*,Node*>);
    
    Node* getNodeById(char* id);
    int getNodeID(Node* node);
};

#endif	/* SCENEGRAPH_H */

