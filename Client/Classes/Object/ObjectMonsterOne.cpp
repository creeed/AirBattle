#include "ObjectMonsterOne.h"
#include "ObjectMonsterOneView.h"
#include "GameMap.h"
#include "GameMapView.h"
#include "ObjectMoveAimingBullet.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_Monster_One::Object_Monster_One()
{

}

Object_Monster_One::~Object_Monster_One()
{
}

bool Object_Monster_One::initialise(const Object_Init *init)
{
	if (!Object_Monster::initialise(init))
		return false;

	view_ = Object_Monster_One_View::create(this);
	Game_Map::singleton()->get_view()->get_map_layer(LAYER_ORDER_OBJECT)->addChild(view_);

	hit_rect_.set_rect(-100, -100, 100, 100);

	return true;
}

void Object_Monster_One::cleanup()
{
	Object_Monster::cleanup();
}

bool Object_Monster_One::heartbeat(uint32_t udt)
{
	bool ret = Object_Monster::heartbeat(udt);
	if (!ret)
	{
		return false;
	}

	if (move_type_ == 0)
	{
		vy_ = -6.0f;
	}

	else if (move_type_ == 1)
	{
		vx_ = sin((3.1415926535897931f * move_counter_) / 40.0f) * 5.0f;
		vy_ = -6.0f;
	}
	else if (move_type_ == 2)
	{
		if (move_type_ < 50)
			vy_ = -6.0f;

		else if (move_counter_ >= 100)
		{
			vx_ = sin((3.1415926535897931f * (move_counter_ - 100.0f)) / 160.0f) * 2.5f;
			vy_ = sin((3.1415926535897931f * (move_counter_ - 20.0f)) / 160.0f) * 2.5f;
		}
	}
	else if (move_type_ == 3)
	{
		if (move_counter_ < 50)
			vy_ = -6.0f;

		else if (move_counter_ >= 100)
		{
			vx_ = -sin((3.1415926535897931f * (move_counter_ - 100.0f)) / 160.0f) * 2.5f;
			vy_ = sin((3.1415926535897931f * (move_counter_ - 20.0f)) / 160.0f) * 2.5f;
		}
	}

	return true;
}

void Object_Monster_One::move(uint32_t udt)
{
	float x = get_pos_x();
	float y = get_pos_y();

	if (pattern_ == 0)
	{
		y -= 5.0f;
	}
	
	else if (pattern_ == 1)
	{
		x += sin((3.1415926535897931f * (double)pattern_counter_) / 40.0f) * 5.0f;
		y -= 1.5f;
	}
	else if (pattern_ == 2)
	{
		if (pattern_counter_ < 50)
			y -= 6.0f;

		else if (pattern_counter_ >= 100)
		{
			x += sin((3.1415926535897931f * ((double)pattern_counter_ - 100.0f)) / 160.0f) * 2.5f;
			y += sin((3.1415926535897931f * ((double)pattern_counter_ - 20.0f)) / 160.0f) * 2.5f;
		}
	}
	else if (pattern_ == 3)
	{
		if (pattern_counter_ < 50)
			y -= 6.0f;

		else if (pattern_counter_ >= 100)
		{
			x -= sin((3.1415926535897931f * ((double)pattern_counter_ - 100.0f)) / 160.0f) * 2.5f;
			y += sin((3.1415926535897931f * ((double)pattern_counter_ - 20.0f)) / 160.0f) * 2.5f;
		}
	}

	check_out_of_screen();

	if (butllet_counter_ > 0)
		butllet_counter_--;

	if (butllet_counter_ <= 0)
	{
		Object_Move_Aiming_Bullet *bullet = (Object_Move_Aiming_Bullet *)Game_Map::singleton()->new_object(OBJECT_CLASS_TYPE_MOVEAIMINGBULLET);
		Object_Move_Aiming_Bullet_Init bullet_init;
		bullet_init.player_ = (XObject*)Game_Map::singleton()->get_my_self();
		bullet_init.pos_.set_point(get_pos_x(), get_pos_y());
		bullet->initialise(&bullet_init);

		butllet_counter_ = 100;
	}

	pattern_counter_++;

	set_pos(x, y);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////