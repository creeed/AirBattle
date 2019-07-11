#include "WorldRect.h"

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////
World_Rect::World_Rect()
:top_(0),
bottom_(0),
left_(0),
right_(0)
{
}

World_Rect::World_Rect(const World_Point &point, const World_Size &size)
:top_(point.y_),
bottom_(point.y_ + size.height_),
left_(point.x_),
right_(point.x_ + size.width_)
{
}

World_Rect::World_Rect(float left, float top, float right, float bottom)
:top_(top),
bottom_(bottom),
left_(left),
right_(right)
{
}

World_Rect::World_Rect(const World_Rect& rect)
:top_(rect.top_),
bottom_(rect.bottom_),
left_(rect.left_),
right_(rect.right_)
{
}

void World_Rect::set_pos(const World_Point& pt)
{
	World_Size sz(get_size());

	left_ = pt.x_;
    top_  = pt.y_;

	set_size(sz);
}

void World_Rect::set_rect(float left, float top, float right, float bottom)
{
    top_ = top;
    bottom_ = bottom;
    left_ = left;
    right_ = right;
} 

void World_Rect::set_rect(const World_Point &point, const World_Size &size)
{
    top_ = point.y_;
    bottom_ = point.y_ + size.height_;
    left_ = point.x_;
    right_ = point.x_ + size.width_;
} 

void World_Rect::offset_rect(float x, float y)
{
    top_ += y;
    bottom_ += y;
    left_ += x;
    right_ += x;
}

void World_Rect::offset_rect(const World_Size &size)
{
    top_ += size.height_;
    bottom_ += size.height_;
    left_ += size.width_ ;
    right_ += size.width_ ;
}

bool World_Rect::pt_in_rect(const World_Point& point) const
{
	if ((left_ > point.x_) ||
		(right_ <= point.x_) ||
		(top_ > point.y_) ||
		(bottom_ <= point.y_))
	{
		return false;
	}

	return true;
}

bool World_Rect::intersection_rect(const World_Rect& rect) const
{
	if ((right_ < rect.left_) ||
		(left_ > rect.right_) ||
		(bottom_ < rect.top_) ||
		(top_ > rect.bottom_))
	{
		return false;
	}
	else
	{
		return true;
	}
}

//World_Rect World_Rect::union_rect(const World_Rect& rect) const 
//{
//}
//
//World_Rect World_Rect::subtract_rect(const World_Rect& rect) const 
//{
//}




	

///////////////////////////////////////////////////////////////////////////////////////////////
