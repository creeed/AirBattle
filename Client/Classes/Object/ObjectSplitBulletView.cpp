#include "ObjectSplitBulletView.h"
#include "Object.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_Split_Bullet_View::Object_Split_Bullet_View(XObject *object)
	:Object_View(object)
{
	
}

Object_Split_Bullet_View::~Object_Split_Bullet_View()
{
}

Object_Split_Bullet_View * Object_Split_Bullet_View::create(XObject *obj)
{
	Object_Split_Bullet_View *view = new Object_Split_Bullet_View(obj);

	if (view && view->init())
	{
		view->autorelease();
		return view;
	}

	return NULL;
}

bool Object_Split_Bullet_View::init()
{
	Sprite *spr = Sprite::create("bullet0.png");
	addChild(spr);

	//Node *model = CSLoader::createNode("Bullet.csb");
	//ActionTimeline *action = CSLoader::createTimeline("Bullet.csb");
	//model->runAction(action);
	//addChild(model);
	//model->setPosition(Vec2(0, 0));
	//action->play("animation0", true);

	return true;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////