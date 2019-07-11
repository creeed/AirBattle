#ifndef __WORLD_POINT_H__
#define __WORLD_POINT_H__


///////////////////////////////////////////////////////////////////////////////////////////////
class World_Point
{
public:
    World_Point():x_(0), y_(0) {}
    World_Point(float x, float y):x_(x), y_(y) {}
    World_Point(const World_Point &point):x_(point.x_), y_(point.y_) {}
    ~World_Point() {}

public:
    void offset(float x, float y) { x_+= x; y_+=y; }

    void set_point(float x, float y) { x_=x; y_=y; }

    bool operator == (const World_Point &point) const { return (x_==point.x_&&y_==point.y_); }
    bool operator != (const World_Point &point) const { return (x_!=point.x_||y_!=point.y_); }

    World_Point &operator = (const World_Point &point) { x_=point.x_; y_=point.y_; return *this; }

    void operator += (const World_Point &point) { x_+=point.x_; y_+=point.y_; }
    void operator -= (const World_Point &point) { x_-=point.x_; y_-=point.y_; }

    World_Point operator + (const World_Point &point) { return World_Point(x_+point.x_, y_+point.y_); }
    World_Point operator - (const World_Point &point) { return World_Point(x_-point.x_, y_-point.y_); }
    World_Point operator - () { return World_Point(-x_, -y_); }

    World_Point operator * (float multip) { return World_Point(x_*multip, y_*multip); }

public:
    float x_;
    float y_;
};


inline World_Point operator+ (const World_Point &lhs, const World_Point &rhs)
{
	return World_Point(lhs.x_+rhs.x_, lhs.y_+rhs.y_);
}

inline World_Point operator- (const World_Point &lhs, const World_Point &rhs)
{
	return World_Point(lhs.x_-rhs.x_, lhs.y_-rhs.y_);
}


///////////////////////////////////////////////////////////////////////////////////////////////

#endif
