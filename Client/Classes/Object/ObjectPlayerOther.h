#ifndef __OBJECT_PLAYEROTHER_H__
#define __OBJECT_PLAYEROTHER_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "ObjectCharacter.h"

struct Object_Player_Other_Init : public Object_Character_Init
{
	Object_Player_Other_Init()
	{
		cleanup();
	}

	virtual void cleanup()
	{
		Object_Character_Init::cleanup();
	}
};


/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_PlayerOther : public Object_Character
{
public:
    Object_PlayerOther();
	virtual ~Object_PlayerOther();

public:
	virtual OBJECT_CLASS_TYPE get_obj_type() const { return OBJECT_CLASS_TYPE_PLAYEROTHER; }

	virtual bool initialise(const Object_Init *init);
	virtual void cleanup( );

	uint32_t get_server_guid() const { return guid_server_; }
	void set_server_guid(uint32_t guid) { guid_server_ = guid; }

	virtual bool heartbeat(uint32_t udt);

private:
	uint32_t guid_server_;
};

/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
