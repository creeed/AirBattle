#ifndef __OBJECT_PLAYER_BULLET_H__
#define __OBJECT_PLAYER_BULLET_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "ObjectBullet.h"

struct Object_Player_Bullet_Init : public Object_Bullet_Init
{
	Object_Player_Bullet_Init()
	{
		cleanup();
	}

	virtual void cleanup()
	{
		Object_Bullet_Init::cleanup();
	}
};


/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_Player_Bullet : public Object_Bullet
{
public:
	Object_Player_Bullet();
	virtual ~Object_Player_Bullet();

public:
	virtual bool check_hit(XObject *obj);

};


/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
