#include "ObjectDirectionalBullet.h"
#include "ObjectDirectionalBulletView.h"
#include "GameMap.h"
#include "GameMapView.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_Directional_Bullet::Object_Directional_Bullet()
{
	theta_ = 0.0f;
	speed_ = 0.0f;
}

Object_Directional_Bullet::~Object_Directional_Bullet()
{
}

bool Object_Directional_Bullet::initialise(const Object_Init *init)
{
	if (!Object_Monster_Bullet::initialise(init))
		return false;

	Object_Directional_Bullet_Init *pinit = (Object_Directional_Bullet_Init *)init;

	theta_ = pinit->theta_;
	speed_ = pinit->speed_;

	vx_ = cos(theta_) * speed_;
	vy_ = sin(theta_) * speed_;

	view_ = Object_Directional_Bullet_View::create(this);
	Game_Map::singleton()->get_view()->get_map_layer(LAYER_ORDER_OBJECT)->addChild(view_);

	hit_rect_.set_rect(-70, -57, 70, 57);

	return true;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
