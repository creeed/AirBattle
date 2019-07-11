#ifndef __OBJECT_PLAYERMYSELF_H__
#define __OBJECT_PLAYERMYSELF_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "ObjectPlayerOther.h"

struct Object_Player_MySelf_Init : public Object_Player_Other_Init
{
	Object_Player_MySelf_Init()
	{
		cleanup();
	}

	virtual void cleanup()
	{
		Object_Player_Other_Init::cleanup();
	}
};


/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_PlayerMySelf : public Object_PlayerOther
{
public:
    Object_PlayerMySelf();
	virtual ~Object_PlayerMySelf();

public:
	virtual OBJECT_CLASS_TYPE get_obj_type() const { return OBJECT_CLASS_TYPE_PLAYERMYSELF; }

	virtual bool initialise(const Object_Init *init);
	virtual void cleanup();

	virtual bool heartbeat(uint32_t udt);

	virtual void move(uint32_t udt) {}
	virtual bool check_hit(XObject *obj);

private:

};

/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
