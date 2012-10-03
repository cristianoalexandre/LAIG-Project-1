#include "XMLScene.h"

#include <iostream>
#include <vector>

void parsingCycle(TiXmlElement* elem)
{

    TiXmlElement* child = elem->FirstChildElement();
    if (child == NULL)
    {
        printf("no more children\n");
        return;
    }

    while (child != NULL)
    {

        char* name = (char*) child->Value();
        printf("parsing %s element:\n", name);

        TiXmlAttribute* attr = child->FirstAttribute();
        while (attr != NULL)
        {

            char* tmp = (char*) attr->Value();
            char* attrName = (char*) attr->Name();
            printf("attribute %s = %s\n", attrName, tmp);
            attr = attr->Next();
        }

        parsingCycle(child);
        child = child->NextSiblingElement();
    }
    return;
}

void queryStringValue(TiXmlElement* elem, char* attr, char* value)
{

    value = NULL;
    value = (char*) elem->Attribute(attr);

    if (value != NULL)
    {
        printf("%s: %s\n", attr, value);

    }
    else
    {
        printf("%s not found\n", attr);
    }

}

void queryBoolValue(TiXmlElement* elem, char* attr, bool* value)
{

    char* tmp = NULL;
    tmp = (char*) elem->Attribute(attr);

    if (tmp != NULL)
    {
        if (tmp == "true")
        {
            *value = true;
        }
        else
        {
            *value = false;
        }

        printf("%s: %s\n", attr, tmp);

    }
    else
    {
        printf("%s not found\n", attr);
    }

}

XMLScene::XMLScene(char *filename)
{

    vector<char*> attributes;
    vector<char*> names;

    doc = new TiXmlDocument(filename);
    bool loadOkay = doc->LoadFile();

    if (!loadOkay)
    {
        printf("Could not load file '%s'. Error='%s'. Exiting.\n", filename, doc->ErrorDesc());
        exit(1);
    }

    TiXmlElement* lsfElement = doc->FirstChildElement("lsf");

    if (lsfElement == NULL)
    {
        printf("Main lsf block element not found! Exiting!\n");
        exit(1);
    }

    globalsElement = lsfElement->FirstChildElement("globals");
    camerasElement = lsfElement->FirstChildElement("cameras");
    lightningElement = lsfElement->FirstChildElement("lightning");
    appearancesElement = lsfElement->FirstChildElement("appearances");
    leavesElement = lsfElement->FirstChildElement("leaves");
    nodesElement = lsfElement->FirstChildElement("nodes");
    graphElement = lsfElement->FirstChildElement("graph");



    if (globalsElement == NULL)
    {
        printf("Globals block not found!\n");

    }
    else
    {
        printf("Processing Globals:\n");

        parsingCycle(globalsElement);
    }

    if (camerasElement == NULL)
    {
        printf("cameras block not found\n");
    }
    else
    {
        char* camIni;
        queryStringValue(camerasElement, "initial", camIni);


        parsingCycle(camerasElement);
    }

    if (lightningElement == NULL)
    {
        printf("lightning block not found\n");
    }
    else
    {
        bool doublesided, local, enabled;

        queryBoolValue(lightningElement, "doublesided", &doublesided);
        queryBoolValue(lightningElement, "local", &local);
        queryBoolValue(lightningElement, "enabled", &enabled);

        parsingCycle(lightningElement);
    }

    if (appearancesElement == NULL)
    {
        printf("appearances block not found\n");
    }
    else
    {
        parsingCycle(appearancesElement);
    }


    // graph section
    if (graphElement == NULL)
        printf("Graph block not found!\n");
    else
    {
        char *prefix = "  -";
        TiXmlElement *node = graphElement->FirstChildElement();

        while (node)
        {
            printf("Node id '%s' - Descendants:\n", node->Attribute("id"));
            TiXmlElement *child = node->FirstChildElement();
            while (child)
            {
                if (strcmp(child->Value(), "Node") == 0)
                {
                    // access node data by searching for its id in the nodes section

                    TiXmlElement *noderef = findChildByAttribute(nodesElement, "id", child->Attribute("id"));

                    if (noderef)
                    {
                        // print id
                        printf("  - Node id: '%s'\n", child->Attribute("id"));

                        // prints some of the data
                        printf("    - Material id: '%s' \n", noderef->FirstChildElement("material")->Attribute("id"));
                        printf("    - Texture id: '%s' \n", noderef->FirstChildElement("texture")->Attribute("id"));

                        // repeat for other leaf details
                    }
                    else
                        printf("  - Node id: '%s': NOT FOUND IN THE NODES SECTION\n", child->Attribute("id"));

                }
                if (strcmp(child->Value(), "Leaf") == 0)
                {
                    // access leaf data by searching for its id in the leaves section
                    TiXmlElement *leaf = findChildByAttribute(leavesElement, "id", child->Attribute("id"));

                    if (leaf)
                    {
                        // it is a leaf and it is present in the leaves section
                        printf("  - Leaf id: '%s' ; type: '%s'\n", child->Attribute("id"), leaf->Attribute("type"));

                        // repeat for other leaf details
                    }
                    else
                        printf("  - Leaf id: '%s' - NOT FOUND IN THE LEAVES SECTION\n", child->Attribute("id"));
                }

                child = child->NextSiblingElement();
            }
            node = node->NextSiblingElement();
        }
    }

}

XMLScene::~XMLScene()
{
    delete(doc);
}

//-------------------------------------------------------

TiXmlElement *XMLScene::findChildByAttribute(TiXmlElement *parent, const char * attr, const char *val)
// Searches within descendants of a parent for a node that has an attribute _attr_ (e.g. an id) with the value _val_
// A more elaborate version of this would rely on XPath expressions
{
    TiXmlElement *child = parent->FirstChildElement();
    int found = 0;

    while (child && !found)
        if (child->Attribute(attr) && strcmp(child->Attribute(attr), val) == 0)
            found = 1;
        else
            child = child->NextSiblingElement();

    return child;
}