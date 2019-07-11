#include "ObjectSplitBullet.h"
#include "ObjectSplitBulletView.h"
#include "GameMap.h"
#include "GameMapView.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
Object_Split_Bullet::Object_Split_Bullet()
{
	butllet_counter_ = 0;
}

Object_Split_Bullet::~Object_Split_Bullet()
{
}

bool Object_Split_Bullet::initialise(const Object_Init *init)
{
	if (!Object_Monster_Bullet::initialise(init))
		return false;

	Object_Split_Bullet_Init *pinit = (Object_Split_Bullet_Init *)init;

	float speed = 3.0f;
	float x_enemy = get_pos_x();
	float y_enemy = get_pos_y();

	float x_player = pinit->player_->get_pos_x();
	float y_player = pinit->player_->get_pos_y();

	float distance = sqrt((x_player - x_enemy) * (x_player - x_enemy)
		+ (y_player - y_enemy) * (y_player - y_enemy));

	if (distance != 0.0f) 
	{
		vx_ = ((x_player - x_enemy) / distance) * speed;
		vy_ = ((y_player - y_enemy) / distance) * speed;
	}
	else
	{
		vx_ = 0.0f;
		vy_ = -speed;
	}

	view_ = Object_Split_Bullet_View::create(this);
	Game_Map::singleton()->get_view()->get_map_layer(LAYER_ORDER_OBJECT)->addChild(view_);

	hit_rect_.set_rect(-70, -57, 70, 57);

	return true;
}

void Object_Split_Bullet::move(uint32_t udt)
{
	float x = get_pos_x();
	float y = get_pos_y();

	x += vx_;
	y += vy_;

	if (butllet_counter_ == 50)
	{
		theta = 15F;
		n = 12;
		vxNWay = new float[n];
		vyNWay = new float[n];
		float rad_step = (float)(0.017453292519943295D * (double)theta);
		float rad = (float)(((double)(-n / 2) + 0.5D) * (double)rad_step);
		for (int i = 0; i < n;)
		{
			float c = (float)Math.cos(rad);
			float s = (float)Math.sin(rad);
			vxNWay[i] = vx0 * c - vy0 * s;
			vyNWay[i] = vx0 * s + vy0 * c;
			GamePanel.addList(new EnemyShot(x, y, vxNWay[i], vyNWay[i]));
			i++;
			rad += rad_step;
		}

		vx = vxNWay[0];
		vy = vyNWay[0];

		on_dead();
	}

	set_pos(x, y);

	butllet_counter_++;

	if (x - OUTOFF_SCREEN > WINDOW_WIDTH
		|| x + OUTOFF_SCREEN < 0.0f
		|| y - OUTOFF_SCREEN > WINDOW_HEIGHT
		|| y + OUTOFF_SCREEN < 0.0f)
	{
		on_dead();
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
