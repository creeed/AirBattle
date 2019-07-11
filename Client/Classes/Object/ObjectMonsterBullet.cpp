#include "ObjectMonsterBullet.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_Monster_Bullet::Object_Monster_Bullet()
{
}

Object_Monster_Bullet::~Object_Monster_Bullet()
{
}

bool Object_Monster_Bullet::check_hit(XObject *obj)
{
	bool ret = false;

	if (obj->get_obj_type() == OBJECT_CLASS_TYPE_PLAYERMYSELF)
	{
		World_Rect obj_rect;
		obj_rect.set_rect(World_Point(obj->get_x(), obj->get_y()),
			World_Size(obj->get_view_width(), obj->get_view_height()));
		obj_rect.offset_rect(-obj->get_view_width() / 2.0f, -obj->get_view_height() / 2.0f);

		if (obj_rect.pt_in_rect(get_pos()))
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
		on_dead();
		obj->set_hp(obj->get_hp() - get_attack());
	}

	return ret;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
