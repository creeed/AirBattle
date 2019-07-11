#ifndef __XOBJECT_MOVE_AIMING_BULLET_VIEW_H__
#define __XOBJECT_MOVE_AIMING_BULLET_VIEW_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "ObjectView.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_Move_Aiming_Bullet_View : public Object_View
{
public:
	Object_Move_Aiming_Bullet_View(XObject *object);
	virtual ~Object_Move_Aiming_Bullet_View();

	static Object_Move_Aiming_Bullet_View *create(XObject *object);

public:
	virtual bool init();
	virtual float get_width() const;
	virtual float get_height() const;

private:
	Sprite *spr_obj_;
};



/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
