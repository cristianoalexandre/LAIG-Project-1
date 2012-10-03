
#ifndef NODE_H
#define	NODE_H

#include <vector>

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
    void addChild(Node* child);
    void addChildID(char* id);
    int getNumberOfChildren();
    bool seekNullChildren();
    Node* getChildByID(int id);

};

#endif	/* NODE_H */