#include "ProcedureScene.h"
#include "Procedure.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;


bool Procedure_Scene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}

void Procedure_Scene::onEnter()
{
	Layer::onEnter();

}

void Procedure_Scene::onExit()
{
	Layer::onExit();

}

void Procedure_Scene::update(float dt)
{
	Procedure::tick_active(dt);
}
