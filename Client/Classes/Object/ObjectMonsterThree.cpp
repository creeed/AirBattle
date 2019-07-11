#include "ObjectMonsterThree.h"
#include "ObjectMonsterThreeView.h"
#include "GameMap.h"
#include "GameMapView.h"
#include "ObjectMoveAimingBullet.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_Monster_Three::Object_Monster_Three()
{
	pattern_counter_ = 0;
	butllet_counter_ = 0;
}

Object_Monster_Three::~Object_Monster_Three()
{
}

bool Object_Monster_Three::initialise(const Object_Init *init)
{
	if (!Object_Monster::initialise(init))
		return false;

	view_ = Object_Monster_Three_View::create(this);
	Game_Map::singleton()->get_view()->get_map_layer(LAYER_ORDER_OBJECT)->addChild(view_);

	vy_ = -4.0f;

	hit_rect_.set_rect(-100, -100, 100, 100);

	return true;
}

void Object_Monster_Three::cleanup()
{
	Object_Monster::cleanup();
}

bool Object_Monster_Three::heartbeat(uint32_t udt)
{
	bool ret = Object_Monster::heartbeat(udt);
	if (!ret)
	{
		return false;
	}

	return true;
}

void Object_Monster_Three::move(uint32_t udt)
{
	float x = get_pos_x();
	float y = get_pos_y();

	if (pattern_ == 0) 
	{
		if (pattern_counter_ < 60)
		{
			x += vx_;
			y == vy_;
		}
		else if (pattern_counter_ > 250)
		{
			x += vx_;
			y += vy_;
		}
	}
	else if (pattern_ == 1)
	{
		if (pattern_counter_ < 60)
		{
			x -= vx_;
			y -= vy_;
		}
		else if (pattern_counter_ > 150)
		{
			x += vx_;
			y += vy_;
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

		butllet_counter_ = 90;
	}

	pattern_counter_++;

	set_pos(x, y);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////