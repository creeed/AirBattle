#include "TimeManager.h"
#include "OsApi.h"

//////////////////////////////////////////////////////////////////////////////////////////////////
template<> Time_Manager* Singleton<Time_Manager>::singleton_ = 0;
Time_Manager* Time_Manager::singleton()
{
    return singleton_;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
Time_Manager::Time_Manager()
{
	time_now_ = 0;
	loop_time_ = 0;
	delta_time_ = 0;
	real_time_ = 0;
	fps_ = 0;
	tick_count_ = 0;

	time_now_ = gettickcount_os();
}

Time_Manager::~Time_Manager()
{
}

bool Time_Manager::initialise()
{
	time_now_ = 0;
	loop_time_ = 0;
	delta_time_ = 0;
	real_time_ = 0;
	fps_ = 0;
	tick_count_ = 0;

	time_now_ = gettickcount_os();

	return true ;
}

void Time_Manager::cleanup()
{
}

void Time_Manager::tick() 
{
	static uint32_t	old_time = 0;	
	tick_count_++;

	time_now_ = gettickcount_os();
	uint32_t sub_time = cal_sub_time(old_time, time_now_);

	delta_time_ = sub_time;

	const uint32_t	MAXTIME_CAL_LOOPTIME	= 20;	
	{
		static uint32_t	loop_count = 0;		
		static uint32_t	loop_hop = 0;		

		loop_count++;
		loop_hop += sub_time;

		if( loop_hop > MAXTIME_CAL_LOOPTIME )		
		{
			loop_time_ = loop_hop / loop_count ;

			loop_count = 0;
			loop_hop = 0;
		}
	}

	const uint32_t	MAXTIME_CAL_FPS			= 1000;	
	{
		static uint32_t	loop_count = 0;		
		static uint32_t	loop_hop = 0;	

		loop_count++;
		loop_hop += sub_time;

		if( loop_hop > MAXTIME_CAL_FPS )		
		{
			fps_ = (loop_count * 1000) / loop_hop;

			loop_count = 0;
			loop_hop = 0;
		}
	}

	old_time = time_now_;
	real_time_ += loop_time_;
}

uint32_t Time_Manager::cal_sub_time(uint32_t start, uint32_t end)
{
	if(start < end) 
		return ((uint32_t)0xFFFFFFFF - start) + end;
	else 
		return end - start;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

