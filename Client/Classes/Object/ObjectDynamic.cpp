#include "ObjectDynamic.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_Dynamic::Object_Dynamic()
{
	vx_ = 0.0f;
	vy_ = 0.0f;
	ax_ = 0.0f;
	ay_ = 0.0f;

	move_counter_ = 0;
	butllet_counter_ = 0;
}

Object_Dynamic::~Object_Dynamic()
{
}

bool Object_Dynamic::initialise(const Object_Init *init)
{
	if (!XObject::initialise(init))
		return false;

	Object_Dynamic_Init *pinit = (Object_Dynamic_Init *)init;

	vx_ = pinit->vx_;
	vy_ = pinit->vy_;
	ax_ = pinit->ax_;
	ay_ = pinit->ay_;

	return true;
}

void Object_Dynamic::cleanup( )
{
	vx_ = 0.0f;
	vy_ = 0.0f;
	ax_ = 0.0f;
	ay_ = 0.0f;

	move_counter_ = 0;
	butllet_counter_ = 0;

	XObject::cleanup();
}

bool Object_Dynamic::heartbeat(uint32_t udt)
{
	bool ret = XObject::heartbeat(udt);
	if (!ret)
	{
		return false;
	}

	move(udt);

	return true;
}

void Object_Dynamic::move(uint32_t udt)
{
	vx_ = vx_ + ax_;
	vy_ = vy_ + ay_;

	x_ = x_ + vx_;
	y_ = y_ + vy_;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////