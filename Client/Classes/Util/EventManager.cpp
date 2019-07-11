#include "TimeManager.h"
#include "EventManager.h"

//////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////
template<> Event_Manager* Singleton<Event_Manager>::singleton_ = 0;
Event_Manager* Event_Manager::singleton()
{
    return singleton_;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
Event_Manager::Event_Manager()
{
	last_tick_count_ = 0;

	game_event_defines_ = new Game_Event_Define[GAME_EVENT_NUMBER];

	for (int i = 0; i < GAME_EVENT_NUMBER; i++)
	{
		game_event_defines_[i].game_event_id_ = (Game_Event_ID)i;   //
		game_event_defines_[i].delay_process_ = false;
		event_index_as_id_[game_event_defines_[i].game_event_id_] = &game_event_defines_[i];
	}
}

Event_Manager::~Event_Manager()
{
	//SAFE_DELETE_ARRAY(game_event_defines_);
}

bool Event_Manager::initialise()
{

	return true ;
}

void Event_Manager::cleanup()
{
	unregister_all_event_handle();

	queue_event_.clear();
	delay_queue_event_.clear();
}

void Event_Manager::tick()
{
    process_all_event();
}

void Event_Manager::register_event_handle(Game_Event_ID event_id, Func_Event_Handle fun_handle, uint32_t owner_data)
{
	Game_Event_Define* pevent = event_index_as_id_[event_id];

	if (!pevent)
	{
		return;
	}

	pevent->func_notifys_.push_back(std::make_pair(fun_handle, owner_data));
}

void Event_Manager::unregister_event_handle(Game_Event_ID event_id)
{
	Game_Event_Define* pevent = event_index_as_id_[event_id];

	if (!pevent)
	{
		return;
	}

	pevent->func_notifys_.clear();
}

void Event_Manager::unregister_event_handle(Game_Event_ID event_id, uint32_t owner_data)
{
	Game_Event_Define* pevent = event_index_as_id_[event_id];

	if (!pevent)
	{
		return;
	}

	if (!(pevent->func_notifys_.empty()))
	{
		Func_Notifys::iterator iend = pevent->func_notifys_.end();
		for (Func_Notifys::iterator i = pevent->func_notifys_.begin(); i != iend; i++)
		{
			if ((*i).second == owner_data)
			{
				pevent->func_notifys_.erase(i);
				return;
			}
				
		}
	}
}

void Event_Manager::unregister_all_event_handle()
{
	for (int i = 0; i < GAME_EVENT_NUMBER; i++)
	{
		game_event_defines_[i].func_notifys_.clear();   //
	}
}

void Event_Manager::push_event(Game_Event_ID id, const std::vector< std::string >& vparam)
{
	if (event_index_as_id_.find(id) == event_index_as_id_.end())
	{
		return;
	}

	Game_Event event;
	event.event_define_ = event_index_as_id_[id];

	event.arg_ = vparam;

	push_event(event);
}

void Event_Manager::push_event(Game_Event_ID id)
{
	if (event_index_as_id_.find(id) == event_index_as_id_.end())
	{
		return;
	}

	Game_Event event;
	event.event_define_ = event_index_as_id_[id];

	push_event(event);
}

void Event_Manager::push_event(Game_Event_ID id, int arg0)
{
	if (event_index_as_id_.find(id) == event_index_as_id_.end())
	{
		return;
	}

	Game_Event event;
	event.event_define_ = event_index_as_id_[id];

	char temp[32];
	snprintf(temp, 32, "%d", arg0);
	event.arg_.push_back(temp);

	push_event(event);
}

void Event_Manager::push_event(Game_Event_ID id, int arg0, int64_t arg1)
{
	if (event_index_as_id_.find(id) == event_index_as_id_.end())
	{
		return;
	}

	Game_Event event;
	event.event_define_ = event_index_as_id_[id];

	char temp[32];

	snprintf(temp, 32, "%d", arg0);
	event.arg_.push_back(temp);

	snprintf(temp, 32, "%I64d", arg1);
	event.arg_.push_back(temp);

	push_event(event);
}

void Event_Manager::push_event(Game_Event_ID id, int arg0, const char *arg1)
{
	if (event_index_as_id_.find(id) == event_index_as_id_.end())
	{
		return;
	}

	Game_Event event;
	event.event_define_ = event_index_as_id_[id];

	char temp[32];

	snprintf(temp, 32, "%d", arg0);
	event.arg_.push_back(temp);

	event.arg_.push_back(arg1);

	push_event(event);
}


void Event_Manager::push_event(Game_Event_ID id, float arg0)
{
	if (event_index_as_id_.find(id) == event_index_as_id_.end())
	{
		return;
	}

	Game_Event event;
	event.event_define_ = event_index_as_id_[id];

	char temp[32];
	snprintf(temp, 32, "%f", arg0);
	event.arg_.push_back(temp);

	push_event(event);
}

void Event_Manager::push_event(Game_Event_ID id, const char *arg0)
{
	if (event_index_as_id_.find(id) == event_index_as_id_.end())
	{
		return;
	}

	Game_Event event;
	event.event_define_ = event_index_as_id_[id];

	event.arg_.push_back(arg0);

	push_event(event);
}

void Event_Manager::push_event(Game_Event_ID id, const char *arg0, int arg1)
{
	if (event_index_as_id_.find(id) == event_index_as_id_.end())
	{
		return;
	}

	Game_Event event;
	event.event_define_ = event_index_as_id_[id];

	event.arg_.push_back(arg0);

	char temp[32];
	snprintf(temp, 32, "%d", arg1);
	event.arg_.push_back(temp);

	push_event(event);
}

void Event_Manager::push_event(Game_Event_ID id, const char *arg0, int arg1, int arg2)
{
	if (event_index_as_id_.find(id) == event_index_as_id_.end())
	{
		return;
	}

	Game_Event event;
	event.event_define_ = event_index_as_id_[id];

	event.arg_.push_back(arg0);

	char temp[32];
	snprintf(temp, 32, "%d", arg1);
	event.arg_.push_back(temp);

	snprintf(temp, 32, "%d", arg2);
	event.arg_.push_back(temp);

	push_event(event);
}

void Event_Manager::push_event(Game_Event_ID id, const char *arg0, int arg1, int arg2, int arg3)
{
	if (event_index_as_id_.find(id) == event_index_as_id_.end())
	{
		return;
	}

	Game_Event event;
	event.event_define_ = event_index_as_id_[id];

	event.arg_.push_back(arg0);

	char temp[32];
	snprintf(temp, 32, "%d", arg1);
	event.arg_.push_back(temp);

	snprintf(temp, 32, "%d", arg2);
	event.arg_.push_back(temp);

	snprintf(temp, 32, "%d", arg3);
	event.arg_.push_back(temp);

	push_event(event);
}

void Event_Manager::push_event(Game_Event_ID id, const char *arg0, float arg1)
{
	if (event_index_as_id_.find(id) == event_index_as_id_.end())
	{
		return;
	}

	Game_Event event;
	event.event_define_ = event_index_as_id_[id];

	event.arg_.push_back(arg0);

	char temp[32];
	snprintf(temp, 32, "%f", arg1);
	event.arg_.push_back(temp);

	push_event(event);
}

void Event_Manager::push_event(Game_Event_ID id, const char *arg0, float arg1, float arg2)
{
	if (event_index_as_id_.find(id) == event_index_as_id_.end())
	{
		return;
	}

	Game_Event event;
	event.event_define_ = event_index_as_id_[id];

	event.arg_.push_back(arg0);

	char temp[32];
	snprintf(temp, 32, "%f", arg1);
	event.arg_.push_back(temp);

	snprintf(temp, 32, "%f", arg2);
	event.arg_.push_back(temp);

	push_event(event);
}

void Event_Manager::push_event(Game_Event_ID id, const char *arg0, const char *arg1)
{
	if (event_index_as_id_.find(id) == event_index_as_id_.end())
	{
		return;
	}

	Game_Event event;
	event.event_define_ = event_index_as_id_[id];

	event.arg_.push_back(arg0);
	event.arg_.push_back(arg1);

	push_event(event);
}

void Event_Manager::push_event(Game_Event_ID id, const char *arg0, const char *arg1, int arg2 )
{
	if (event_index_as_id_.find(id) == event_index_as_id_.end())
	{
		return;
	}

	Game_Event event;
	event.event_define_ = event_index_as_id_[id];

	event.arg_.push_back(arg0);
	event.arg_.push_back(arg1);

	char temp[32];
	snprintf(temp, 32, "%d", arg2);
	event.arg_.push_back(temp);

	push_event(event);
}

void Event_Manager::push_event(Game_Event_ID id, int arg0, int arg1)
{
	if (event_index_as_id_.find(id) == event_index_as_id_.end())
	{
		return;
	}

	Game_Event event;
	event.event_define_ = event_index_as_id_[id];

	char temp[32];
	snprintf(temp, 32, "%d", arg0);
	event.arg_.push_back(temp);

	snprintf(temp, 32, "%d", arg1);
	event.arg_.push_back(temp);

	push_event(event);
}

void Event_Manager::push_event(Game_Event_ID id, int arg0, int arg1, int arg2)
{
	if (event_index_as_id_.find(id) == event_index_as_id_.end())
	{
		return;
	}

	Game_Event event;
	event.event_define_ = event_index_as_id_[id];

	char temp[32];
	snprintf(temp, 32, "%d", arg0);
	event.arg_.push_back(temp);

	snprintf(temp, 32, "%d", arg1);
	event.arg_.push_back(temp);

	snprintf(temp, 32, "%d", arg2);
	event.arg_.push_back(temp);

	push_event(event);
}


void Event_Manager::push_event(Game_Event_ID id, int arg0, int arg1, int arg2, int arg3)
{
	if (event_index_as_id_.find(id) == event_index_as_id_.end())
	{
		return;
	}

	Game_Event event;
	event.event_define_ = event_index_as_id_[id];

	char temp[32];
	snprintf(temp, 32, "%d", arg0);
	event.arg_.push_back(temp);

	snprintf(temp, 32, "%d", arg1);
	event.arg_.push_back(temp);

	snprintf(temp, 32, "%d", arg2);
	event.arg_.push_back(temp);

	snprintf(temp, 32, "%d", arg3);
	event.arg_.push_back(temp);

	push_event(event);
}


void Event_Manager::push_event(Game_Event_ID id, int arg0, int arg1, int arg2, int arg3, int arg4)
{
	if (event_index_as_id_.find(id) == event_index_as_id_.end())
	{
		return;
	}

	Game_Event event;
	event.event_define_ = event_index_as_id_[id];

	char temp[32];
	snprintf(temp, 32, "%d", arg0);
	event.arg_.push_back(temp);

	snprintf(temp, 32, "%d", arg1);
	event.arg_.push_back(temp);

	snprintf(temp, 32, "%d", arg2);
	event.arg_.push_back(temp);

	snprintf(temp, 32, "%d", arg3);
	event.arg_.push_back(temp);

	snprintf(temp, 32, "%d", arg4);
	event.arg_.push_back(temp);

	push_event(event);
}

void Event_Manager::push_event(Game_Event_ID id, const char *arg0, const char *arg1, int arg2, int arg3)
{
	if (event_index_as_id_.find(id) == event_index_as_id_.end())
	{
		return;
	}

	Game_Event event;
	event.event_define_ = event_index_as_id_[id];

	event.arg_.push_back(arg0);
	event.arg_.push_back(arg1);


	char temp[32];
	snprintf(temp, 32, "%d", arg2);
	event.arg_.push_back(temp);

	snprintf(temp, 32, "%d", arg3);
	event.arg_.push_back(temp);

	push_event(event);
}



void Event_Manager::process_all_event()
{
	if(!(delay_queue_event_.empty()))
	{
		const uint32_t WORK_STEP = 2;
		uint32_t tick_count_now = Time_Manager::singleton()->get_tick_count();
		uint32_t tick_count_step = Time_Manager::singleton()->cal_sub_time(last_tick_count_, tick_count_now);

		if(tick_count_step >= WORK_STEP) 
		{
			last_tick_count_ = tick_count_now;

			const Game_Event& event = *(delay_queue_event_.begin());

			process_event(event);

			delay_queue_event_.erase(delay_queue_event_.begin());
		}
	}

	std::list< Game_Event >::iterator i;
	for(i = queue_event_.begin(); i != queue_event_.end(); i++)
	{
		const Game_Event& event = *i;

		process_event(event);
	}

	queue_event_.clear();
}

void Event_Manager::clean_all_event()
{
	delay_queue_event_.clear();
	queue_event_.clear();
}

void Event_Manager::push_event(const Game_Event& event)
{
	if (!event.event_define_)
	{
		return;
	}

	if(event.event_define_->delay_process_)
	{
		delay_queue_event_.push_back(event);
	}
	else
	{
		queue_event_.push_back(event);
	}
}

void Event_Manager::process_event(const Game_Event& event)
{
	Game_Event_Define* event_define = event.event_define_;
	if (!event_define)
	{
		return;
	}

	if(!(event_define->func_notifys_.empty()))
	{
		Func_Notifys::iterator iend = event_define->func_notifys_.end();
		for (Func_Notifys::iterator i = event_define->func_notifys_.begin(); i != iend; i++)
		{
			if((*i).first)
				((*i).first)(&event, (*i).second);
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

