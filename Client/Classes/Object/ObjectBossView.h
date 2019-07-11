#ifndef __XOBJECT_BOSS_VIEW_H__
#define __XOBJECT_BOSS_VIEW_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "ObjectView.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_Boss_View : public Object_View
{
public:
	Object_Boss_View(XObject *object);
	virtual ~Object_Boss_View();

	static Object_Boss_View *create(XObject *object);

public:
	virtual bool init();

	virtual float get_width() const;
	virtual float get_height() const;

private:
	Sprite *spr_obj_;
};



/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
