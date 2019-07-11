#ifndef __OBJECT_MONSTER_THREE_H__
#define __OBJECT_MONSTER_THREE_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "ObjectMonster.h"

struct Object_Monster_Three_Init : public Object_Monster_Init
{
	Object_Monster_Three_Init()
	{
		cleanup();
	}

	virtual void cleanup()
	{
		Object_Monster_Init::cleanup();
	}
};

/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_Monster_Three : public Object_Monster
{
public:
	Object_Monster_Three();
	virtual ~Object_Monster_Three();

public:
	virtual OBJECT_CLASS_TYPE get_obj_type() const { return OBJECT_CLASS_TYPE_MONSTERTHREE; }

	virtual bool initialise(const Object_Init *init);
	virtual void cleanup( );

	virtual bool heartbeat(uint32_t udt);

public:
	virtual void move(uint32_t udt);

private:
	int pattern_counter_;
	int butllet_counter_;
};


/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
