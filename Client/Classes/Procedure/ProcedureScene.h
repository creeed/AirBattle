#ifndef __PROCEDURE_SCENE_H__
#define __PROCEDURE_SCENE_H__

#include "Prereqs.h"

class Procedure_Scene : public Layer
{
public:
    virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	virtual void update(float dt);



};

#endif // 
