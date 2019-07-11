#include "ObjectMonsterThreeView.h"
#include "Object.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_Monster_Three_View::Object_Monster_Three_View(XObject *object)
	:Object_View(object)
{
	
}

Object_Monster_Three_View::~Object_Monster_Three_View()
{
}

Object_Monster_Three_View * Object_Monster_Three_View::create(XObject *obj)
{
	Object_Monster_Three_View *view = new Object_Monster_Three_View(obj);

	if (view && view->init())
	{
		view->autorelease();
		return view;
	}

	return NULL;
}

bool Object_Monster_Three_View::init()
{
	Sprite *spr = Sprite::create("enemy1menu-sheet0.png");
	addChild(spr);

	return true;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////