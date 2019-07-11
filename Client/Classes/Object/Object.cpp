#include "Object.h"
#include "ObjectView.h"
#include "ObjectPlayerMySelf.h"
#include "GameMap.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
XObject::XObject() 
{
	id_ = INVALID;
	server_id_ = INVALID;

	visible_ = false;
	dead_ = false;
	
	hp_ = 0;
	attack_ = 0;

	x_ = 0.0f;
	y_ = 0.0f;
	dir_ = 0;

	view_ = 0;
}

XObject::~XObject()
{
}

bool XObject::initialise(const Object_Init *init)
{
	if ( init != NULL )
	{
		x_ = init->x_;
		y_ = init->y_;
		dir_ = init->dir_;

		hp_ = init->hp_;
		attack_ = init->attack_;
	}

	return true;
}

void XObject::cleanup( )
{
	visible_ = false;
	dead_ = false;

	hp_ = 0;
	attack_ = 0;

	x_ = 0.0f;
	y_ = 0.0f;
	dir_ = 0.0f;

	if (view_)
	{
		//view_->runAction(RemoveSelf::create());
		view_->removeFromParent();
		view_ = 0;
	}
	
}

bool XObject::heartbeat(uint32_t udt)
{
	if (dead_)
	{
		return false;
	}

	check_out_of_screen();

	if (view_)
	{
		view_->setPosition(x_, y_);
	}

	return true;
}

bool XObject::is_special_object(std::string& str_return)
{
	if (this == (XObject*)Game_Map::singleton()->get_my_self())
	{
		str_return = "myself";
		return true;
	}
	else
		return false;
}

bool XObject::check_hit(XObject *obj)
{
	return false;
}

bool XObject::check_out_of_screen()
{
	if (x_ - get_view_width() / 2.0f > WINDOW_WIDTH
		|| x_ + get_view_width() / 2.0f < 0.0f
		|| y_ - get_view_height() / 2.0f > WINDOW_HEIGHT
		|| y_ + get_view_height() / 2.0f < 0.0f)
	{
		on_dead();

		return true;
	}

	return false;

}

float XObject::get_view_width() const
{
	if (view_)
	{
		return view_->get_width();
	}

	return 0.0f;
}

float XObject::get_view_height() const
{
	if (view_)
	{
		return view_->get_height();
	}

	return 0.0f;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////