#ifndef __XOBJECT_VIEW_H__
#define __XOBJECT_VIEW_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "Object.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_View : public Node
{
public:
	Object_View(XObject *object);
	virtual ~Object_View();

public:
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	virtual void update(float dt);

	XObject *get_object() { return object_; }

	virtual float get_width() const { return 0; }
	virtual float get_height() const { return 0; }

protected:
	XObject *object_;

	bool debug_show_rect_;
};



/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
