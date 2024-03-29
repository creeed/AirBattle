#ifndef __DEFINE_H__
#define __DEFINE_H__

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define WINDOW_WIDTH 720
#define WINDOW_HEIGHT 1280

#define OUTOFF_SCREEN 500

////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum LAYER_ORDER
{
	LAYER_ORDER_MAP_FAR = 1,
	LAYER_ORDER_MAP_MIDDLE ,
	LAYER_ORDER_MAP_LAND,
	LAYER_ORDER_OBJECT,
	LAYER_ORDER_OBJECT_EFFECT,
	LAYER_ORDER_MAP_NEAR ,
	LAYER_ORDER_MAP_EFFECT,
	LAYER_ORDER_MAP_EFFECT_ABSOLUTEPOS,

	LAYER_ORDER_UI,
};



/////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif