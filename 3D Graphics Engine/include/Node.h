#ifndef NODE_H
#define	NODE_H

#include <vector>
#include <string>

#include "Figure.h"
#include "CGFappearance.h"
#include "CGFobject.h"
#include "TransformValues.h"


using namespace std;

class Node : public CGFobject
{
    
private:
    string id;
    vector <char*> children_id;
    vector <Node*> children;
    vector <Figure*> primitives;
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
    void addChildID(char* id);
    int getNumberOfChildren();
    void setAppearance(CGFappearance* appearance);
    bool seekNonExistentChildren();
    Node* getChildByID(char* id);
    Node* getChildByID(string id);

	void addValues(char* elem, char* attr, char* value);
    
    bool operator==(Node &n);

};

#endif	/* NODE_H */