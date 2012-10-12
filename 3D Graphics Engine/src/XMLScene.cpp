#include "XMLScene.h"


void XMLScene::singleElementAttributeParser(SceneValues val, TiXmlElement* elem){

	char* name = (char*) elem->Value();
	printf("parsing %s element:\n", name);

	printf("parsing attributes:\n");
	TiXmlAttribute* attr = elem->FirstAttribute();
	while(attr != NULL){

		char* tmp = (char*) attr->Value();
		char* attrName = (char*) attr->Name();

		//val.addValues(name, attrName, tmp);
		printf("attribute %s = %s\n", attrName, tmp);
		attr = attr->Next();
	}
}


void XMLScene::parsingCycle(TiXmlElement* elem, SceneValues val){

	singleElementAttributeParser(val, elem);

	TiXmlElement* child = elem->FirstChildElement();
	if(child == NULL){
		printf("no more children\n");
		return;
	}else{
		while(child != NULL){
			parsingCycle(child, val);
			child = child->NextSiblingElement();
		}
	}
	return;

}




void XMLScene::nodeAttributeParser(char* name, TiXmlElement* elem, Node* no){

	printf("parsing attributes:\n");
	TiXmlAttribute* attr = elem->FirstAttribute();
	while(attr != NULL){

		char* tmp = (char*) attr->Value();
		char* attrName = (char*) attr->Name();


		if(string(attrName) != "appearanceref" && string(attrName) != "noderef"){
			no->addValues(name, attrName, tmp);
		}

		printf("attribute %s = %s\n", attrName, tmp);
		attr = attr->Next();
	}
}

void XMLScene::parsingNodesCycle(TiXmlElement* elem, Node* node){

	char* name = (char*) elem->Value();
	printf("parsing %s element:\n", name);

	TiXmlElement* child = elem->FirstChildElement();


	if(string(name) == "node"){

		node = new Node();
		nodeAttributeParser(name, child, node);
		parsingNodesCycle(child, node);
		this->sGraph.addNode(node);
	}

	nodeAttributeParser(name, elem, node);

	if(child == NULL){
		printf("no more children\n");
		return;
	}else{
		while(child != NULL){
			parsingNodesCycle(child, node);
			child = child->NextSiblingElement();
		}
	}
	return;
}


void XMLScene::applyRefs(TiXmlElement* elem){

	char* name = (char*) elem->Value();
	printf("NAME = %s\n", name);


	if(string(name) == "noderef"){

		char* parentName = NULL;
		TiXmlNode* e1, *e2;

		e1 = elem->Parent();
		while(1){

			e2 = e1->Parent();
			parentName = (char*)e1->Value();
			printf("parentName = %s\n", parentName);
			if(!strcmp(parentName, "node")){

				char* idParent;
				char* idChild;
				TiXmlElement* tmpElem;

				tmpElem = e1->ToElement();
				idParent = (char*) tmpElem->Attribute("id");
				idChild = (char*) elem->FirstAttribute()->Value();

				printf("id = %s\nval = %s\n",idParent,idChild);

				//this->sGraph.getNodeById(string(idParent))->addChild(this->sGraph.getNodeById(string(idChild)));
				break;
			}else{
				e1 = e2;
			}
		}
	}


	TiXmlElement* child = elem->FirstChildElement();
	if(child == NULL){
		printf("no more children\n");
		return;
	}else{
		while(child != NULL){
			applyRefs(child);
			child = child->NextSiblingElement();
		}
	}
	return;
}


void XMLScene::initParser(TiXmlElement* elem){

	set<TiXmlElement*>::iterator it;

	it = this->elements.find(elem);

	if(it != this->elements.end()){
		if(*it == this->globalsElement){
			GlobalValues val;
			parsingCycle(elem, val);
			this->gv = val;
		}else{
			if(*it == this->camerasElement){
				CameraValues val;		
				parsingCycle(elem, val);
				this->cv = val;
			}else{
				if(*it == this->lightningElement){
					LightValues val;
					parsingCycle(elem, val);
					this->lv = val;
				}else{
					if(*it == this->appearancesElement){
						AppearanceValues val;
						parsingCycle(elem, val);
						this->av = val;
					}else{
						if(*it == this->graphElement){ // parsing cycle not yet fully implemented for this type of TiXmlElement
							Node* no = NULL;
							parsingNodesCycle(elem, no); //for now, only for compliling and debugging purposes
						}
					}
				}
			}
		}
	}else{
		printf("Element %s not found\n", (char*)elem->Value());
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

	this->elements.insert(globalsElement);
	this->elements.insert(camerasElement);
	this->elements.insert(lightningElement);
	this->elements.insert(appearancesElement);
	this->elements.insert(graphElement);
	this->elements.insert(nodesElement);
	this->elements.insert(leavesElement);

	/*
	if (globalsElement == NULL){
	printf("Globals block not found!\n");
	} else {
	initParser(globalsElement);
	}

	if (camerasElement == NULL) {
	printf("cameras block not found\n");
	} else {
	initParser(camerasElement);
	}

	if(lightningElement == NULL){
	printf("lightning block not found\n");
	}else{
	initParser(lightningElement);
	}

	if(appearancesElement == NULL){
	printf("appearances block not found\n");
	}else{
	initParser(appearancesElement);
	}
	*/
	if (graphElement == NULL)
	printf("Graph block not found!\n");
	else {
	initParser(graphElement);
	}



	applyRefs(graphElement);

	string ola;
	cin >> ola;

}

XMLScene::~XMLScene()
{
	delete(doc);
}
