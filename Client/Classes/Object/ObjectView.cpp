#include "ObjectView.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_View::Object_View(XObject *object)
	:object_(object)
{
	
}

Object_View::~Object_View()
{
}

bool Object_View::init()
{
	this->scheduleUpdate();

	return true;
}

void Object_View::onEnter()
{

}

void Object_View::onExit()
{

}

void Object_View::update(float dt)
{

}






/////////////////////////////////////////////////////////////////////////////////////////////////////