#ifndef __WORLD_RECT_H__
#define __WORLD_RECT_H__

///////////////////////////////////////////////////////////////////////////////////////////////
#include "WorldPoint.h"
#include "WorldSize.h"

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////
class World_Rect 
{
public:
    World_Rect();
    World_Rect(const World_Point &point, const World_Size &size);
    World_Rect(float left, float top, float right, float bottom);
    World_Rect(const World_Rect& rect);

    World_Point get_pos() const { return World_Point(left_, top_); }
    void set_pos(const World_Point& pt);

    float get_width() const { return right_ - left_; }
    void set_width(float width) { right_ = left_ + width; }

    float get_height() const {return bottom_ - top_; }
    void set_height(float height) { bottom_ = top_ + height;}

    World_Size get_size() const { return World_Size(get_width(), get_height());}
    void set_size(const World_Size& size)	{ set_width(size.width_); set_height(size.height_); }

    void set_rect(float left, float top, float right, float bottom); 
    void set_rect(const World_Point &point, const World_Size &size); 

    void offset_rect(float x, float y);
    void offset_rect(const World_Size &size);

    bool pt_in_rect(const World_Point& point) const;
    bool is_empty() const { return (get_width() == 0.0f && get_height() == 0.0f); }

    bool intersection_rect(const World_Rect& rect) const;
    //Rect union_rect(const Rect& rect) const ;
    //Rect subtract_rect(const Rect& rect) const ;

    World_Rect& operator = (const World_Rect& rhs) 
    {
	    left_ = rhs.left_;
	    top_ = rhs.top_;
	    right_ = rhs.right_;
	    bottom_ = rhs.bottom_;

	    return *this;
    }

    bool operator == (const World_Rect& rhs) const 	
    {
		return ((left_ == rhs.left_) && (right_ == rhs.right_) && (top_ == rhs.top_) && (bottom_ == rhs.bottom_));
	}
    bool operator != (const World_Rect& rhs) const { return !operator==(rhs); }

public:
    float left_, top_, right_, bottom_;
};

///////////////////////////////////////////////////////////////////////////////////////////////

#endif