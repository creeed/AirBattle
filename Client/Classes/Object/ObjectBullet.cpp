#include "ObjectBullet.h"
#include "ObjectView.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_Bullet::Object_Bullet()
{
	move_counter_ = 0;
	butllet_counter_ = 0;
}

Object_Bullet::~Object_Bullet()
{
}

bool Object_Bullet::initialise(const Object_Init *init)
{
	if (!Object_Dynamic::initialise(init))
		return false;

	return true;
}

void Object_Bullet::cleanup()
{
	Object_Dynamic::cleanup();
}

bool Object_Bullet::heartbeat(uint32_t udt)
{
	bool ret = Object_Dynamic::heartbeat(udt);
	if (!ret)
	{
		return false;
	}

	return ret;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
