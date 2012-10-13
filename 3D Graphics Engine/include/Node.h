#ifndef NODE_H
#define	NODE_H

#include <vector>
#include <string>
#include <cstdio>
#include <set>

#include "Rectangle.h"
#include "Cylinder.h"
#include "Torus.h"
#include "Triangle.h"
#include "Sphere.h"
#include "CGFappearance.h"
#include "CGFobject.h"
#include "TransformValues.h"


using namespace std;

class Node
{
private:
    string id;
    vector <Node*> children;
    vector <Primitive*> primitives;
	map<string, Primitive*> primitiveTypes;
    int transf_matrix[4][4];
    CGFappearance* appearance;
    TransformValues transforms;
public:
    Node();
    Node(char* node_id);
    Node(string node_id);
    string getID();
    void setID(string ID);
    void addChild(Node* child);
    int getNumberOfChildren();
    void setAppearance(CGFappearance* appearance);
    bool seekNonExistentChildren();
    Node* getChildByID(char* id);
    Node* getChildByID(string id);
	CGFappearance* getAppearance();
	vector<Node*>* getChildren();
	bool hasChildren();
	void draw();

    void addValues(char* elem, char* attr, char* value);

	void addPrimitive(Primitive* prim);

    bool operator==(Node &n);

};

#endif	/* NODE_H */