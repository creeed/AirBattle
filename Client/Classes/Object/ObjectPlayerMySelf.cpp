#include "ObjectPlayerMySelf.h"
#include "ObjectPlayerMySelfView.h"
#include "GameMap.h"
#include "GameMapView.h"
#include "ObjectPlayerBasicBullet.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_PlayerMySelf::Object_PlayerMySelf()
{
}

Object_PlayerMySelf::~Object_PlayerMySelf()
{
	cleanup();
}

bool Object_PlayerMySelf::initialise(const Object_Init *init)
{
	if (!Object_PlayerOther::initialise(init))
		return false;

	Object_Player_MySelf_Init *pinit = (Object_Player_MySelf_Init *)init;

	view_ = Object_PlayerMySelf_View::create(this);
	Game_Map::singleton()->get_view()->get_map_layer(LAYER_ORDER_OBJECT)->addChild(view_);

	hit_rect_.set_rect(-70, -57, 70, 57);

	return true;
}

void Object_PlayerMySelf::cleanup()
{
	Object_PlayerOther::cleanup();
}

bool Object_PlayerMySelf::heartbeat(uint32_t udt)
{
	bool ret = Object_PlayerOther::heartbeat(udt);

	if (butllet_counter_ > 0)
		butllet_counter_--;

	if (butllet_counter_ <= 0)
	{
		Object_Player_Basic_Bullet *bullet = 0;
		Object_Player_Basic_Bullet_Init bullet_init;

		bullet = (Object_Player_Basic_Bullet *)Game_Map::singleton()->new_object(OBJECT_CLASS_TYPE_PLAYERBASICBULLET);
		bullet_init.x_ = get_x() - 30;
		bullet_init.y_ = get_y() + 20;
		bullet_init.vy_ = 20;
		bullet_init.attack_ = get_attack();
		bullet->initialise(&bullet_init);

		bullet = (Object_Player_Basic_Bullet *)Game_Map::singleton()->new_object(OBJECT_CLASS_TYPE_PLAYERBASICBULLET);
		bullet_init.x_ = get_x() - 15;
		bullet_init.y_ = get_y() + 20;
		bullet_init.vy_ = 20;
		bullet->initialise(&bullet_init);

		bullet = (Object_Player_Basic_Bullet *)Game_Map::singleton()->new_object(OBJECT_CLASS_TYPE_PLAYERBASICBULLET);
		bullet_init.x_ = get_x() ;
		bullet_init.y_ = get_y() + 20;
		bullet_init.vy_ = 20;
		bullet_init.attack_ = get_attack();
		bullet->initialise(&bullet_init);

		bullet = (Object_Player_Basic_Bullet *)Game_Map::singleton()->new_object(OBJECT_CLASS_TYPE_PLAYERBASICBULLET);
		bullet_init.x_ = get_x() + 15;
		bullet_init.y_ = get_y() + 20;
		bullet_init.vy_ = 20;
		bullet_init.attack_ = get_attack();
		bullet->initialise(&bullet_init);

		bullet = (Object_Player_Basic_Bullet *)Game_Map::singleton()->new_object(OBJECT_CLASS_TYPE_PLAYERBASICBULLET);
		bullet_init.x_ = get_x() + 30;
		bullet_init.y_ = get_y() + 20;
		bullet_init.vy_ = 20;
		bullet_init.attack_ = get_attack();
		bullet->initialise(&bullet_init);

		butllet_counter_ = 8;
	}

	return ret;
}

bool Object_PlayerMySelf::check_hit(XObject *obj)
{
	bool ret = false;

	if (obj->get_obj_type() == OBJECT_CLASS_TYPE_MONSTER || obj->get_obj_type() == OBJECT_CLASS_TYPE_BOSS)
	{
		World_Rect rect;
		rect.set_rect(World_Point(get_x(), get_y()),
			World_Size(get_view_width(), get_view_height()));
		rect.offset_rect(-get_view_width() / 2.0f, -get_view_height() / 2.0f);

		World_Rect obj_rect;
		obj_rect.set_rect(World_Point(obj->get_x(), obj->get_y()),
			World_Size(obj->get_view_width(), obj->get_view_height()));
		rect.offset_rect(-obj->get_view_width() / 2.0f, -obj->get_view_height() / 2.0f);

		if (obj_rect.intersection_rect(rect))
		{
			ret = true;
		}
		else
		{
			ret = false;
		}
	}

	if (ret)
	{
		set_hp(get_hp() - obj->get_attack());
		obj->set_hp(obj->get_hp() - get_attack());
	}

	return ret;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////