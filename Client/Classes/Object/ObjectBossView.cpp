#include "ObjectBossView.h"
#include "Object.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_Boss_View::Object_Boss_View(XObject *object)
	:Object_View(object)
{
	
}

Object_Boss_View::~Object_Boss_View()
{
}

Object_Boss_View * Object_Boss_View::create(XObject *obj)
{
	Object_Boss_View *view = new Object_Boss_View(obj);

	if (view && view->init())
	{
		view->autorelease();
		return view;
	}

	return NULL;
}

bool Object_Boss_View::init()
{
	if (!Object_View::init())
		return false;

	spr_obj_ = Sprite::create("enemy6-sheet0.png");
	addChild(spr_obj_);

	return true;
}

float Object_Boss_View::get_width() const
{
	return spr_obj_->getContentSize().width;
}

float Object_Boss_View::get_height() const
{
	return spr_obj_->getContentSize().height;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////