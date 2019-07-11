#ifndef __WORDL_SIZE_H__
#define __WORDL_SIZE_H__

/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
class World_Size 
{
public:
    World_Size():width_(0), height_(0)  { }
    World_Size(float width, float height):width_(width), height_(height) {}
    World_Size(const World_Size &size): width_(size.width_), height_(size.height_) {}
    ~World_Size() {}

    bool operator == (const World_Size &size) const { return (size.width_==width_&&size.height_==height_); }
    bool operator != (const World_Size &size) const { return (size.width_!=width_||size.height_!=height_); }

    World_Size &operator = (const World_Size &size) { width_=size.width_; height_=size.height_; return *this; }

    World_Size& operator += (const World_Size &size) { width_+=size.width_; height_+=size.height_; }
    World_Size& operator -= (const World_Size &size) { width_-=size.width_; height_-=size.height_; }

    void set_size(float width, float height) { width_=width; height_=height; }

    World_Size operator + (const World_Size &size) { return World_Size(width_+size.width_, height_+size.height_); }
    World_Size operator - (const World_Size &size) { return World_Size(width_-size.width_, height_-size.height_); }
    World_Size operator - () { return World_Size(-width_, -height_); }

public:
    float width_;
    float height_;
};

/////////////////////////////////////////////////////////////////////////////////////////

#endif
