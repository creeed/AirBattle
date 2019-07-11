#ifndef __XOBJECT_H__
#define __XOBJECT_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
class Object_View;

enum OBJECT_CLASS_TYPE
{
	OBJECT_CLASS_TYPE_INVALID = -1,

	OBJECT_CLASS_TYPE_MONSTER,
	OBJECT_CLASS_TYPE_BOSS,
	OBJECT_CLASS_TYPE_PLAYEROTHER,		//其他玩家
	OBJECT_CLASS_TYPE_PLAYERMYSELF,		//玩家自己

	OBJECT_CLASS_TYPE_PLAYERBASICBULLET,
	OBJECT_CLASS_TYPE_MOVEAIMINGBULLET,
	OBJECT_CLASS_TYPE_DIRECTIONALBULLET,
};

struct Object_Init
{
	float x_;
	float y_;
	float dir_;

	int hp_;
	int attack_;

	Object_Init()
	{
		cleanup();
	}

	virtual void cleanup()
	{
		x_ = 0.0f;
		y_ = 0.0f;
		dir_ = 0.0f;

		hp_ = 0;
		attack_ = 0;
	}
};

/////////////////////////////////////////////////////////////////////////////////////////////////
class XObject
{
public:

public:
    XObject();
	virtual ~XObject();

public:
	virtual OBJECT_CLASS_TYPE get_obj_type() const { return OBJECT_CLASS_TYPE_INVALID; }
	bool is_special_object(std::string& str_return);

	uint32_t get_id() const { return id_; }   //local id
	void set_id(uint32_t id) { id_ = id; }

	uint32_t get_server_id() const { return server_id_; } //server object id
	void set_server_id(uint32_t id){ server_id_ = id; }

public:
	virtual bool initialise(const Object_Init *init);
	virtual void cleanup();

	virtual bool heartbeat(uint32_t udt);

public:
	bool is_visible() const { return visible_; }
	void set_visible(bool visible) { visible_ = visible; }	

	bool is_dead() const { return dead_; }
	virtual void on_dead() { dead_ = true; }

	int get_hp() const { return hp_; }
	void set_hp(int hp) { hp_ = hp; }

	int get_attack() const { return attack_; }
	void set_attack(int attack) { attack_ = attack; }

	float get_x() const { return x_; }
	void set_x(float x) { x_ = x; }

	float get_y() const { return y_; }
	void set_y(float y) { y_ = y; }

	void set_pos(float x, float y) { x_ = x; y_ = y; }
	World_Point get_pos() const { return World_Point(x_, y_); }

	int get_dir() const { return dir_; }
	void set_dir(int dir) { dir_ = dir;  }

	World_Rect get_hit_rect() const { return hit_rect_; }
	void set_hit_rect(const World_Rect &hit_rect) { hit_rect_ = hit_rect; }

	virtual float get_view_width() const;
	virtual float get_view_height() const;

	virtual bool check_hit(XObject *obj);
	virtual bool check_out_of_screen();

protected:
	uint32_t id_;
	uint32_t server_id_;

	bool dead_;
	bool visible_;

	int hp_;
	int attack_;

	float x_;
	float y_;
	float dir_;

	World_Rect hit_rect_;

protected:
	Object_View *view_;
};

/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
