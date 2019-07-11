#include "GameScene.h"
#include "GameMap.h"
#include "ObjectPlayerMySelf.h"
#include "GameProcedure.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

using namespace cocostudio::timeline;


Layer* Game_Scene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Game_Scene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return layer;
}


bool Game_Scene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	scheduleUpdate();

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto _mouseListen = EventListenerMouse::create();
	_mouseListen->onMouseDown = [=](Event* event)
	{
		EventMouse* e = (EventMouse*)event;
		if (e->getMouseButton() == 0)
		{
			float cursorX = e->getCursorX();
			float cursorY = e->getCursorY();

			Object_PlayerMySelf *myself = Game_Map::singleton()->get_my_self();

			Rect rect = Rect(myself->get_x() + myself->get_hit_rect().get_pos().x_,
				myself->get_y() + myself->get_hit_rect().get_pos().y_,
				myself->get_hit_rect().get_width(), myself->get_hit_rect().get_height());

			if (rect.containsPoint(Point(cursorX, cursorY)))
			{
				Procedure::game_procedure_->set_mouse_down(true);
				Procedure::game_procedure_->set_mouse_dist(World_Point(cursorX, cursorY) - myself->get_pos());
				Procedure::game_procedure_->set_mouse_pt(World_Point(cursorX, cursorY));
			}
		
		}
	};

	_mouseListen->onMouseMove = [=](Event* event)
	{
		EventMouse* e = (EventMouse*)event;
		if (e->getMouseButton() == 0)
		{
			float cursorX = e->getCursorX();
			float cursorY = e->getCursorY();

			if (Procedure::game_procedure_->get_mouse_down())
			{
				Procedure::game_procedure_->set_mouse_pt(World_Point(cursorX, cursorY));
			}
		}
	};

	_mouseListen->onMouseUp = [=](Event* event)
	{
		EventMouse* e = (EventMouse*)event;
		float cursorX = e->getCursorX();
		float cursorY = e->getCursorY();

		if (Procedure::game_procedure_->get_mouse_down())
		{
			Procedure::game_procedure_->set_mouse_down(false);
			Procedure::game_procedure_->set_mouse_pt(World_Point(cursorX, cursorY));
		}
	};

	auto _eventDispatcher = Director::getInstance()->getEventDispatcher();
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListen, this);


	return true;
}

void Game_Scene::onEnter()
{
	Layer::onEnter();

}

void Game_Scene::onExit()
{
	Layer::onExit();

}

void Game_Scene::update(float dt)
{
	uint32_t udt = dt * 1000;
	Procedure::get_active_proc()->tick(udt);
	
}
