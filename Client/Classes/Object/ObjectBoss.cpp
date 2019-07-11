#include "ObjectBoss.h"
#include "ObjectBossView.h"
#include "ObjectMoveAimingBullet.h"
#include "ObjectDirectionalBullet.h"
#include "GameMap.h"
#include "GameMapView.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_Boss::Object_Boss()
{
	move_type_ = 0;
	bullet_type_ = 0;
}

Object_Boss::~Object_Boss()
{
}

bool Object_Boss::initialise(const Object_Init *init)
{
	if (!Object_Character::initialise(init))
		return false;

	Object_Boss_Init *pinit = (Object_Boss_Init *)init;

	move_type_ = pinit->move_type_;
	bullet_type_ = pinit->bullet_type_;

	view_ = Object_Boss_View::create(this);
	Game_Map::singleton()->get_view()->get_map_layer(LAYER_ORDER_OBJECT)->addChild(view_);

	hit_rect_.set_rect(-100, -100, 100, 100);


	return true;
}

void Object_Boss::cleanup()
{
	Object_Monster::cleanup();
}

bool Object_Boss::heartbeat(uint32_t udt)
{
	bool ret = Object_Character::heartbeat(udt);
	if (!ret)
	{
		return false;
	}

	if (move_counter_ < 150)
	{
		vx_ = 0.0f;
		vy_ = -2.0f;
	}
	else if (move_counter_ == 150)
	{
		vx_ = 1.3f;
		vy_ = 0.0f;
	}
		
	else if (move_counter_ > 150)
	{
		if (x_ > WINDOW_WIDTH - 250.0f)
			vx_ = -vx_;
		if (x_ < 0.0f + 250.0f)
			vx_ = -vx_;
	}
	
	if (butllet_counter_ > 0)
		butllet_counter_--;

	if (move_counter_ % 2000 < 500)
	{
		if (butllet_counter_ <= 0 && move_counter_ % 2000 > 100)
		{
			float rad = 0.0f;
			float rad_step = 6.2831853071795862f / 24.0f;

			for (int i = 0; i < 24; i++)
			{
				Object_Directional_Bullet_Init bullet_init;
				Object_Directional_Bullet *bullet = (Object_Directional_Bullet *)Game_Map::singleton()->new_object(OBJECT_CLASS_TYPE_DIRECTIONALBULLET);

				bullet_init.x_ = get_x();
				bullet_init.y_ = get_y();
				bullet_init.speed_ = 6.0f;
				bullet_init.theta_ = rad;
				bullet->initialise(&bullet_init);

				rad += rad_step;
			}

			butllet_counter_ = 80;
		}
	}
	else if (move_counter_ % 2000 < 1000)
	{
		if (butllet_counter_ <= 0 && move_counter_ % 2000 > 600)
		{
			Object_Move_Aiming_Bullet *bullet = 0;
			Object_Move_Aiming_Bullet_Init bullet_init;

			bullet = (Object_Move_Aiming_Bullet *)Game_Map::singleton()->new_object(OBJECT_CLASS_TYPE_MOVEAIMINGBULLET);
			bullet_init.player_ = (XObject*)Game_Map::singleton()->get_my_self();
			bullet_init.x_ = get_x() - 60.0f;
			bullet_init.y_ = get_y();
			bullet_init.speed_ = 10.0f;
			bullet_init.attack_ = get_attack();
			bullet->initialise(&bullet_init);

			bullet = (Object_Move_Aiming_Bullet *)Game_Map::singleton()->new_object(OBJECT_CLASS_TYPE_MOVEAIMINGBULLET);
			bullet_init.player_ = (XObject*)Game_Map::singleton()->get_my_self();
			bullet_init.x_ = get_x() + 60.0f;
			bullet_init.y_ = get_y();
			bullet_init.speed_ = 10.0f;
			bullet_init.attack_ = get_attack();
			bullet->initialise(&bullet_init);

			butllet_counter_ = 60;
		}
	}
	else if (move_counter_ % 2000 < 1500 && butllet_counter_ <= 0)
	{
		Object_Move_Aiming_Bullet *bullet = 0;
		Object_Move_Aiming_Bullet_Init bullet_init;

		bullet = (Object_Move_Aiming_Bullet *)Game_Map::singleton()->new_object(OBJECT_CLASS_TYPE_MOVEAIMINGBULLET);
		bullet_init.player_ = (XObject*)Game_Map::singleton()->get_my_self();
		bullet_init.x_ = get_x() - 100.0f;
		bullet_init.y_ = get_y();
		bullet_init.speed_ = 10.0f;
		bullet_init.attack_ = get_attack();
		bullet->initialise(&bullet_init);

		bullet = (Object_Move_Aiming_Bullet *)Game_Map::singleton()->new_object(OBJECT_CLASS_TYPE_MOVEAIMINGBULLET);
		bullet_init.player_ = (XObject*)Game_Map::singleton()->get_my_self();
		bullet_init.x_ = get_x();
		bullet_init.y_ = get_y();
		bullet_init.speed_ = 10.0f;
		bullet_init.attack_ = get_attack();
		bullet->initialise(&bullet_init);

		bullet = (Object_Move_Aiming_Bullet *)Game_Map::singleton()->new_object(OBJECT_CLASS_TYPE_MOVEAIMINGBULLET);
		bullet_init.player_ = (XObject*)Game_Map::singleton()->get_my_self();
		bullet_init.x_ = get_x() + 100.0f;
		bullet_init.y_ = get_y();
		bullet_init.speed_ = 10.0f;
		bullet_init.attack_ = get_attack();
		bullet->initialise(&bullet_init);

		butllet_counter_ = 80;

	}
	else if (move_counter_ % 2000 > 1600 && butllet_counter_ <= 0)
	{
		float rad = 0.0f;
		float rad_step = 6.2831853071795862f / 24.0f;

		for (int i = 0; i < 24; i++) 
		{
			Object_Directional_Bullet_Init bullet_init;
			Object_Directional_Bullet *bullet = (Object_Directional_Bullet *)Game_Map::singleton()->new_object(OBJECT_CLASS_TYPE_DIRECTIONALBULLET);

			bullet_init.x_ = get_x();
			bullet_init.y_ = get_y();
			bullet_init.speed_ = 10.0f;
			bullet_init.theta_ = rad;
			bullet_init.attack_ = get_attack();
			bullet->initialise(&bullet_init);

			rad += rad_step;
		}

		butllet_counter_ = 100;
	}

	move_counter_++;

	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////