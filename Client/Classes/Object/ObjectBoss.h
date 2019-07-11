#ifndef __OBJECT_BOSS_H__
#define __OBJECT_BOSS_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "ObjectMonster.h"

struct Object_Boss_Init : public Object_Monster_Init
{
	Object_Boss_Init()
	{
		cleanup();
	}

	virtual void cleanup()
	{
		Object_Monster_Init::cleanup();
	}
};

/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_Boss : public Object_Monster
{
public:
	Object_Boss();
	virtual ~Object_Boss();

	virtual OBJECT_CLASS_TYPE get_obj_type() const { return OBJECT_CLASS_TYPE_BOSS; }

public:
	virtual bool initialise(const Object_Init *init);
	virtual void cleanup( );

	virtual bool heartbeat(uint32_t udt);

public:

private:
	

};


/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
