#include "ObjectMonsterTwo.h"
#include "ObjectMonsterTwoView.h"
#include "GameMap.h"
#include "GameMapView.h"
#include "ObjectEnemyBeamBullet.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_Monster_Two::Object_Monster_Two()
{
	pattern_counter_ = 0;
	butllet_counter_ = 0;
}

Object_Monster_Two::~Object_Monster_Two()
{
}

bool Object_Monster_Two::initialise(const Object_Init *init)
{
	if (!Object_Monster::initialise(init))
		return false;

	view_ = Object_Monster_Two_View::create(this);
	Game_Map::singleton()->get_view()->get_map_layer(LAYER_ORDER_OBJECT)->addChild(view_);

	vy_ = 2.0f;
	hit_rect_.set_rect(-100, -100, 100, 100);

	return true;
}

void Object_Monster_Two::cleanup()
{
	Object_Monster::cleanup();
}

bool Object_Monster_Two::heartbeat(uint32_t udt)
{
	bool ret = Object_Monster::heartbeat(udt);
	if (!ret)
	{
		return false;
	}

	return true;
}

void Object_Monster_Two::move(uint32_t udt)
{
	float x = get_pos_x();
	float y = get_pos_y();

	if (pattern_ == 0)
	{
		if (pattern_counter_ < 100)
		{
			y -= vy_;
		}
		else if (pattern_counter_ > 300)
		{
			y += vy_;
		}
		
	}

	check_out_of_screen();

	if (butllet_counter_ > 0)
		butllet_counter_--;

	if (pattern_counter_ > 100 && pattern_counter_ < 280 && butllet_counter_ <= 0)
	{
		Object_Enemy_Beam_Bullet *bullet = (Object_Enemy_Beam_Bullet *)Game_Map::singleton()->new_object(OBJECT_CLASS_TYPE_ENEMYBEAMBULLET);
		Object_Enemy_Beam_Bullet_Init bullet_init;
		bullet_init.enemy_ = this;
		bullet_init.pos_.set_point(get_pos_x(), get_pos_y());
		bullet->initialise(&bullet_init);

		butllet_counter_ = 20;
	}
	
	pattern_counter_++;

	set_pos(x, y);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////