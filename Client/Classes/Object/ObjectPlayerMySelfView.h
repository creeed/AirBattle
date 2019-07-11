#ifndef __XOBJECT_PLAYER_MYSELF_VIEW_H__
#define __XOBJECT_PLAYER_MYSELF_VIEW_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "ObjectView.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_PlayerMySelf_View : public Object_View
{
public:
	Object_PlayerMySelf_View(XObject *object);
	virtual ~Object_PlayerMySelf_View();

	static Object_PlayerMySelf_View *create(XObject *object);

public:
	virtual bool init();
	virtual float get_width() const;
	virtual float get_height() const;

private:
	Sprite *spr_obj_;
};



/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
