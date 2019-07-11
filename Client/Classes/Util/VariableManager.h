
#ifndef __VARIABLE_MANAGER_H__
#define __VARIABLE_MANAGER_H__

//////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prereqs.h"
#include "WorldRect.h"

//////////////////////////////////////////////////////////////////////////////////////////////////
class Variable_Manager : public Singleton<Variable_Manager>
{
private:
	typedef std::unordered_map< std::string, std::string > Variables;

public:
    Variable_Manager();
    ~Variable_Manager();

    static Variable_Manager *singleton();

public:
	bool initialise();
	void cleanup();

public:
	bool get_variable(const char *name, std::string& value)	;	
	void set_variable(const char *name, const char *value, bool fire_event = true);

	void set_int(const char *name, int value) ;
	void set_float(const char *name, float value) ;

	void set_point(const char *name, float x, float y)	;
	void set_string(const char *name, const std::string &value)	;
	
	int	 get_int(const char *name, bool* have = NULL)		;
	float get_float(const char *name, bool* have = NULL)		;
	const World_Point &get_point(const char *name, bool* have = NULL)	;
	const std::string& get_string(const char *name, bool* have = NULL)	;

private:
	Variables current_variables_;
	Variables need_save_variables_;
};

//////////////////////////////////////////////////////////////////////////////////////////////////

#endif
