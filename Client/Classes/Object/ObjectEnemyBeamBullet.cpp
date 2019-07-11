#include "ObjectEnemyBeamBullet.h"
#include "ObjectEnemyBeamBulletView.h"
#include "GameMap.h"
#include "GameMapView.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_Enemy_Beam_Bullet::Object_Enemy_Beam_Bullet()
{
	enemy_ = 0;
}

Object_Enemy_Beam_Bullet::~Object_Enemy_Beam_Bullet()
{
}

bool Object_Enemy_Beam_Bullet::initialise(const Object_Init *init)
{
	if (!Object_Monster_Bullet::initialise(init))
		return false;

	Object_Enemy_Beam_Bullet_Init *pinit = (Object_Enemy_Beam_Bullet_Init *)init;

	vx_ = 0.0f;
	vy_ = -4.0f;

	enemy_ = pinit->enemy_;

	view_ = Object_Enemy_Beam_Bullet_View::create(this);
	Game_Map::singleton()->get_view()->get_map_layer(LAYER_ORDER_OBJECT)->addChild(view_);

	hit_rect_.set_rect(-70, -57, 70, 57);

	return true;
}

void Object_Enemy_Beam_Bullet::move(uint32_t udt)
{
	float x = get_pos_x();
	float y = get_pos_y();

	x += vx_ + enemy_->get_vx(); 
	y += vy_ + enemy_->get_vy();

	set_pos(x, y);

	if (x - OUTOFF_SCREEN > WINDOW_WIDTH
		|| x + OUTOFF_SCREEN < 0.0f
		|| y - OUTOFF_SCREEN > WINDOW_HEIGHT
		|| y + OUTOFF_SCREEN < 0.0f)
	{
		on_dead();
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
