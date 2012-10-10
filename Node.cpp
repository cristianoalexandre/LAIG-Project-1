#include <string.h>
#include <stdlib.h>

#include "Node.h"

Node::Node()
{
	id = "not defined";
	appearance = NULL;
}

Node::Node(char* node_id)
{
	id = string(node_id);
	appearance = NULL;
}

Node::Node(string node_id)
{
	id = node_id;
	appearance = NULL;
}

void Node::setID(string ID){
	this->id = ID;
}

void Node::addChild(Node* child)
{
	children.push_back(child);
}

void Node::addChildID(char* id)
{
	children_id.push_back(id);
}

Node* Node::getChildByID(char* id)
{
	return getChildByID(string(id));
}

Node* Node::getChildByID(string id)
{
	for (vector <Node*>::iterator it = children.begin(); it != children.end(); it++)
	{
		if ((*it)->getID() == id)
		{
			return (*it);
		}
	}

	return NULL;
}

int Node::getNumberOfChildren()
{
	return children.size();
}

bool Node::seekNonExistentChildren()
{
	if (children_id.size() > children.size())
	{
		return true;
	}

	return false;
}

void Node::setAppearance(CGFappearance* appearance)
{
	this->appearance = appearance;
}

string Node::getID()
{
	return id;
}

bool Node::operator==(Node &n)
{
	return id == n.getID();
}


void Node::addValues(char* elem, char* attr, char* value){

	string elemName = string(elem);
	string attribute = string(elem);

	if(elemName == "node"){
		if(attribute == "id"){
			this->setID(string(value));
		}else{
			printf("ERROR - unrecognized node attribute\n");
		}
	}else{
		if(elemName == "scale" || elemName == "rotate" || elemName == "translate"){
			this->transforms.addValues(elem, attr, value);
		}else{
			if(elemName == "appearanceref"){

				
				//this->setAppearance();
			}
		}

	}


}