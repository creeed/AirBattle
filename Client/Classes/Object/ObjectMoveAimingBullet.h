#ifndef __OBJECT_MOVE_AIMING_BULLET_H__
#define __OBJECT_MOVE_AIMING_BULLET_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "ObjectMonsterBullet.h"

struct Object_Move_Aiming_Bullet_Init : public Object_Monster_Bullet_Init
{
	float speed_;
	XObject *player_;

	Object_Move_Aiming_Bullet_Init()
	{
		cleanup();
	}

	virtual void cleanup()
	{
		speed_ = 0.0f;
		player_ = 0;

		Object_Monster_Bullet_Init::cleanup();
	}
};


/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_Move_Aiming_Bullet : public Object_Monster_Bullet
{
public:
	Object_Move_Aiming_Bullet();
	virtual ~Object_Move_Aiming_Bullet();

	virtual OBJECT_CLASS_TYPE get_obj_type() const { return OBJECT_CLASS_TYPE_MOVEAIMINGBULLET; }

	virtual bool initialise(const Object_Init *init);

private:
	float speed_;
};


/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
