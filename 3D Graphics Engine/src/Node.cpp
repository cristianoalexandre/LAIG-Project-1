#include <string.h>
#include <stdlib.h>

#include "Node.h"

Node::Node()
{
	id = "not defined";
	appearance = NULL;

	Rectangle* rect = new Rectangle();
	pair<string, Primitive*> rectangle("rectangle",rect);
	Triangle* tri = new Triangle();
	pair<string, Primitive*> triangle("triangle",tri);
	Cylinder* cyl = new Cylinder();
	pair<string, Primitive*> cylinder("cylinder",cyl);
	Sphere* sph = new Sphere();
	pair<string, Primitive*> sphere("sphere",sph);
	Torus* tor = new Torus();
	pair<string, Primitive*> torus("torus",tor);

	this->primitiveTypes.insert(rectangle);
	this->primitiveTypes.insert(triangle);
	this->primitiveTypes.insert(cylinder);
	this->primitiveTypes.insert(sphere);
	this->primitiveTypes.insert(torus);

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

void Node::setID(string ID)
{
	this->id = ID;
}

void Node::addChild(Node* child)
{
	children.push_back(child);
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
	for (size_t i = 0; i < children.size(); i++)
	{
		if (children.at(i) == NULL)
		{
			return true;
		}
	}

	return false;
}

void Node::setAppearance(Appearance* appearance)
{
	this->appearance = appearance;
}

string Node::getID()
{
	return this->id;
}

bool Node::operator==(Node &n)
{
	return id == n.getID();
}

void Node::addValues(char* elem, char* attr, char* value){

	string elemName = string(elem);
	string attribute = string(attr);

	if(elemName == "node"){
		if(attribute == "id"){
			this->setID(string(value));
		}else{
			printf("ERROR - unrecognized node attribute\n");
		}
	}else{
		if(elemName == "rectangle"){
			map<string,Primitive*>::iterator it = primitiveTypes.find("rectangle");
			if(it->second->addValues(attr, string(value))){
				printf("ADICIONADA PRIMITIVA\n");
				this->addPrimitive(it->second);
			}
		}


		if(elemName == "scale" || elemName == "rotate" || elemName == "translate"){
			this->transforms.addValues(elem, attr, value);
		}
	}
}

void Node::addPrimitive(Primitive* prim){

	this->primitives.push_back(prim);
}

vector<Node*>* Node::getChildren(){

	vector<Node*>* ptrChildren = &this->children;
	return ptrChildren;
}

bool Node::hasChildren(){

	return !(this->getChildren()->empty());
}

bool Node::hasPrimitives(){

	if(this->primitives.size() == 0){
		return false;
	}else{
		return true;
	}
}

Appearance* Node::getAppearance(){

	return this->appearance;

}

void Node::draw(){



	cout << "Node ID = " << this->getID() << endl;
	this->transforms.apply();

	//cin.get();
	if(this->appearance != NULL){
		this->appearance->applyValues();
	}
	//cin.get();
	vector<Primitive*>::iterator iti = this->primitives.begin();
	vector<Primitive*>::iterator itf = this->primitives.end();

	while(iti != itf){
		(*iti)->draw();
		iti++;
	}


}


