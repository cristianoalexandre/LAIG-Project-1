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
		Appearance* tmp = (*iti).second->getAppearance();
		if(tmp == NULL){

			printf("Appearance = NULL\n");
		}else{
			cout << "Appearance = " << tmp->id << endl;
		}
		iti++;
	}
}

void SceneGraph::drawCycle(Node* root){

	root->draw();

	if(root->hasChildren()){

		vector<Node*>* children = root->getChildren();
		vector<Node*>::iterator it;

		for(it = children->begin(); it != children->end(); it++){

			if((*it)->getAppearance() == NULL){			
				drawCycle(*it);
			}else{
				this->nodeInOrderOfProcessing.push(*it);
			}
		}
	}
}