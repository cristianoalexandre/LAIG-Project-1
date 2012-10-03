#include <string.h>
#include <stdlib.h>

#include "Node.h"

Node::Node()
{
    id = (char*) "not defined";
    appearance = NULL;
}

Node::Node(char* node_id)
{
    id = node_id;
    appearance = NULL;
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
    for (vector <Node*>::iterator it = children.begin(); it != children.end(); it++)
    {
        if (!strcmp((*it)->getID(), id))
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

char* Node::getID()
{
    return id;
}
