#include "ObjectCharacter.h"
#include "ObjectPlayerOther.h"
#include "ObjectPlayerMySelf.h"
#include "ObjectMonster.h"
#include "ObjectBoss.h"
#include "ObjectPlayerBasicBullet.h"
#include "ObjectMoveAimingBullet.h"
#include "ObjectDirectionalBullet.h"

#include "GameMap.h"
#include "GameMapView.h"

#define MAX_REMOVE_SIZE 1024

#define MONSTER_COUNT 73

int monster_table[MONSTER_COUNT][7] = {
		{ 0 /*monster boss*/, 0/*time*/, 50/*x*/, 1200/*y*/, 1000/*hp*/, 20/*attack*/, 0/*movetype*/},
		{ 0 /*monster boss*/, 1/*time*/, 150/*x*/, 1150/*y*/, 1000/*hp*/, 20/*attack*/, 1/*movetype*/ },
		{ 0 /*monster boss*/, 3/*time*/, 200/*x*/, 1170/*y*/, 1000/*hp*/, 20/*attack*/, 2/*movetype*/ },
		{ 0 /*monster boss*/, 5/*time*/, 300/*x*/, 1160/*y*/, 1000/*hp*/, 20/*attack*/, 3/*movetype*/ },
		{ 0 /*monster boss*/, 6/*time*/, 400/*x*/, 1155/*y*/, 1000/*hp*/, 20/*attack*/, 0/*movetype*/ },
		{ 0 /*monster boss*/, 8/*time*/, 500/*x*/, 1168/*y*/, 1000/*hp*/, 20/*attack*/, 1/*movetype*/ },
		{ 0 /*monster boss*/, 10/*time*/, 600/*x*/, 1179/*y*/, 1000/*hp*/, 20/*attack*/, 2/*movetype*/ },
		{ 0 /*monster boss*/, 12/*time*/, 700/*x*/, 1154/*y*/, 1000/*hp*/, 20/*attack*/, 3/*movetype*/ },

		{ 0 /*monster boss*/, 10/*time*/, 50/*x*/, 1200/*y*/, 1000/*hp*/, 20/*attack*/, 0/*movetype*/ },
		{ 0 /*monster boss*/, 13/*time*/, 150/*x*/, 1150/*y*/, 1000/*hp*/, 20/*attack*/, 1/*movetype*/ },
		{ 0 /*monster boss*/, 14/*time*/, 200/*x*/, 1170/*y*/, 1000/*hp*/, 20/*attack*/, 2/*movetype*/ },
		{ 0 /*monster boss*/, 15/*time*/, 300/*x*/, 1160/*y*/, 1000/*hp*/, 20/*attack*/, 3/*movetype*/ },
		{ 0 /*monster boss*/, 17/*time*/, 400/*x*/, 1155/*y*/, 1000/*hp*/, 20/*attack*/, 0/*movetype*/ },
		{ 0 /*monster boss*/, 20/*time*/, 500/*x*/, 1168/*y*/, 1000/*hp*/, 20/*attack*/, 1/*movetype*/ },
		{ 0 /*monster boss*/, 22/*time*/, 600/*x*/, 1179/*y*/, 1000/*hp*/, 20/*attack*/, 2/*movetype*/ },
		{ 0 /*monster boss*/, 23/*time*/, 700/*x*/, 1154/*y*/, 1000/*hp*/, 20/*attack*/, 3/*movetype*/ },

		{ 0 /*monster boss*/, 20/*time*/, 50/*x*/, 1200/*y*/, 1000/*hp*/, 20/*attack*/, 0/*movetype*/ },
		{ 0 /*monster boss*/, 22/*time*/, 150/*x*/, 1150/*y*/, 1000/*hp*/, 20/*attack*/, 1/*movetype*/ },
		{ 0 /*monster boss*/, 24/*time*/, 200/*x*/, 1170/*y*/, 1000/*hp*/, 20/*attack*/, 2/*movetype*/ },
		{ 0 /*monster boss*/, 25/*time*/, 300/*x*/, 1160/*y*/, 1000/*hp*/, 20/*attack*/, 3/*movetype*/ },
		{ 0 /*monster boss*/, 27/*time*/, 400/*x*/, 1155/*y*/, 1000/*hp*/, 20/*attack*/, 0/*movetype*/ },
		{ 0 /*monster boss*/, 28/*time*/, 500/*x*/, 1168/*y*/, 1000/*hp*/, 20/*attack*/, 1/*movetype*/ },
		{ 0 /*monster boss*/, 29/*time*/, 600/*x*/, 1179/*y*/, 1000/*hp*/, 20/*attack*/, 2/*movetype*/ },
		{ 0 /*monster boss*/, 30/*time*/, 700/*x*/, 1154/*y*/, 1000/*hp*/, 20/*attack*/, 3/*movetype*/ },

		{ 0 /*monster boss*/, 32/*time*/, 50/*x*/, 1200/*y*/, 1000/*hp*/, 20/*attack*/, 0/*movetype*/ },
		{ 0 /*monster boss*/, 33/*time*/, 150/*x*/, 1150/*y*/, 1000/*hp*/, 20/*attack*/, 1/*movetype*/ },
		{ 0 /*monster boss*/, 36/*time*/, 200/*x*/, 1170/*y*/, 1000/*hp*/, 20/*attack*/, 2/*movetype*/ },
		{ 0 /*monster boss*/, 37/*time*/, 300/*x*/, 1160/*y*/, 1000/*hp*/, 20/*attack*/, 3/*movetype*/ },
		{ 0 /*monster boss*/, 38/*time*/, 400/*x*/, 1155/*y*/, 1000/*hp*/, 20/*attack*/, 0/*movetype*/ },
		{ 0 /*monster boss*/, 39/*time*/, 500/*x*/, 1168/*y*/, 1000/*hp*/, 20/*attack*/, 1/*movetype*/ },
		{ 0 /*monster boss*/, 40/*time*/, 600/*x*/, 1179/*y*/, 1000/*hp*/, 20/*attack*/, 2/*movetype*/ },
		{ 0 /*monster boss*/, 41/*time*/, 700/*x*/, 1154/*y*/, 1000/*hp*/, 20/*attack*/, 3/*movetype*/ },

		{ 0 /*monster boss*/, 40/*time*/, 50/*x*/, 1200/*y*/, 1000/*hp*/, 20/*attack*/, 0/*movetype*/ },
		{ 0 /*monster boss*/, 42/*time*/, 150/*x*/, 1150/*y*/, 1000/*hp*/, 20/*attack*/, 1/*movetype*/ },
		{ 0 /*monster boss*/, 44/*time*/, 200/*x*/, 1170/*y*/, 1000/*hp*/, 20/*attack*/, 2/*movetype*/ },
		{ 0 /*monster boss*/, 45/*time*/, 300/*x*/, 1160/*y*/, 1000/*hp*/, 20/*attack*/, 3/*movetype*/ },
		{ 0 /*monster boss*/, 47/*time*/, 400/*x*/, 1155/*y*/, 1000/*hp*/, 20/*attack*/, 0/*movetype*/ },
		{ 0 /*monster boss*/, 48/*time*/, 500/*x*/, 1168/*y*/, 1000/*hp*/, 20/*attack*/, 1/*movetype*/ },
		{ 0 /*monster boss*/, 49/*time*/, 600/*x*/, 1179/*y*/, 1000/*hp*/, 20/*attack*/, 2/*movetype*/ },
		{ 0 /*monster boss*/, 52/*time*/, 700/*x*/, 1154/*y*/, 1000/*hp*/, 20/*attack*/, 3/*movetype*/ },

		{ 0 /*monster boss*/, 50/*time*/, 50/*x*/, 1200/*y*/, 1000/*hp*/, 20/*attack*/, 0/*movetype*/ },
		{ 0 /*monster boss*/, 53/*time*/, 150/*x*/, 1150/*y*/, 1000/*hp*/, 20/*attack*/, 1/*movetype*/ },
		{ 0 /*monster boss*/, 54/*time*/, 200/*x*/, 1170/*y*/, 1000/*hp*/, 20/*attack*/, 2/*movetype*/ },
		{ 0 /*monster boss*/, 55/*time*/, 300/*x*/, 1160/*y*/, 1000/*hp*/, 20/*attack*/, 3/*movetype*/ },
		{ 0 /*monster boss*/, 58/*time*/, 400/*x*/, 1155/*y*/, 1000/*hp*/, 20/*attack*/, 0/*movetype*/ },
		{ 0 /*monster boss*/, 59/*time*/, 500/*x*/, 1168/*y*/, 1000/*hp*/, 20/*attack*/, 1/*movetype*/ },
		{ 0 /*monster boss*/, 60/*time*/, 600/*x*/, 1179/*y*/, 1000/*hp*/, 20/*attack*/, 2/*movetype*/ },
		{ 0 /*monster boss*/, 61/*time*/, 700/*x*/, 1154/*y*/, 1000/*hp*/, 20/*attack*/, 3/*movetype*/ },

		{ 0 /*monster boss*/, 60/*time*/, 50/*x*/, 1200/*y*/, 1000/*hp*/, 20/*attack*/, 0/*movetype*/ },
		{ 0 /*monster boss*/, 62/*time*/, 150/*x*/, 1150/*y*/, 1000/*hp*/, 20/*attack*/, 1/*movetype*/ },
		{ 0 /*monster boss*/, 63/*time*/, 200/*x*/, 1170/*y*/, 1000/*hp*/, 20/*attack*/, 2/*movetype*/ },
		{ 0 /*monster boss*/, 65/*time*/, 300/*x*/, 1160/*y*/, 1000/*hp*/, 20/*attack*/, 3/*movetype*/ },
		{ 0 /*monster boss*/, 66/*time*/, 400/*x*/, 1155/*y*/, 1000/*hp*/, 20/*attack*/, 0/*movetype*/ },
		{ 0 /*monster boss*/, 68/*time*/, 500/*x*/, 1168/*y*/, 1000/*hp*/, 20/*attack*/, 1/*movetype*/ },
		{ 0 /*monster boss*/, 69/*time*/, 600/*x*/, 1179/*y*/, 1000/*hp*/, 20/*attack*/, 2/*movetype*/ },
		{ 0 /*monster boss*/, 70/*time*/, 700/*x*/, 1154/*y*/, 1000/*hp*/, 20/*attack*/, 3/*movetype*/ },

		{ 0 /*monster boss*/, 70/*time*/, 50/*x*/, 1200/*y*/, 1000/*hp*/, 20/*attack*/, 0/*movetype*/ },
		{ 0 /*monster boss*/, 72/*time*/, 150/*x*/, 1150/*y*/, 1000/*hp*/, 20/*attack*/, 1/*movetype*/ },
		{ 0 /*monster boss*/, 74/*time*/, 200/*x*/, 1170/*y*/, 1000/*hp*/, 20/*attack*/, 2/*movetype*/ },
		{ 0 /*monster boss*/, 75/*time*/, 300/*x*/, 1160/*y*/, 1000/*hp*/, 20/*attack*/, 3/*movetype*/ },
		{ 0 /*monster boss*/, 77/*time*/, 400/*x*/, 1155/*y*/, 1000/*hp*/, 20/*attack*/, 0/*movetype*/ },
		{ 0 /*monster boss*/, 78/*time*/, 500/*x*/, 1168/*y*/, 1000/*hp*/, 20/*attack*/, 1/*movetype*/ },
		{ 0 /*monster boss*/, 79/*time*/, 600/*x*/, 1179/*y*/, 1000/*hp*/, 20/*attack*/, 2/*movetype*/ },
		{ 0 /*monster boss*/, 80/*time*/, 700/*x*/, 1154/*y*/, 1000/*hp*/, 20/*attack*/, 3/*movetype*/ },

		{ 0 /*monster boss*/, 81/*time*/, 50/*x*/, 1200/*y*/, 1000/*hp*/, 20/*attack*/, 0/*movetype*/ },
		{ 0 /*monster boss*/, 82/*time*/, 150/*x*/, 1150/*y*/, 1000/*hp*/, 20/*attack*/, 1/*movetype*/ },
		{ 0 /*monster boss*/, 83/*time*/, 200/*x*/, 1170/*y*/, 1000/*hp*/, 20/*attack*/, 2/*movetype*/ },
		{ 0 /*monster boss*/, 85/*time*/, 300/*x*/, 1160/*y*/, 1000/*hp*/, 20/*attack*/, 3/*movetype*/ },
		{ 0 /*monster boss*/, 86/*time*/, 400/*x*/, 1155/*y*/, 1000/*hp*/, 20/*attack*/, 0/*movetype*/ },
		{ 0 /*monster boss*/, 88/*time*/, 500/*x*/, 1168/*y*/, 1000/*hp*/, 20/*attack*/, 1/*movetype*/ },
		{ 0 /*monster boss*/, 89/*time*/, 600/*x*/, 1179/*y*/, 1000/*hp*/, 20/*attack*/, 2/*movetype*/ },
		{ 0 /*monster boss*/, 90/*time*/, 700/*x*/, 1154/*y*/, 1000/*hp*/, 20/*attack*/, 3/*movetype*/ },

		{ 1 /*monster boss*/, 96/*time*/, 360/*x*/, 1154/*y*/, 10000/*hp*/, 20/*attack*/, 3/*movetype*/ },
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
template<> Game_Map* Singleton<Game_Map>::singleton_ = 0;
Game_Map* Game_Map::singleton()
{
	return singleton_;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
Game_Map::Game_Map()
{
	my_self_ = 0;
	last_id = 0;

	root_layer_ = 0;
	view_ = 0;

	counter_ = 0;
}

Game_Map::~Game_Map()
{
}

bool Game_Map::initialise()
{
	view_ = Game_Map_View::create(this);
	root_layer_->addChild(view_);

	Object_PlayerMySelf *myself = (Object_PlayerMySelf *)new_object(OBJECT_CLASS_TYPE_PLAYERMYSELF);
	Object_Player_MySelf_Init myself_init;
	myself_init.x_ = WINDOW_WIDTH / 2.0f;
	myself_init.y_ = 200.0f;
	myself_init.hp_ = 10000;
	myself_init.attack_ = 30;
	myself->initialise(&myself_init);

	//Object_Monster *monster = (Object_Monster *)new_object(OBJECT_CLASS_TYPE_MONSTER);
	//Object_Monster_Init monster_init;
	//monster_init.x_ = rand() % WINDOW_WIDTH;
	//monster_init.y_ = WINDOW_HEIGHT;
	//monster_init.move_type_ = 3;
	//monster_init.hp_ = 1000;
	//monster_init.attack_ = 20;
	//monster->initialise(&monster_init);

	//Object_Boss *boss = (Object_Boss *)new_object(OBJECT_CLASS_TYPE_BOSS);
	//Object_Boss_Init boss_init;
	//boss_init.x_ = WINDOW_WIDTH / 2.0f;
	//boss_init.y_ = WINDOW_HEIGHT;
	//boss_init.hp_ = 10000;
	//boss_init.attack_ = 10;
	//boss->initialise(&boss_init);

	return true;
}

void Game_Map::cleanup()
{
	for (Object_Map::iterator i = objects_.begin(); i != objects_.end(); ++i)
	{
		//SAFE_DELETE(i->second);
	}

	objects_.clear();
	server_objects_.clear();

	root_layer_ = 0;
	view_ = 0;
}

XObject* Game_Map::new_object(OBJECT_CLASS_TYPE object_class, int id_server)
{
	if (id_server != -1)
	{
		XObject* ifind = (XObject*)find_server_object(id_server);
		//如果已经有
		if (ifind != NULL)
		{
			return ifind;
		}
	}

	int id = id_factory();
	XObject *new_object = 0;

	if (object_class == OBJECT_CLASS_TYPE_PLAYERMYSELF)
	{
		new_object = new Object_PlayerMySelf;
		my_self_ = (Object_PlayerMySelf*)new_object;
	}
	else if (object_class == OBJECT_CLASS_TYPE_PLAYEROTHER)
	{
		new_object = new Object_PlayerOther;
	}
	else if (object_class == OBJECT_CLASS_TYPE_MONSTER)
	{
		new_object = new Object_Monster;
	}
	else if (object_class == OBJECT_CLASS_TYPE_BOSS)
	{
		new_object = new Object_Boss;
	}
	else if (object_class == OBJECT_CLASS_TYPE_PLAYERBASICBULLET)
	{
		new_object = new Object_Player_Basic_Bullet;
	}
	else if (object_class == OBJECT_CLASS_TYPE_MOVEAIMINGBULLET)
	{
		new_object = new Object_Move_Aiming_Bullet;
	}
	else if (object_class == OBJECT_CLASS_TYPE_DIRECTIONALBULLET)
	{
		new_object = new Object_Directional_Bullet;
	}
	else
	{
		assert(false);
	}

	new_object->set_id(id);
	new_object->set_server_id(id_server);

	objects_[new_object->get_id()] = new_object;

	if (id_server != INVALID)
	{
		server_objects_[id_server] = new_object;
	}

	return new_object;
}

void Game_Map::destroy_object(XObject* object)
{
	if (object == my_self_)
	{
		my_self_ = 0;
	}

	int id = object->get_id();
	int id_server = object->get_server_id();

	objects_.erase(id);
	server_objects_.erase(id_server);

	object->cleanup();
	delete object;
}

XObject* Game_Map::find_object(int id)
{
	if (id == INVALID)
		return 0;

	Object_Map::iterator ifind = objects_.find(id);

	if (ifind == objects_.end()) return 0;
	else return ifind->second;
}

XObject* Game_Map::find_server_object(int id_server)
{
	if (id_server == INVALID)
		return 0;

	Object_Map::iterator ifind = server_objects_.find(id_server);

	if (ifind == server_objects_.end())
		return 0;
	else
		return ifind->second;
}

bool Game_Map::set_object_server_id(int id_obj, int id_server)
{
	if (id_obj != INVALID)
	{
		XObject *object = find_object(id_obj);
		if (object != NULL)
		{
			int id_old_server = object->get_server_id();
			if (id_old_server != INVALID)
				server_objects_.erase(id_old_server);

			if (id_server != INVALID)
				server_objects_[id_server] = object;

			object->set_server_id(id_server);
		}
	}

	return true;
}


int Game_Map::id_factory()
{
	return ++last_id;
}

bool Game_Map::tick(uint32_t udt)
{
	uint32_t remove_count = 0;
	XObject *need_remove[MAX_REMOVE_SIZE];
	memset(need_remove, 0, sizeof(XObject *)* MAX_REMOVE_SIZE);

	for (auto i = objects_.begin(); i != objects_.end(); ++i)
		for (auto j = objects_.begin(); j != objects_.end(); ++j)
		{
		XObject *obj1 = i->second;
		XObject *obj2 = j->second;

		if (obj1 != obj2)
		{
			if (!obj1->is_dead() && !obj2->is_dead())
			{
				obj1->check_hit(obj2);
			}
		}
		}

	for (auto i = objects_.begin(); i != objects_.end(); ++i)
	{
		bool ret = i->second->heartbeat(udt);

		if (!ret)
		{
			need_remove[remove_count++] = i->second;
		}
	}

	for (int i = remove_count - 1; i >= 0; i--)
	{
		XObject *obj = (XObject*)(need_remove[i]);
		if (obj != NULL)
		{
			destroy_object(obj);
		}
	}

	monster_producer();

	if (view_)
		view_->heartbeat(udt);

	return true;
}

bool Game_Map::monster_producer()
{
	for (int i = 0; i < MONSTER_COUNT; i++)
	{
		if ((float)monster_table[i][1] == counter_ / 50.0f)
		{
			if (monster_table[i][0] == OBJECT_CLASS_TYPE_MONSTER)
			{
				Object_Monster *monster = (Object_Monster *)new_object(OBJECT_CLASS_TYPE_MONSTER);
				Object_Monster_Init monster_init;
				monster_init.x_ = monster_table[i][2];
				monster_init.y_ = monster_table[i][3];
				monster_init.hp_ = monster_table[i][4];
				monster_init.attack_ = monster_table[i][5];
				monster_init.move_type_ = monster_table[i][6];
				monster->initialise(&monster_init);
			}
			else if (monster_table[i][0] == OBJECT_CLASS_TYPE_BOSS)
			{
				Object_Boss *boss = (Object_Boss *)new_object(OBJECT_CLASS_TYPE_BOSS);
				Object_Boss_Init boss_init;
				boss_init.x_ = monster_table[i][2];
				boss_init.y_ = monster_table[i][3];
				boss_init.hp_ = monster_table[i][4];
				boss_init.attack_ = monster_table[i][5];
				boss_init.move_type_ = monster_table[i][6];
				boss->initialise(&boss_init);
			}

		}
	}

	counter_++;

	return true;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////