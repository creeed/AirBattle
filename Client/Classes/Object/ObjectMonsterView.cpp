#include "ObjectMonsterView.h"
#include "Object.h"
#include "ObjectMonster.h"

#include "GameMap.h"
#include "GameMapView.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_Monster_View::Object_Monster_View(XObject *object)
	:Object_View(object)
{
	
}

Object_Monster_View::~Object_Monster_View()
{
}

Object_Monster_View * Object_Monster_View::create(XObject *obj)
{
	Object_Monster_View *view = new Object_Monster_View(obj);

	if (view && view->init())
	{
		view->autorelease();
		return view;
	}

	return NULL;
}

bool Object_Monster_View::init()
{
	if (!Object_View::init())
		return false;

	int move_type = ((Object_Monster*)object_)->move_type_;

	if (move_type == 0)
	{
		spr_obj_ = Sprite::create("enemy1-sheet0.png");
		addChild(spr_obj_);
	}
	else if (move_type == 1)
	{
		spr_obj_ = Sprite::create("enemy3-sheet0.png");
		addChild(spr_obj_);
	}
	else if (move_type == 2)
	{
		spr_obj_ = Sprite::create("enemy4-sheet0.png");
		addChild(spr_obj_);
	}
	else if (move_type == 3)
	{
		spr_obj_ = Sprite::create("enemy5-sheet0.png");
		addChild(spr_obj_);
	}



	return true;
}

float Object_Monster_View::get_width() const
{
	return spr_obj_->getContentSize().width;
}

float Object_Monster_View::get_height() const
{
	return spr_obj_->getContentSize().height;
}

void Object_Monster_View::draw_gold()
{
	Sprite *spr = Sprite::create("score100-sheet0.png");
	spr->setPosition(getPosition());
	Game_Map::singleton()->get_view()->get_map_layer(LAYER_ORDER_OBJECT)->addChild(spr);

	//Action *act = Squen

	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////