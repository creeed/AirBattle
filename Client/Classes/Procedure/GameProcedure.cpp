#include "GameProcedure.h"
#include "GameScene.h"
#include "GameMap.h"
#include "ObjectPlayerMySelf.h"


/////////////////////////////////////////////////////////////////////////////////////////////
Game_Procedure::Game_Procedure()
{
	mouse_down_ = false;
}

Game_Procedure::~Game_Procedure()
{
}

bool Game_Procedure::initialise()
{
	auto director = Director::getInstance();
	Game_Map *game_map = Game_Map::singleton();

	root_layer_ = Game_Scene::createScene();
	director->replaceScene((Scene*)root_layer_->getParent());
	game_map->set_root_layer(root_layer_);
	game_map->initialise();

	return true;
}

void Game_Procedure::cleanup()
{
	mouse_down_ = false;
}

void Game_Procedure::tick(uint32_t udt)
{
	Procedure::tick(udt);

	Game_Map *game_map = Game_Map::singleton();
	game_map->tick(udt);

	if (mouse_down_)
	{
		Object_PlayerMySelf *myself = game_map->get_my_self();

		if (myself)
		{
			float oldx = myself->get_x();
			float oldy = myself->get_y();

			float newdx = mouse_pt_.x_ - mouse_dist_.x_;
			float newdy = mouse_pt_.y_ - mouse_dist_.y_;

			myself->set_x(newdx);
			myself->set_y(newdy);

			myself->set_vx(newdx - oldx);
			myself->set_vy(newdy - oldy);
		}

	}
	
}
