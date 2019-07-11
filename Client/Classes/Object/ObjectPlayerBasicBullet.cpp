#include "ObjectPlayerBasicBullet.h"
#include "ObjectPlayerBasicBulletView.h"

#include "GameMap.h"
#include "GameMapView.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_Player_Basic_Bullet::Object_Player_Basic_Bullet()
{
}

Object_Player_Basic_Bullet::~Object_Player_Basic_Bullet()
{
}

bool Object_Player_Basic_Bullet::initialise(const Object_Init *init)
{
	if (!Object_Player_Bullet::initialise(init))
		return false;

	Object_Player_Basic_Bullet_Init *pinit = (Object_Player_Basic_Bullet_Init *)init;

	view_ = Object_Player_Basic_Bullet_View::create(this);
	Game_Map::singleton()->get_view()->get_map_layer(LAYER_ORDER_OBJECT)->addChild(view_);

	hit_rect_.set_rect(-70, -57, 70, 57);

	return true;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
