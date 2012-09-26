#include "XMLScene.h"





void queryStringValue(TiXmlElement* elem, string &attr, string &value){
    
    
    if(elem->QueryStringAttribute(attr, value) == TIXML_SUCCESS){
        printf("%s: %s\n", attr, value);
        
    }else{
        
        printf("%s not found\n", attr);
    }
    
}


void queryBoolValue(TiXmlElement* elem, string &attr, bool &value){
    
    string tmp;
    if(elem->QueryStringAttribute(attr, value) == TIXML_SUCCESS){
        
        if(value){
            tmp = "true";
        }else{
            tmp = "false";
        }
        printf("%s: %s\n", attr, tmp);
        
    }else{     
        printf("%s not found\n", attr);
    }
    
}


XMLScene::XMLScene(char *filename)
{

    doc = new TiXmlDocument(filename);
    bool loadOkay = doc->LoadFile();

    if (!loadOkay) {
        printf("Could not load file '%s'. Error='%s'. Exiting.\n", filename, doc->ErrorDesc());
        exit(1);
    }

    TiXmlElement* lsfElement = doc->FirstChildElement("lsf");

    if (lsfElement == NULL) {
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



    if (globalsElement == NULL){
        printf("Globals block not found!\n");
    
    } else {
        printf("Processing Globals:\n");
        
        
        //BACKGROUND
        TiXmlElement* backgroundElement = globalsElement->FirstChildElement("background");      
        if (backgroundElement) {
            float red, green, blue;

            if (backgroundElement->QueryFloatAttribute("r", &red) == TIXML_SUCCESS &&
                    backgroundElement->QueryFloatAttribute("g", &green) == TIXML_SUCCESS &&
                    backgroundElement->QueryFloatAttribute("b", &blue) == TIXML_SUCCESS
                    ){
               printf(" background attributes: %f %f %f\n", red, green, blue);
            }else
               printf("Error parsing background\n");
        } else {
            printf("backgroud not found\n");
        }

        
        //POLYGON
        TiXmlElement* polygonElement = globalsElement->FirstChildElement("polygon");
        if (polygonElement) {
            string strMode, strShading;
            
            queryStringValue(polygonElement,"mode",strMode);
            queryStringValue(polygonElement,"shading",strShading);

        } else {
            printf("Polygon not found\n");
        }
     
        
        //CULLING
        TiXmlElement* cullingElement = globalsElement->FirstChildElement("culling");
        if (cullingElement) {

            string strFFO, cullface;
            bool enabled;
            
    
            queryStringValue(cullingElement,"frontfaceorder", strFFO);
            queryStringValue(cullingElement, "cullface", cullface);
            queryBoolValue(cullingElement, "enabled", enabled);
           
        }else{
            printf("culling not found\n");
        }
    }

    if (camerasElement == NULL) {
        printf("cameras block not found\n");
    } else {
        string camIni;
        queryStringValue(camerasElement, "initial", camIni);
        
        
        
        TiXmlElement* child = NULL;
        while(child = camerasElement->IterateChildren(child)){
            
            string id, near, far, angle;
            queryStringValue(child,"id", id);
            queryStringValue(child,"near", near);
            queryStringValue(child,"far", far);
            queryStringValue(child,"angle", angle);
            
            TiXmlElement* fromElement = child->FirstChildElement("from");
            
            if(fromElement){
                
                int x,y,z;
                
                if (fromElement->QueryIntAttribute("r", &x) == TIXML_SUCCESS &&
                        fromElement->QueryIntAttribute("g", &y) == TIXML_SUCCESS &&
                        fromElement->QueryIntAttribute("b", &z) == TIXML_SUCCESS){
                 printf(" fromElement attributes: %d %d %d\n", x, y, z);
            }else
               printf("Error parsing fromElement\n");
                
            }
            
            
            
        }
    }


    // graph section
    if (graphElement == NULL)
        printf("Graph block not found!\n");
    else {
        char *prefix = "  -";
        TiXmlElement *node = graphElement->FirstChildElement();

        while (node) {
            printf("Node id '%s' - Descendants:\n", node->Attribute("id"));
            TiXmlElement *child = node->FirstChildElement();
            while (child) {
                if (strcmp(child->Value(), "Node") == 0) {
                    // access node data by searching for its id in the nodes section

                    TiXmlElement *noderef = findChildByAttribute(nodesElement, "id", child->Attribute("id"));

                    if (noderef) {
                        // print id
                        printf("  - Node id: '%s'\n", child->Attribute("id"));

                        // prints some of the data
                        printf("    - Material id: '%s' \n", noderef->FirstChildElement("material")->Attribute("id"));
                        printf("    - Texture id: '%s' \n", noderef->FirstChildElement("texture")->Attribute("id"));

                        // repeat for other leaf details
                    } else
                        printf("  - Node id: '%s': NOT FOUND IN THE NODES SECTION\n", child->Attribute("id"));

                }
                if (strcmp(child->Value(), "Leaf") == 0) {
                    // access leaf data by searching for its id in the leaves section
                    TiXmlElement *leaf = findChildByAttribute(leavesElement, "id", child->Attribute("id"));

                    if (leaf) {
                        // it is a leaf and it is present in the leaves section
                        printf("  - Leaf id: '%s' ; type: '%s'\n", child->Attribute("id"), leaf->Attribute("type"));

                        // repeat for other leaf details
                    } else
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




