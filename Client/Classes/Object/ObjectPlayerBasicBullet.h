#ifndef __OBJECT_PLAYER_BASIC_BULLET_H__
#define __OBJECT_PLAYER_BASIC_BULLET_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "ObjectPlayerBullet.h"

struct Object_Player_Basic_Bullet_Init : public Object_Player_Bullet_Init
{
	Object_Player_Basic_Bullet_Init()
	{
		cleanup();
	}

	virtual void cleanup()
	{
		Object_Player_Bullet_Init::cleanup();
	}
};


/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_Player_Basic_Bullet : public Object_Player_Bullet
{
public:
	Object_Player_Basic_Bullet();
	virtual ~Object_Player_Basic_Bullet();

	virtual OBJECT_CLASS_TYPE get_obj_type() const { return OBJECT_CLASS_TYPE_PLAYERBASICBULLET; }

	virtual bool initialise(const Object_Init *init);
};


/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
