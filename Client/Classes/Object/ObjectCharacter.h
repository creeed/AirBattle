#ifndef __OBJECT_CHARACTER_H__
#define __OBJECT_CHARACTER_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "ObjectDynamic.h"

struct Object_Character_Init : public Object_Dynamic_Init
{
	Object_Character_Init()
	{
		cleanup();
	}

	virtual void cleanup()
	{
		Object_Dynamic_Init::cleanup();
	}
};


/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_Character : public Object_Dynamic
{
public:
	Object_Character();
	virtual ~Object_Character();

public:
	virtual bool initialise(const Object_Init *init);
	virtual void cleanup( );

	virtual bool heartbeat(uint32_t udt);

public:
	

protected:



};


/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
