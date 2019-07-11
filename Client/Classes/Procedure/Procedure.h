#ifndef __PROCEDURE_H__
#define __PROCEDURE_H__

////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"

class Game_Procedure;

////////////////////////////////////////////////////////////////////////////////////////////////////////
class Procedure 
{
public:
	Procedure();
	virtual ~Procedure();

public:
	static void init_static_memeber();
	static void release_static_member();
	static void set_active_proc(Procedure* to_active);
	static Procedure *get_active_proc() { return proc_active_; }
	static void tick_active(uint32_t udt);

public:
    virtual bool initialise();
	virtual void cleanup();

	virtual void tick(uint32_t udt);
	
public:
	static Game_Procedure* game_procedure_;

protected:
	static Procedure* proc_active_;
	static Procedure* proc_prev_;

protected:
	Layer *root_layer_;
};

////////////////////////////////////////////////////////////////////////////////////////////

#endif 