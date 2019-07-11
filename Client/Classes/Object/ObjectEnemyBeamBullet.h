#ifndef __OBJECT_ENEMY_BEAM_BULLET_H__
#define __OBJECT_ENEMY_BEAM_BULLET_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "ObjectMonsterBullet.h"

struct Object_Enemy_Beam_Bullet_Init : public Object_Monster_Bullet_Init
{
	XObject *enemy_;

	Object_Enemy_Beam_Bullet_Init()
	{
		cleanup();
	}

	virtual void cleanup()
	{
		enemy_ = 0;
		Object_Monster_Bullet_Init::cleanup();
	}
};


/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_Enemy_Beam_Bullet : public Object_Monster_Bullet
{
public:
	Object_Enemy_Beam_Bullet();
	virtual ~Object_Enemy_Beam_Bullet();

	virtual OBJECT_CLASS_TYPE get_obj_type() const { return OBJECT_CLASS_TYPE_ENEMYBEAMBULLET; }

	virtual bool initialise(const Object_Init *init);

	virtual void move(uint32_t udt);

private:
	XObject *enemy_;

};


/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
