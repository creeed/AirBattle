#ifndef __XOBJECT_DIRECTIONAL_BULLET_VIEW_H__
#define __XOBJECT_DIRECTIONAL_BULLET_VIEW_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "ObjectView.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_Directional_Bullet_View : public Object_View
{
public:
	Object_Directional_Bullet_View(XObject *object);
	virtual ~Object_Directional_Bullet_View();

	static Object_Directional_Bullet_View *create(XObject *object);

public:
	virtual bool init();
	virtual float get_width() const;
	virtual float get_height() const;

private:
	Sprite *spr_obj_;
};



/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
