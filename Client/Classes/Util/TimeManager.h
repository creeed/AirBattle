#ifndef __TIME_MANAGER_H__
#define __TIME_MANAGER_H__

//////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "Singleton.h"

//////////////////////////////////////////////////////////////////////////////////////////////////
class Time_Manager : public Singleton<Time_Manager>
{
public:
    Time_Manager();
    ~Time_Manager();

    static Time_Manager *singleton();

public:
	bool initialise();
	void cleanup();

	void tick();

public:
	uint32_t get_loop_time() const { return loop_time_; }
	uint32_t get_delta_time() const { return delta_time_; }
	uint32_t get_real_time() const { return real_time_; }

	uint32_t get_fps() const { return fps_; }
	
	uint32_t get_time_now() const { return time_now_; }
	uint32_t get_tick_count() { return tick_count_; }

    uint32_t cal_sub_time(uint32_t start, uint32_t end);

private:
	uint32_t time_now_;		//��ǰʱ��
	uint32_t loop_time_;		//���20ms����ÿ��ƽ�����ѵ�ʱ��
	uint32_t delta_time_;		//��һ�������ѵ�ʱ��
	uint32_t real_time_;		//����loop_time_�ۻ���ϵͳ����ʱ��
	uint32_t fps_;				//��ǰ������
	uint32_t tick_count_;	//������
};

//////////////////////////////////////////////////////////////////////////////////////////////////

#endif
