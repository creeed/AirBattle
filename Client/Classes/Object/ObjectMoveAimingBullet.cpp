#include "ObjectMoveAimingBullet.h"
#include "ObjectMoveAimingBulletView.h"
#include "GameMap.h"
#include "GameMapView.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_Move_Aiming_Bullet::Object_Move_Aiming_Bullet()
{
	speed_ = 0.0f;
}

Object_Move_Aiming_Bullet::~Object_Move_Aiming_Bullet()
{
}

bool Object_Move_Aiming_Bullet::initialise(const Object_Init *init)
{
	if (!Object_Monster_Bullet::initialise(init))
		return false;

	Object_Move_Aiming_Bullet_Init *pinit = (Object_Move_Aiming_Bullet_Init *)init;

	speed_ = pinit->speed_;

	float x_enemy = get_x();
	float y_enemy = get_y();

	float x_player = pinit->player_->get_x();
	float y_player = pinit->player_->get_y();

	float distance = sqrt((x_player - x_enemy) * (x_player - x_enemy)
		+ (y_player - y_enemy) * (y_player - y_enemy));

	if (distance != 0.0f) 
	{
		vx_ = ((x_player - x_enemy) / distance) * speed_;
		vy_ = ((y_player - y_enemy) / distance) * speed_;
	}
	else
	{
		vx_ = 0.0f;
		vy_ = -speed_;
	}

	view_ = Object_Move_Aiming_Bullet_View::create(this);
	Game_Map::singleton()->get_view()->get_map_layer(LAYER_ORDER_OBJECT)->addChild(view_);

	hit_rect_.set_rect(-70, -57, 70, 57);

	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
