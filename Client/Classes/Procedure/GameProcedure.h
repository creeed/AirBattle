#ifndef __GAME_PROCEDURE_H__
#define __GAME_PROCEDURE_H__

////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "Procedure.h"

class Game_Scene;

////////////////////////////////////////////////////////////////////////////////////////////////////////
class Game_Procedure : public Procedure
{
public:
	Game_Procedure();
	virtual ~Game_Procedure();

    virtual bool initialise();
	virtual void cleanup();

	virtual void tick(uint32_t udt);

public:
	bool get_mouse_down() const { return mouse_down_; }
	void set_mouse_down(bool mouse_down) { mouse_down_ = mouse_down; }

	World_Point get_mouse_pt() const { return mouse_pt_; }
	void set_mouse_pt(const World_Point &mouse_pt) { mouse_pt_ = mouse_pt; }

	World_Point get_mouse_dist() const { return mouse_dist_; }
	void set_mouse_dist(const World_Point &mouse_dist) { mouse_dist_ = mouse_dist; }

private:
	bool mouse_down_;
	World_Point mouse_pt_;
	World_Point mouse_dist_;
};

////////////////////////////////////////////////////////////////////////////////////////////

#endif