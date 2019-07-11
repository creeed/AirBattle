#ifndef __COUNT_TIMER_H__
#define __COUNT_TIMER_H__

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Types.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Count_Timer
{
public:
	Count_Timer() 
	{
		opered_ = false;

		timer_term_ = 0;
		timer_old_ = 0;
	}

	~Count_Timer() { }

public:
	void cleanup()
	{
		opered_ = false;

		timer_term_ = 0;
		timer_old_ = 0;
	}

	bool is_set_timer() { return opered_; }

	void begin_timer(uint32_t term, bool first_run = false) 
	{
		opered_ = true;
		first_run_ = first_run;

		timer_term_ = term;
		timer_old_ = 0;
	}

	bool counting_timer(uint32_t dt)
	{
		if (!opered_)
			return false;

		if (first_run_)
		{
			first_run_ = false;
			return true;
		}

		timer_old_ += dt;

		if (timer_old_ < timer_term_)
			return false;

		timer_old_ = 0;

		return true;
	}

	uint32_t get_leave_time(uint32_t now)
	{
		if (!opered_)
			return 0;

		//if(!counting_timer(now))
		//{
			return timer_term_ + timer_old_ - now;
		//}

		return 0;
	}

private:
	bool opered_;
	bool first_run_;

	uint32_t timer_term_;
	uint32_t timer_old_;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif