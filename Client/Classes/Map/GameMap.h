#ifndef __GAME_MAP_H__
#define __GAME_MAP_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "Object.h"

class Object_Character;
class Object_PlayerMySelf;
class Object_PlayerOther;
class Object_Monster;
class Object_Boss;

class Game_Map_View;

/////////////////////////////////////////////////////////////////////////////////////////////////
class Game_Map : public Singleton<Game_Map>
{
public:
	typedef std::map< int, XObject* > Object_Map;

public:
	Game_Map();
	~Game_Map();

	static Game_Map *singleton();

public:
	bool initialise();
	void cleanup( );

	bool tick(uint32_t udt);

	bool monster_producer();

public:
	XObject* new_object(OBJECT_CLASS_TYPE object_class, int id_server = -1);
	void destroy_object(XObject* object);

	bool set_object_server_id(int id_obj, int id_server);
	XObject* find_object(int id);
	XObject* find_server_object(int id_server);
	
	Object_PlayerMySelf *get_my_self() { return my_self_; }

public:
	Node *get_root_layer()  { return root_layer_; }
	void set_root_layer(Node * node) { root_layer_ = node; }

	Game_Map_View *get_view() { return view_; }
	void set_view(Game_Map_View * view) { view_ = view; }

private:
	int id_factory();
	int last_id;

private:
	Object_Map objects_;
	Object_Map server_objects_;

	Object_PlayerMySelf *my_self_;	

private:
	Node *root_layer_;
	Game_Map_View *view_;

	int counter_;
};

/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
