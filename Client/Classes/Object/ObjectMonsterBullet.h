#ifndef __OBJECT_MONSTER_BULLET_H__
#define __OBJECT_MONSTER_BULLET_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "ObjectBullet.h"

struct Object_Monster_Bullet_Init : public Object_Bullet_Init
{
	Object_Monster_Bullet_Init()
	{
		cleanup();
	}

	virtual void cleanup()
	{
		Object_Bullet_Init::cleanup();
	}
};


/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_Monster_Bullet : public Object_Bullet
{
public:
	Object_Monster_Bullet();
	virtual ~Object_Monster_Bullet();

public:
	virtual bool check_hit(XObject *obj);

};


/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
