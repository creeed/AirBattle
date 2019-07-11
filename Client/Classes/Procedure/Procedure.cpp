#include "Procedure.h"
#include "GameProcedure.h"
#include "GameMap.h"

/////////////////////////////////////////////////////////////////////////////////////////////
Procedure* Procedure::proc_active_ = NULL;
Procedure* Procedure::proc_prev_ = NULL;

Game_Procedure* Procedure::game_procedure_ = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////
Procedure::Procedure()
{
	root_layer_ = 0;
}

Procedure::~Procedure()
{

}
void Procedure::init_static_memeber()
{
	Game_Map *game_map = new Game_Map;
	game_procedure_ = new Game_Procedure();	

}

void Procedure::release_static_member()
{

}


void Procedure::set_active_proc(Procedure* to_active)
{
	if (NULL == to_active || proc_active_ == to_active)
		return;

	proc_prev_ = proc_active_;
	proc_active_ = to_active;

	if (proc_active_ != proc_prev_)
	{
		if (proc_prev_)
			proc_prev_->cleanup();

		if (proc_active_)
			proc_active_->initialise();

		proc_prev_ = proc_active_;
	}
}

void Procedure::tick_active(uint32_t udt)
{
	if (proc_active_)
		proc_active_->tick(udt);
}

bool Procedure::initialise()
{
	return true;
}

void Procedure::cleanup()
{
	root_layer_ = 0;
}

void Procedure::tick(uint32_t udt)
{
	
}

