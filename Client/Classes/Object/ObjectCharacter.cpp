#include "ObjectCharacter.h"
#include "ObjectView.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_Character::Object_Character()
{

}

Object_Character::~Object_Character()
{
}

bool Object_Character::initialise(const Object_Init *init)
{
	if (!Object_Dynamic::initialise(init))
		return false;

	return true;
}

void Object_Character::cleanup()
{
	Object_Dynamic::cleanup();

	dead_ = false;
}

bool Object_Character::heartbeat(uint32_t udt)
{
	bool ret = Object_Dynamic::heartbeat(udt);
	if (!ret)
	{
		return false;
	}

	if (hp_ <= 0)
	{
		on_dead();
	}

	return ret;
}





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
