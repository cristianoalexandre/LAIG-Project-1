#include "XMLScene.h"

void XMLScene::singleElementAttributeParser(SceneValues &val, TiXmlElement* elem)
{

    char* name = (char*) elem->Value();
    printf("\nParsing %s element:\n\n", name);

    printf("Parsing attributes:\n");
    TiXmlAttribute* attr = elem->FirstAttribute();
    while (attr != NULL)
    {

        char* tmp = (char*) attr->Value();
        char* attrName = (char*) attr->Name();

        val.addValues(name, attrName, tmp);
        printf("Attribute %s = %s\n", attrName, tmp);
        attr = attr->Next();
    }
}

void XMLScene::parsingCycle(TiXmlElement* elem, SceneValues &val)
{

    singleElementAttributeParser(val, elem);

    TiXmlElement* child = elem->FirstChildElement();
    if (child == NULL)
    {
        printf("no more children\n\n-------------------------------------------------\n\n");
        return;
    }
    else
    {
        while (child != NULL)
        {
            parsingCycle(child, val);
            child = child->NextSiblingElement();
        }
    }
    return;

}

void XMLScene::nodeAttributeParser(char* name, TiXmlElement* elem, Node* no)
{

    printf("Parsing attributes:\n");
    TiXmlAttribute* attr = elem->FirstAttribute();
    while (attr != NULL)
    {

        char* tmp = (char*) attr->Value();
        char* attrName = (char*) attr->Name();

        if (string(attrName) != "appearanceref" && string(attrName) != "noderef")
        {
            no->addValues(name, attrName, tmp);
        }

        printf("Attribute %s = %s\n", attrName, tmp);
        attr = attr->Next();
    }
}

void XMLScene::parsingNodesCycle(TiXmlElement* elem, Node* node)
{

    char* name = (char*) elem->Value();
    printf("\nParsing %s element:\n\n", name);

    TiXmlElement* child = elem->FirstChildElement();


    if (string(name) == "node")
    {

        node = new Node();
        nodeAttributeParser(name, elem, node);
        while (child != NULL)
        {
            parsingNodesCycle(child, node);
            child = child->NextSiblingElement();
        }
        this->sGraph.addNode(node);
    }
    else
    {

        nodeAttributeParser(name, elem, node);

        if (child == NULL)
        {
            printf("no more children\n\n--------------------------------------------------\n\n");
            printf("\nEnded Parsing %s element:\n\n", name);
            return;
        }
        else
        {
            while (child != NULL)
            {
                parsingNodesCycle(child, node);
                child = child->NextSiblingElement();
            }
        }
    }
    printf("\n Ended Parsing %s element:\n\n", name);
    return;
}

void XMLScene::applyRefs(TiXmlElement* elem)
{

    char* name = (char*) elem->Value();

    if (string(name) == "noderef")
    {

        char* parentName = NULL;
        TiXmlNode* e1, *e2;

        e1 = elem->Parent();
        while (1)
        {
            e2 = e1->Parent();
            parentName = (char*) e1->Value();

            if (!strcmp(parentName, "node"))
            {

                char* idParent;
                char* idChild;
                TiXmlElement* tmpElem;

                tmpElem = e1->ToElement();
                idParent = (char*) tmpElem->Attribute("id");
                idChild = (char*) elem->FirstAttribute()->Value();

                this->sGraph.getNodeById(string(idParent))->addChild(this->sGraph.getNodeById(string(idChild)));

                break;
            }
            else
            {
                e1 = e2;
            }
        }
    }


    TiXmlElement* child = elem->FirstChildElement();
    if (child == NULL)
    {
        return;
    }
    else
    {
        while (child != NULL)
        {
            applyRefs(child);
            child = child->NextSiblingElement();
        }
    }
    return;
}

void XMLScene::initParser(TiXmlElement* elem)
{

    set<TiXmlElement*>::iterator it;

    it = this->elements.find(elem);

    if (it != this->elements.end())
    {
        if (*it == this->globalsElement)
        {
            GlobalValues val;
            parsingCycle(elem, val);
            this->gv = val;
        }
        else
        {
            if (*it == this->camerasElement)
            {
                CameraValues val;
                parsingCycle(elem, val);
                this->cv = val;
            }
            else
            {
                if (*it == this->lightningElement)
                {
                    LightValues val;
                    parsingCycle(elem, val);
                    this->lv = val;
                }
                else
                {
                    if (*it == this->appearancesElement)
                    {
                        AppearanceValues val;
                        parsingCycle(elem, val);
                        this->av = val;
                    }
                    else
                    {
                        if (*it == this->graphElement)
                        { // parsing cycle not yet fully implemented for this type of TiXmlElement
                            Node* no = NULL;
                            parsingNodesCycle(elem, no); //for now, only for compliling and debugging purposes
                        }
                    }
                }
            }
        }
    }
    else
    {
        printf("Element %s not found\n", (char*) elem->Value());
    }
}

XMLScene::XMLScene(char *filename)
{
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
    lightningElement = lsfElement->FirstChildElement("lighting");
    appearancesElement = lsfElement->FirstChildElement("appearances");
    leavesElement = lsfElement->FirstChildElement("leaves");
    nodesElement = lsfElement->FirstChildElement("nodes");
    graphElement = lsfElement->FirstChildElement("graph");

    this->elements.insert(globalsElement);
    this->elements.insert(camerasElement);
    this->elements.insert(lightningElement);
    this->elements.insert(appearancesElement);
    this->elements.insert(graphElement);
    this->elements.insert(nodesElement);
    this->elements.insert(leavesElement);

    this->init();

    if (globalsElement == NULL)
    {
        printf("Globals block not found!\n");
    }
    else
    {
        initParser(globalsElement);
    }

    if (lightningElement == NULL)
    {
        printf("lighting block not found\n");
    }
    else
    {
        initParser(lightningElement);
    }

    /*
    if (camerasElement == NULL) {
    printf("cameras block not found\n");
    } else {
    initParser(camerasElement);
    }



    if(appearancesElement == NULL){
    printf("appearances block not found\n");
    }else{
    initParser(appearancesElement);
    }
     */
    if (graphElement == NULL)
        printf("Graph block not found!\n");
    else
    {
        initParser(graphElement);
    }

    printf("\n\nAPPLYING REFERENCES\n\n");
    applyRefs(graphElement);

    this->sGraph.printNodesID();

	printf("///////////////////////////////////\n");
	/*Node* r = this->sGraph.getNodeById("root");

	for(size_t i = 0; i < r->getChildren()->size(); i++){

		cout << r->getChildren()->at(i)->getID() << endl;
	}*/
    cin.get();

}

void XMLScene::display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Inicializacoes da matriz de transformacoes geometricas
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    CGFscene::activeCamera->applyView();

    axis.draw();

    gv.apply();
    //lv.apply();

	
    //this->drawScene(this->sGraph.getNodeById("root"));
	this->drawSceneEXP(this->sGraph.getNodeById("root"));


/*
	if(proc.empty()){
		cout << "QUEUE is empty\n";
	}else{
		cout << "QUEUE is NOT empty\n";
		while(!proc.empty()){
			proc.pop();
		}
		cout << "QUEUE cleaned\n";
	}*/
	//cin.get();
    glutSwapBuffers();
}

/*(void XMLScene::drawScene(Node* root)
{

    glPushMatrix();
    root->draw();
    cin.get();
    if (root->hasChildren())
    {

        vector<Node*>* children = root->getChildren();
        vector<Node*>::iterator it;

        for (it = children->begin(); it != children->end(); it++)
        {

           if((*it)->getAppearance() == NULL){			
            drawScene(*it);

            }else{
            this->nodeInOrderOfProcessing.push(*it);
            }
        }
    }
    
    if(root->getID() == "root"){
    while(!this->nodeInOrderOfProcessing.empty()){
    drawScene(this->nodeInOrderOfProcessing.front());
    nodeInOrderOfProcessing.pop();
    }
    }
    glPopMatrix();
}*/

XMLScene::~XMLScene()
{
    delete(doc);
}


void XMLScene::drawSceneEXP(Node* node, int level){

	if (node->hasChildren())
    {
		this->proc.push(node);
        vector<Node*>* children = node->getChildren();
        vector<Node*>::iterator it;

        for (it = children->begin(); it != children->end(); it++)
        {		

			if((*it)->hasPrimitives()){
				glPushMatrix();
				this->drawFromStack(*it);
				glPopMatrix();
				
			}else{
				drawSceneEXP(*it, level+1);
			}
        }
		this->proc.pop();
    }
	return;
	
}

void XMLScene::drawFromStack(Node* it){

	stack<Node*> applyOrder;

	while(!proc.empty()){
		applyOrder.push(proc.top());
		proc.pop();
	}


	size_t i = 0;
	size_t size = applyOrder.size();
	while(i++ < size){

		glPushMatrix();
		applyOrder.top()->draw();	
		proc.push(applyOrder.top());		
		applyOrder.pop();
	}

	it->draw();
	i = 0;
	while(i++ < size){
		glPopMatrix();
	}
}