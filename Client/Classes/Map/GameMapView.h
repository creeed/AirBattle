#ifndef __GAME_MAP_VIEW_H__
#define __GAME_MAP_VIEW_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "Object.h"

class Game_Map;

/////////////////////////////////////////////////////////////////////////////////////////////////
class Game_Map_View : public Node
{
public:
	Game_Map_View(Game_Map *game_map);
	virtual ~Game_Map_View();

	static Game_Map_View *create(Game_Map *game_map);

public:
	bool init(Game_Map *game_map);

	bool heartbeat(uint32_t udt);

	Layer *get_map_layer(int layer_order);

protected:
	Game_Map *game_map_;

	Layer *map_layer_far_;
	Layer *map_layer_middle_;
	Layer *map_layer_land_;
	Layer *map_layer_object_;
	Layer *map_layer_object_effect_;
	Layer *map_layer_near_;
	Layer *map_layer_effect_;
	Layer *map_layer_effect_absolutepos_;

	Layer *bg_map_;

private:
	int bg_speed_;
	int bg_index_;
};



/////////////////////////////////////////////////////////////////////////////////////////////////
#endif
