#ifndef __OBJECT_BULLET_H__
#define __OBJECT_BULLET_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "ObjectDynamic.h"

struct Object_Bullet_Init : public Object_Dynamic_Init
{
	Object_Bullet_Init()
	{
		cleanup();
	}

	virtual void cleanup()
	{
		Object_Dynamic_Init::cleanup();
	}
};


/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_Bullet : public Object_Dynamic
{
public:
	Object_Bullet();
	virtual ~Object_Bullet();

public:
	virtual bool initialise(const Object_Init *init);
	virtual void cleanup( );

	virtual bool heartbeat(uint32_t udt);

public:



};


/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
