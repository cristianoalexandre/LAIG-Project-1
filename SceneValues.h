#ifndef SCENEVALUES_H
#define	SCENEVALUES_H

class SceneValues
{
public:
    SceneValues();
    virtual ~SceneValues();

    virtual void apply() = 0;
};

#endif	/* SCENEVALUES_H */

