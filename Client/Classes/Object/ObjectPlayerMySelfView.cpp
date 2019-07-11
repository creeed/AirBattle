#include "ObjectPlayerMySelfView.h"
#include "Object.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_PlayerMySelf_View::Object_PlayerMySelf_View(XObject *object)
	:Object_View(object)
{
	
}

Object_PlayerMySelf_View::~Object_PlayerMySelf_View()
{
}

Object_PlayerMySelf_View * Object_PlayerMySelf_View::create(XObject *obj)
{
	Object_PlayerMySelf_View *view = new Object_PlayerMySelf_View(obj);

	if (view && view->init())
	{
		view->autorelease();
		return view;
	}

	return NULL;
}

bool Object_PlayerMySelf_View::init()
{
	if (!Object_View::init())
		return false;

	spr_obj_ = Sprite::create("player-sheet0.png");
	addChild(spr_obj_);

	return true;
}

float Object_PlayerMySelf_View::get_width() const
{
	return spr_obj_->getContentSize().width;
}

float Object_PlayerMySelf_View::get_height() const
{
	return spr_obj_->getContentSize().height;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////