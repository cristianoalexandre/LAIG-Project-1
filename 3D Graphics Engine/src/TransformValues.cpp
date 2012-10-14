#include "TransformValues.h"

TransformValues::TransformValues()
{

}

void TransformValues::addValues(char* elem, char* attr, char* val)
{
	cout << "ADDING VALUES" << endl;
	string tmp = string(elem);
	if (tmp == "scale")
	{
		addScalingValues(attr, val);
	}
	else
	{
		if (tmp == "rotate")
		{
			addRotationValues(attr, val);
		}
		else
		{
			if (tmp == "translate")
			{
				addTranslationValues(attr, val);
			}
		}
	}

}

void TransformValues::addScalingValues(char* attr, char* val)
{

	string key = string(attr);
	float value = atof(val);

	switch(key[0]){
	case 'x':
		{
			this->scale[0] = atof(val);
			break;
		}
	case 'y':
		{
			this->scale[1] = atof(val);
			break;
		}
	case 'z':
		{
			this->scale[2] = atof(val);

			pair<string,float*> p("scale",this->scale);
			this->order.push_back(p);
			break;
		}
	default:
		{
			printf("ERROR! in Scale Element -> Unrecognized attribute: '%s'\nPress any key to exit\n", attr);
			break;
		}
	}

}

void TransformValues::addRotationValues(char* attr, char* val)
{
	string key = string(attr);
	string value = string(val);

	if(key == "axis"){
		switch(value[0]){
		case 'x':
			{
				this->rotate[1] = 1;
				this->rotate[2] = 0;
				this->rotate[3] = 0;
				break;
			}
		case 'y':
			{
				this->rotate[1] = 0;
				this->rotate[2] = 1;
				this->rotate[3] = 0;
				break;
			}
		case 'z':
			{
				this->rotate[1] = 0;
				this->rotate[2] = 0;
				this->rotate[3] = 1;
				break;
			}
		default:
			{
				printf("ERROR! in Rotate Element -> Unrecognized axis value: '%s'\nPress any key to exit\n", val);
				break;
			}
		}
	}else{
		if(key == "angle"){

			this->rotate[0] = atof(val);
			pair<string,float*> p("rotation",this->rotate);
			this->order.push_back(p);
		}else{
			printf("ERROR! in Rotate Element -> Unrecognized attribute: '%s'\nPress any key to exit\n", attr);
		}

	}
}

void TransformValues::addTranslationValues(char* attr, char* val)
{
	string key = string(attr);
	float value = atof(val);

	switch(key[0]){
	case 'x':
		{
			this->translate[0] = atof(val);
			break;
		}
	case 'y':
		{
			this->translate[1] = atof(val);
			break;
		}
	case 'z':
		{
			this->translate[2] = atof(val);
			pair<string,float*> p("translation",this->translate);
			this->order.push_back(p);
			break;
		}
	default:
		{
			printf("ERROR! in Translation Element -> Unrecognized attribute: '%s'\nPress any key to exit\n", attr);
			break;
		}
	}
}

void TransformValues::apply()
{
	
	
	//cout << this->order[0].first << endl;
	for(size_t i = 0; i < this->order.size(); i++){

		string type = this->order[i].first;

		if(type == "scale"){
			glScalef(this->scale[0], this->scale[1], this->scale[2]);
		}
		if(type == "translation"){
			glTranslatef(this->translate[0], this->translate[1], this->translate[2]);
		}
		if(type == "rotation"){
			glRotatef(this->rotate[0], this->rotate[1], this->rotate[2], this->rotate[3]);		
		}
		
		
	}
}