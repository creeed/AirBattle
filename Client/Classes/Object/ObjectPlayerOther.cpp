#include "ObjectPlayerOther.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_PlayerOther::Object_PlayerOther()
{
}

Object_PlayerOther::~Object_PlayerOther()
{
}

bool Object_PlayerOther::initialise(const Object_Init *init)
{
	if (!Object_Character::initialise(init))
		return false;

	return true;
}

void Object_PlayerOther::cleanup()
{
	Object_Character::cleanup();
}

bool Object_PlayerOther::heartbeat(uint32_t udt)
{
	bool ret = Object_Character::heartbeat(udt);

	return ret;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////