#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "Prereqs.h"
#include "ProcedureScene.h"

class Game_Scene : public Procedure_Scene
{
public:
    static Layer* createScene();
	CREATE_FUNC(Game_Scene);
    virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	virtual void update(float dt);

public:
	

};

#endif // 
