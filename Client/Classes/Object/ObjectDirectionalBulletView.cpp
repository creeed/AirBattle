#include "ObjectDirectionalBulletView.h"
#include "Object.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_Directional_Bullet_View::Object_Directional_Bullet_View(XObject *object)
	:Object_View(object)
{
	
}

Object_Directional_Bullet_View::~Object_Directional_Bullet_View()
{
}

Object_Directional_Bullet_View * Object_Directional_Bullet_View::create(XObject *obj)
{
	Object_Directional_Bullet_View *view = new Object_Directional_Bullet_View(obj);

	if (view && view->init())
	{
		view->autorelease();
		return view;
	}

	return NULL;
}

bool Object_Directional_Bullet_View::init()
{
	if (!Object_View::init())
		return false;

	spr_obj_ = Sprite::create("bullet2.png");
	addChild(spr_obj_);

	//Node *model = CSLoader::createNode("Bullet.csb");
	//ActionTimeline *action = CSLoader::createTimeline("Bullet.csb");
	//model->runAction(action);
	//addChild(model);
	//model->setPosition(Vec2(0, 0));
	//action->play("animation0", true);

	return true;
}

float Object_Directional_Bullet_View::get_width() const
{
	return spr_obj_->getContentSize().width;
}

float Object_Directional_Bullet_View::get_height() const
{
	return spr_obj_->getContentSize().height;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////