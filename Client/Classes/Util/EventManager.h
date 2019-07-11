#ifndef __EVENT_MANAGER_H__
#define __EVENT_MANAGER_H__

//////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"

//////////////////////////////////////////////////////////////////////////////////////////////////
struct Game_Event;

enum Game_Event_ID
{
	GE_APPLICATION_INITED = 0,			//游戏程序初始化
	GE_NET_CLOSE,
	GE_VARIABLE_CHANGED,
	GE_SHOW_SYSTEM_INFO,
	GE_CONNECT_FAILED,


	GE_UNIT_DATA_ID,
	GE_UNIT_NAME,
	GE_UNIT_LEVEL,
	GE_UNIT_EXP,
	GE_UNIT_GOLD,
	GE_UNIT_BIND_GOLD,
	GE_UNIT_MONEY,
	GE_UNIT_SCORE,
	GE_UNIT_WIN_COUNT,
	GE_UNIT_LOST_COUNT,
	GE_UNIT_MEMBER_LEVEL,
	GE_UNIT_MEMBER_LEVEL_REWARD,
	GE_UNIT_YAOQIANSHU_COUNT,
	GE_UNIT_EXPCOPY_COUNT,
	GE_UNIT_EQUIPCOPY_COUNT,
	GE_UNIT_SEVEN_SIGN,
	GE_UNIT_GOLD_MULTIPLE,
	GE_UNIT_MONTH_CARD,
	GE_UNIT_DAY_SIGN,
	GE_UNIT_DAY_SIGN_COUNT,
	GE_UNIT_DAY_SIGN_TOTAL,
	GE_UNIT_FIRST_RECHARGE,
	GE_UNIT_RECHARGE,

	GE_LOGIN_FAILED,
	GE_JOIN_SCENE_FAILED,
	GE_PLAYER_UPDATE_EQUIP,
	GE_LOADING_RESOURCE_PROGRESS,
	GE_BAG_ITEM_CHANGED,
	GE_PLAYER_ON_EQUIP,
	GE_PLAYER_UN_EQUIP,
	GE_RELATION_CHANGED,
	GE_RELATION_DELETE,
	GE_LOAD_RANK,
	GE_ON_ATTACK,
	GE_MAIL_CHANGED,
	GE_MYSELF_DIE,
	GE_PLAYEROTHER_DIE,
	GE_PLAYEROTHER_NEW,
	GE_PLAYEROTHER_DELETE,
	GE_MONSTER_OUT_AREA,
	GE_GO_NEXT_STAGE,
	GE_RESTART_GAME,
	GE_PREV_RESTART_GAME,
	GE_ON_USE_JINNANG,
	GE_PVP_GAME_READY,
	GE_PVP_GAME_END,
	GE_PVP_PARAM_SET,
	GE_PVP_PLAYEROTHER_READY,
	GE_PVP_GAME_READY_EFFECT,
	GE_MATCH_GAME_FAILED,
	GE_MATCH_OTHER_PLAYER,
	GE_MATCH_CANCEL,
	GE_SCENE_RESOURCE_LOADED,
	GE_SELL_ITEM_SUCCESS,
	GE_ACCOUNT_DETAIL_ERROR,
	GE_GAME_END,
	GE_ENHANCE_ITEM,
	GE_STARTONLINEREWARD,
	GE_GOTONLINEREWARD,
	GE_CANGOTONLINEREWARD,
	GE_CANSEVENSIGN,
	GE_SEVENSIGN,
	GE_DAYSIGN,
	GE_CANDAYSIGN,
	GE_UNIT_DAY_SIGN_COUNT_BU,
	GE_GOTFIRSTRECHARGE,
	GE_BUY_GOODS_SUCCESS,
	GE_BUY_GOLDS_SUCCESS,
	GE_BUY_GOODS_ERROR,
	GE_BUY_GOLDS_ERROR,
	GE_CANMONTHCARD,
	GE_GOTMONTHCARD_SUCCESS,
	GE_GOTMONTHCARD_ERROR,
	GE_GOTOFFLINEREWARD,
	GE_OPENMAIL,
	GE_MAILDETAIL,
	GE_CHAT_MESSAGE,
	GE_SYSTEM_MESSAGE,
	GE_SCENE_CHAT_MESSAGE,
	GE_FINISH_CUR_GUIDE,
	GE_BUYVIPLIBAO_SUCCESS,
	GE_BUYVIPLIBAO_LACK_MONEY,
	GE_GOODS_FIRST_RECHARGE_CHANGED,
	GE_BUY_ITEM_COUNT_CHANGED,

	GE_UNIT_MONTH_DAY_SIGN, //每日签到
	GE_UNIT_DAY_BU_SIGN, //补签
	GE_UNIT_DAY_LEI_SIGN, //累签

	GE_USE_ITEM,
	GAME_EVENT_NUMBER
};


typedef std::function< void(const Game_Event*, uint32_t) > Func_Event_Handle;
typedef std::list< std::pair< Func_Event_Handle, uint32_t > > Func_Notifys;
#define GAME_EVENT_CALLBACK(__selector__,__target__, ...) std::bind(&__selector__,__target__, std::placeholders::_1, std::placeholders::_2, ##__VA_ARGS__)

struct Game_Event_Define
{
	Game_Event_ID game_event_id_;
	bool delay_process_;
	Func_Notifys func_notifys_;
};

struct Game_Event
{
	Game_Event_Define* event_define_;
	std::vector< std::string > arg_;
};


//////////////////////////////////////////////////////////////////////////////////////////////////
class Event_Manager : public Singleton<Event_Manager>
{
public:
    Event_Manager();
    ~Event_Manager();

    static Event_Manager *singleton();

public:
	bool initialise();
	void cleanup();

	void tick();

	void register_event_handle(Game_Event_ID event_id, Func_Event_Handle fun_handle, uint32_t owner_data = 0);
	void unregister_event_handle(Game_Event_ID event_id);
	void unregister_event_handle(Game_Event_ID event_id, uint32_t owner_data);
	void unregister_all_event_handle();

public:
	void push_event(Game_Event_ID id, const std::vector< std::string >& vparam);

	void push_event(Game_Event_ID id);
	void push_event(Game_Event_ID id, int arg0);
	void push_event(Game_Event_ID id, int arg0, int64_t arg1);
	void push_event(Game_Event_ID id, int arg0, const char *arg1);
	void push_event(Game_Event_ID id, float arg0);
	void push_event(Game_Event_ID id, const char *arg0);
	void push_event(Game_Event_ID id, const char *arg0, int arg1);
	void push_event(Game_Event_ID id, const char *arg0, int arg1, int arg2);
	void push_event(Game_Event_ID id, const char *arg0, int arg1, int arg2, int arg3);
	void push_event(Game_Event_ID id, const char *arg0, float arg1);
	void push_event(Game_Event_ID id, const char *arg0, float arg1, float arg2);
	void push_event(Game_Event_ID id, const char *arg0, const char *arg1);
	void push_event(Game_Event_ID id, const char *arg0, const char *arg1, int arg2 );
	void push_event(Game_Event_ID id, int arg0, int arg1);
	void push_event(Game_Event_ID id, int arg0, int arg1, int arg2);
	void push_event(Game_Event_ID id, int arg0, int arg1, int arg2, int arg3);
	void push_event(Game_Event_ID id, int arg0, int arg1, int arg2, int arg3, int arg4);
	void push_event(Game_Event_ID id, const char *arg0, const char *arg1, int arg2, int arg3);

	void process_all_event();
	void clean_all_event();

protected:
	void push_event(const Game_Event& event);
	void process_event(const Game_Event& event);

private:
	Game_Event_Define * game_event_defines_;  //Game_Event_Define 数组

	uint32_t last_tick_count_;
	std::list< Game_Event > queue_event_;
	std::list< Game_Event > delay_queue_event_;
	std::map< Game_Event_ID, Game_Event_Define* > event_index_as_id_;
};

//////////////////////////////////////////////////////////////////////////////////////////////////

#endif
