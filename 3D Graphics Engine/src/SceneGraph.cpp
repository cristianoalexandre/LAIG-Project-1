#include "SceneGraph.h"

SceneGraph::SceneGraph()
{

}

SceneGraph::SceneGraph(map<string, Node*> &scene_map)
{
    this->scene_map = scene_map;
}

void SceneGraph::addNode(Node* node)
{
    pair<string, Node*> new_elem(node->getID(), node);
    scene_map.insert(new_elem);
}

string SceneGraph::getNodeID(Node* node)
{
    for (lsfmap::iterator it = scene_map.begin(); it != scene_map.end(); it++)
    {
        if (*(it->second) == (*node))
            return it->first;
    }

    return "";
}

Node* SceneGraph::getNodeById(string id)
{
    return scene_map.at(id);
}


void SceneGraph::printNodesID(){

	lsfmap::iterator iti = this->scene_map.begin();
	lsfmap::iterator itf = this->scene_map.end();

	while(iti != itf){

		cout << "ID = " << (*iti).second->getID() << endl;
		iti++;
	}
}