#ifndef SCENEVALUES_H
#define	SCENEVALUES_H


class SceneValues
{
public:
    SceneValues();
    virtual ~SceneValues();

    virtual void apply();
    virtual void addValues(char* element, char* attribute, char* value);
};

#endif	/* SCENEVALUES_H */