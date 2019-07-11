#ifndef __OBJECT_DYNAMIC_H__
#define __OBJECT_DYNAMIC_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "Object.h"

struct Object_Dynamic_Init : public Object_Init
{
	float vx_;
	float vy_;
	float ax_;
	float ay_;

	Object_Dynamic_Init()
	{
		cleanup();
	}

	virtual void cleanup()
	{
		vx_ = 0.0f;
		vy_ = 0.0f;
		ax_ = 0.0f;
		ay_ = 0.0f;

		Object_Init::cleanup();
	}
};

/////////////////////////////////////////////////////////////////////////////////////////////////
class Object_Dynamic : public XObject
{
public:
    Object_Dynamic();
	virtual ~Object_Dynamic();

public:
	virtual bool initialise(const Object_Init *init);
	virtual void cleanup();

	virtual bool heartbeat(uint32_t udt);

	virtual void move(uint32_t udt);
	

public:
	float get_vx() const { return vx_; }
	void set_vx(float vx) { vx_ = vx; }

	float get_vy() const { return vy_; }
	void set_vy(float vy) { vy_ = vy; }

	float get_ax() const { return ax_; }
	void set_ax(float ax) { ax_ = ax; }

	float get_ay() const { return ay_; }
	void set_ay(float ay) { ay_ = ay; }

protected:
	float vx_;
	float vy_;
	float ax_;
	float ay_;

protected:
	int move_counter_;
	int butllet_counter_;
};


/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
