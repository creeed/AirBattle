#ifndef __OBJECT_MONSTER_H__
#define __OBJECT_MONSTER_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "ObjectCharacter.h"

struct Object_Monster_Init : public Object_Character_Init
{
	int move_type_;
	int bullet_type_;

	Object_Monster_Init()
	{
		cleanup();
	}

	virtual void cleanup()
	{
		move_type_ = 0;
		bullet_type_ = 0;

		Object_Character_Init::cleanup();
	}
};

/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_Monster : public Object_Character
{
public:
	Object_Monster();
	virtual ~Object_Monster();

	virtual OBJECT_CLASS_TYPE get_obj_type() const { return OBJECT_CLASS_TYPE_MONSTER; }

public:
	virtual bool initialise(const Object_Init *init);
	virtual void cleanup( );

	virtual bool heartbeat(uint32_t udt);
	virtual bool check_hit(XObject *obj);

	virtual void on_dead();

public:

public:
	int move_type_;
	int bullet_type_;

};


/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
