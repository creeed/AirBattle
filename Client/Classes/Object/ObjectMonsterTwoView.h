#ifndef __XOBJECT_MONSTER_TWO_VIEW_H__
#define __XOBJECT_MONSTER_TWO_VIEW_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "ObjectView.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_Monster_Two_View : public Object_View
{
public:
	Object_Monster_Two_View(XObject *object);
	virtual ~Object_Monster_Two_View();

	static Object_Monster_Two_View *create(XObject *object);

public:
	bool init();

};



/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
