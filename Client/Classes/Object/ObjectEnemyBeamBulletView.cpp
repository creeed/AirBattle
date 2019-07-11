#include "ObjectEnemyBeamBulletView.h"
#include "Object.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_Enemy_Beam_Bullet_View::Object_Enemy_Beam_Bullet_View(XObject *object)
	:Object_View(object)
{
	
}

Object_Enemy_Beam_Bullet_View::~Object_Enemy_Beam_Bullet_View()
{
}

Object_Enemy_Beam_Bullet_View * Object_Enemy_Beam_Bullet_View::create(XObject *obj)
{
	Object_Enemy_Beam_Bullet_View *view = new Object_Enemy_Beam_Bullet_View(obj);

	if (view && view->init())
	{
		view->autorelease();
		return view;
	}

	return NULL;
}

bool Object_Enemy_Beam_Bullet_View::init()
{
	Sprite *spr = Sprite::create("bullet1.png");
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