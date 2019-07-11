#include "EventManager.h"
#include "VariableManager.h"

//////////////////////////////////////////////////////////////////////////////////////////////////
template<> Variable_Manager* Singleton<Variable_Manager>::singleton_ = 0;
Variable_Manager* Variable_Manager::singleton()
{
    return singleton_;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
Variable_Manager::Variable_Manager()
{
}

Variable_Manager::~Variable_Manager()
{
}

bool Variable_Manager::initialise()
{
	return true ;
}

void Variable_Manager::cleanup()
{

}

bool Variable_Manager::get_variable(const char *name, std::string& value)
{
	Variables::iterator ifind = current_variables_.find(name);
	if(ifind == current_variables_.end()) return false;

	value = ifind->second;

	return true;
}

void Variable_Manager::set_variable(const char *name, const char *value, bool fire_event)
{
	std::string old_var = current_variables_[name];
	std::string new_variable = value;

	current_variables_[name] = new_variable;

	if(old_var != value && fire_event)
	{
		std::vector< std::string > vparam;
		vparam.push_back(name);
		vparam.push_back(value);
		Event_Manager::singleton()->push_event(GE_VARIABLE_CHANGED, vparam);
	}
}


void Variable_Manager::set_int(const char *name, int value) 
{
	char temp[32];
	snprintf(temp, 32, "%d", value);
	set_variable(name, temp);
}

void Variable_Manager::set_float(const char *name, float value) 
{
	char temp[32];
	snprintf(temp, 32, "%f", value);
	set_variable(name, temp);
}

void Variable_Manager::set_point(const char *name, float x, float y)	
{
	char temp[32];
	snprintf(temp, 32, "%f,%f", x, y);
	set_variable(name, temp);
}

void Variable_Manager::set_string(const char *name, const std::string &value)	
{
	set_variable(name, value.c_str());
}

int	 Variable_Manager::get_int(const char *name, bool* have)		
{
	Variables::iterator ifind = current_variables_.find(name);
	if(ifind == current_variables_.end())
	{
		if(have) *have = false;
		return 0;
	}

	if(have) *have = true;
	return atoi(ifind->second.c_str());
}

float Variable_Manager::get_float(const char *name, bool* have)		
{
	Variables::iterator ifind = current_variables_.find(name);
	if(ifind == current_variables_.end())
	{
		if(have) *have = false;
		return 0.0f;
	}

	if(have) *have = true;
	return atof(ifind->second.c_str());
}

const World_Point &Variable_Manager::get_point(const char *name, bool* have)	
{
	static World_Point pnull(0.0f, 0.0f);

	Variables::iterator ifind = current_variables_.find(name);
	if(ifind == current_variables_.end())
	{
		if(have) *have = false;
		pnull.set_point(0.0f, 0.0f);
		return pnull;
	}

	if(have) *have = true;

	char temp[64];
	strncpy(temp, ifind->second.c_str(), 64);

	char* dot = strchr(temp, ',');
	if(!dot) return pnull;
	*dot = '\0';

	pnull.set_point(atof(temp), atof(dot + 1));
    
	return pnull;
}

const std::string& Variable_Manager::get_string(const char *name, bool* have)
{
	Variables::iterator ifind = current_variables_.find(name);
	if(ifind == current_variables_.end())
	{
		static std::string blank = "";
		if(have) *have = false;
		return blank;
	}

	if(have) *have = true;
	return ifind->second;
}


//////////////////////////////////////////////////////////////////////////////////////////////////

