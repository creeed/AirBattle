#include "ObjectMonster.h"
#include "ObjectMoveAimingBullet.h"
#include "ObjectMonsterView.h"
#include "GameMap.h"
#include "GameMapView.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_Monster::Object_Monster()
{
	move_type_ = 0;
	bullet_type_ = 0;
}

Object_Monster::~Object_Monster()
{
}

bool Object_Monster::initialise(const Object_Init *init)
{
	if (!Object_Character::initialise(init))
		return false;

	Object_Monster_Init *pinit = (Object_Monster_Init *)init;

	move_type_ = pinit->move_type_;
	bullet_type_ = pinit->bullet_type_;

	view_ = Object_Monster_View::create(this);
	Game_Map::singleton()->get_view()->get_map_layer(LAYER_ORDER_OBJECT)->addChild(view_);

	hit_rect_.set_rect(-100, -100, 100, 100);


	return true;
}

void Object_Monster::cleanup()
{
	Object_Character::cleanup();
}

bool Object_Monster::heartbeat(uint32_t udt)
{
	bool ret = Object_Character::heartbeat(udt);
	if (!ret)
	{
		return false;
	}

	if (move_type_ == 0)
	{
		vy_ = -3.0f;
	}

	else if (move_type_ == 1)
	{
		vx_ = sin((3.1415926535897931f * move_counter_) / 40.0f) * 5.0f;
		vy_ = -3.0f;
	}
	else if (move_type_ == 2)
	{
		if (move_counter_ < 20)
			vy_ = -3.0f;

		else if (move_counter_ >= 100)
		{
			vx_ = sin((3.1415926535897931f * (move_counter_ - 100.0f)) / 160.0f) * 2.5f;
			vy_ = sin((3.1415926535897931f * (move_counter_ - 20.0f)) / 160.0f) * 2.5f;
		}
	}
	else if (move_type_ == 3)
	{
		if (move_counter_ < 30)
			vy_ = -3.0f;

		else if (move_counter_ >= 100)
		{
			vx_ = -sin((3.1415926535897931f * (move_counter_ - 100.0f)) / 160.0f) * 2.5f;
			vy_ = sin((3.1415926535897931f * (move_counter_ - 20.0f)) / 160.0f) * 2.5f;
		}
	}

	if (bullet_type_ == 0)
	{
		if (butllet_counter_ > 0)
			butllet_counter_--;

		if (butllet_counter_ <= 0)
		{
			Object_Move_Aiming_Bullet *bullet = (Object_Move_Aiming_Bullet *)Game_Map::singleton()->new_object(OBJECT_CLASS_TYPE_MOVEAIMINGBULLET);
			Object_Move_Aiming_Bullet_Init bullet_init;
			bullet_init.player_ = (XObject*)Game_Map::singleton()->get_my_self();
			bullet_init.x_ = get_x();
			bullet_init.y_ = get_y();
			bullet_init.speed_ = 10.0f;
			bullet->initialise(&bullet_init);

			butllet_counter_ = 60;
		}
	}

	move_counter_++;

	check_out_of_screen();

	return true;
}

bool Object_Monster::check_hit(XObject *obj)
{
	bool ret = false;

	if (obj->get_obj_type() == OBJECT_CLASS_TYPE_PLAYERMYSELF)
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

void Object_Monster::on_dead()
{
	Object_Character::on_dead();

	int rnd = rand() % 10000;

	bool success = ((rnd ) < 3000); // Íò·ÖÖ® drop

	if (success)
	{
		if (view_)
		{
			Object_Monster_View *monster_view = (Object_Monster_View *)view_;
			monster_view->draw_gold();
		}
		
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////