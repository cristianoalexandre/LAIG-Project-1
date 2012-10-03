#ifndef NODE_H
#define	NODE_H

#include <vector>

#include "Figure.h"
#include "CGFappearance.h"

using namespace std;

class Node
{
    
private:
    char* id;
    vector <char*> children_id;
    vector <Node*> children;
    vector <Figure*> primitives;
    int transf_matrix[4][4];
    CGFappearance* appearance;

public:
    Node();
    Node(char* node_id);
    char* getID();
    void addChild(Node* child);
    void addChildID(char* id);
    int getNumberOfChildren();
    void setAppearance(CGFappearance* appearance);
    bool seekNonExistentChildren();
    Node* getChildByID(char* id);

};

#endif	/* NODE_H */