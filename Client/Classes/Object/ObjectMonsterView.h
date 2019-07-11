#ifndef __XOBJECT_MONSTER_VIEW_H__
#define __XOBJECT_MONSTER_VIEW_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "ObjectView.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_Monster_View : public Object_View
{
public:
	Object_Monster_View(XObject *object);
	virtual ~Object_Monster_View();

	static Object_Monster_View *create(XObject *object);

public:
	virtual bool init();
	virtual float get_width() const;
	virtual float get_height() const;

public:
	void draw_gold();

private:
	Sprite *spr_obj_;
};



/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
