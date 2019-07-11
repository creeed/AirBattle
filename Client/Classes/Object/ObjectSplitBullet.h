#ifndef __OBJECT_SPLIT_BULLET_H__
#define __OBJECT_SPLIT_BULLET_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "ObjectMonsterBullet.h"

struct Object_Split_Bullet_Init : public Object_Monster_Bullet_Init
{
	XObject *player_;

	Object_Split_Bullet_Init()
	{
		cleanup();
	}

	virtual void cleanup()
	{
		player_ = 0;
		Object_Monster_Bullet_Init::cleanup();
	}
};


/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_Split_Bullet : public Object_Monster_Bullet
{
public:
	Object_Split_Bullet();
	virtual ~Object_Split_Bullet();

	virtual OBJECT_CLASS_TYPE get_obj_type() const { return OBJECT_CLASS_TYPE_SPLITBULLET; }

	virtual bool initialise(const Object_Init *init);

	virtual void move(uint32_t udt);

private:
	int butllet_counter_;
};


/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
