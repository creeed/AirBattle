#ifndef __OBJECT_DIRECTIONAL_BULLET_H__
#define __OBJECT_DIRECTIONAL_BULLET_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "ObjectMonsterBullet.h"

struct Object_Directional_Bullet_Init : public Object_Monster_Bullet_Init
{
	float theta_;
	float speed_;

	Object_Directional_Bullet_Init()
	{
		cleanup();
	}

	virtual void cleanup()
	{
		theta_ = 0.0f;
		speed_ = 0.0f;

		Object_Monster_Bullet_Init::cleanup();
	}
};


/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_Directional_Bullet : public Object_Monster_Bullet
{
public:
	Object_Directional_Bullet();
	virtual ~Object_Directional_Bullet();

	virtual OBJECT_CLASS_TYPE get_obj_type() const { return OBJECT_CLASS_TYPE_DIRECTIONALBULLET; }

	virtual bool initialise(const Object_Init *init);


private:
	float theta_;
	float speed_;

};


/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
