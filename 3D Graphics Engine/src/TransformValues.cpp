#include "TransformValues.h"

TransformValues::TransformValues()
{

}

void TransformValues::addValues(char* elem, char* attr, char* val)
{

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
    pair<string, float> pair(key, value);

    this->scale.insert(pair);
}

void TransformValues::addRotationValues(char* attr, char* val)
{

    string key = string(attr);
	string value = string(val);

	if(key == "axis"){
		pair<string,float> x;
		pair<string,float> y;
		pair<string,float> z;
		switch(val[0]){
			case 'x':
			{
				x.first = "x";
				x.second = 1;
				y.first = "y";
				y.second = 0;
				z.first = "z";
				z.second = 0;
				this->rotate.insert(x);
				this->rotate.insert(y);
				this->rotate.insert(z);
				break;
			}
			case 'y':
			{
				x.first = "x";
				x.second = 0;
				y.first = "y";
				y.second = 1;
				z.first = "z";
				z.second = 0;
				this->rotate.insert(x);
				this->rotate.insert(y);
				this->rotate.insert(z);
				break;
			}
			case 'z':
			{
				x.first = "x";
				x.second = 0;
				y.first = "y";
				y.second = 0;
				z.first = "z";
				z.second = 1;
				this->rotate.insert(x);
				this->rotate.insert(y);
				this->rotate.insert(z);
				break;
			}
			default:
			{
				printf("ERROR! in Rotate Element -> Unrecognized axis attribute: '%s'\nPress any key to exit\n", val);
				break;
			}
		}
	}else{
		if(key == "angle"){

			pair<string,float> p(key, atof(val));
			this->rotate.insert(p);
		}else{
			printf("ERROR! in Rotate Element -> unrecognized attribute name: '%s'\nPress any key to exit\n", attr);
		}
	}
}

void TransformValues::addTranslationValues(char* attr, char* val)
{

    string key = string(attr);
    float value = atof(val);
    pair<string, float> pair(key, value);

    this->translate.insert(pair);
}

void TransformValues::apply()
{
		if(!this->scale.empty()){
			glScalef(this->scale["x"], this->scale["y"], this->scale["z"]);
		}
		if(!this->translate.empty()){
			glTranslatef(this->translate["x"], this->translate["y"], this->translate["<"]);
		}
		if(!this->rotate.empty()){
			glRotatef(this->rotate["angle"], this->rotate["x"], this->rotate["y"], this->rotate["z"]);
		}
}