#include "GameMapView.h"
#include "GameMap.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Game_Map_View::Game_Map_View(Game_Map *game_map)
	:game_map_(game_map)
{
	bg_speed_ = 1.0f;
	bg_map_ = 0;
	bg_index_ = 0;
}

Game_Map_View::~Game_Map_View()
{
}

Game_Map_View * Game_Map_View::create(Game_Map *game_map)
{
	Game_Map_View *view = new Game_Map_View(game_map);

	if (view && view->init(game_map))
	{
		view->autorelease();
		return view;
	}

	return NULL;
}

bool Game_Map_View::init(Game_Map *game_map)
{
	game_map_ = game_map;

	map_layer_far_ = Layer::create();
	addChild(map_layer_far_, LAYER_ORDER_MAP_FAR);

	map_layer_middle_ = Layer::create();
	addChild(map_layer_middle_, LAYER_ORDER_MAP_MIDDLE);

	map_layer_land_ = Layer::create();
	addChild(map_layer_land_, LAYER_ORDER_MAP_LAND);

	map_layer_object_ = Layer::create();
	addChild(map_layer_object_, LAYER_ORDER_OBJECT);

	map_layer_object_effect_ = Layer::create();
	addChild(map_layer_object_effect_, LAYER_ORDER_OBJECT_EFFECT);

	map_layer_near_ = Layer::create();
	addChild(map_layer_near_, LAYER_ORDER_MAP_NEAR);

	map_layer_effect_ = Layer::create();
	addChild(map_layer_effect_, LAYER_ORDER_MAP_EFFECT);

	map_layer_effect_absolutepos_ = Layer::create();
	addChild(map_layer_effect_absolutepos_, LAYER_ORDER_MAP_EFFECT_ABSOLUTEPOS);

	bg_map_ = Layer::create();
	map_layer_far_->addChild(bg_map_);

	Sprite *spr_bg0 = Sprite::create("background1-sheet1.png");
	spr_bg0->setTag(0);
	spr_bg0->setAnchorPoint(Point(0, 0));
	bg_map_->addChild(spr_bg0);

	Sprite *spr_bg1 = Sprite::create("background2-sheet1.png");
	spr_bg1->setTag(1);
	spr_bg1->setAnchorPoint(Point(0, 0));
	spr_bg1->setPosition(0, WINDOW_HEIGHT);
	bg_map_->addChild(spr_bg1);

	return true;
}

Layer *Game_Map_View::get_map_layer(int layer_order)
{
	switch (layer_order)
	{
	case LAYER_ORDER_MAP_FAR:
	{
		return map_layer_far_;
	}
	case LAYER_ORDER_MAP_MIDDLE:
	{
		return map_layer_middle_;
	}
	case LAYER_ORDER_MAP_LAND:
	{
		return map_layer_land_;
	}
	case LAYER_ORDER_OBJECT:
	{
		return map_layer_object_;
	}
	case LAYER_ORDER_OBJECT_EFFECT:
	{
		return map_layer_object_effect_;
	}
	case LAYER_ORDER_MAP_NEAR:
	{
		return map_layer_near_;
	}
	case LAYER_ORDER_MAP_EFFECT:
	{
		return map_layer_effect_;
	}
	case LAYER_ORDER_MAP_EFFECT_ABSOLUTEPOS:
	{
		return map_layer_effect_absolutepos_;
	}
	default:
	{
		assert(false);
		return NULL;
	}
	}
}

bool Game_Map_View::heartbeat(uint32_t udt)
{
	if (bg_map_)
	{
		bg_map_->setPositionY(bg_map_->getPositionY() - bg_speed_);

		int posy = bg_map_->getPositionY();

		if (abs(posy) >= WINDOW_HEIGHT * (bg_index_ + 1))
		{
			Sprite *spr_bg = (Sprite *)bg_map_->getChildByTag(bg_index_ % 2);
			assert(spr_bg);

			if (spr_bg)
			{
				spr_bg->setPositionY(spr_bg->getPositionY() + 2 * WINDOW_HEIGHT);
			}

			bg_index_++;
		}
	}
	    

	return true;
}




/////////////////////////////////////////////////////////////////////////////////////////////////////