
#include "XlbeXmlAttributes.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////
namespace xlbe {

///////////////////////////////////////////////////////////////////////////////////////////////////////
Xml_Attributes::Xml_Attributes()
{
}

Xml_Attributes::~Xml_Attributes()
{
}

void Xml_Attributes::insert(const std::string& attr_name, const std::string& attr_value)
{
	Base::insert(std::pair<std::string, std::string>(attr_name, attr_value));
}

void Xml_Attributes::erase(const std::string& attr_name)
{
	iterator iter = find(attr_name);

	if (iter != end())
		Base::erase(iter);
}

bool Xml_Attributes::exists(const std::string& attr_name) const
{
	return find(attr_name) != end();
}

const std::string& Xml_Attributes::key(size_t index) const
{
	if (index >= size())
	{
		assert(false);
	}

	const_iterator iter = begin();
	std::advance(iter, index);

	return (*iter).first;
}

const std::string& Xml_Attributes::value(size_t index) const
{
	if (index >= size())
	{
		assert(false);
	}

	const_iterator iter = begin();
	std::advance(iter, index);

	return (*iter).second;
}

const std::string& Xml_Attributes::value(const std::string& attr_name) const
{
        const_iterator iter = find(attr_name);

        if (iter != end())
        {
            return (*iter).second;
        }
        else
        {
			assert(false);
        }
}

const std::string& Xml_Attributes::get_value_as_string(const std::string& attr_name, const std::string& def) const
{
	 return (exists(attr_name)) ? value(attr_name) : def;
}

bool Xml_Attributes::get_value_as_bool(const std::string& attr_name, bool def) const
{
        if (!exists(attr_name))
        {
            return def;
        }

		const std::string& val = value(attr_name);

        if (val == "false" || val == "0")
        {
            return false;
        }
        else if (val == "true" || val == "1")
        {
            return true;
        }
        else
        {
			assert(false);
			return false;
        }
}

int Xml_Attributes::get_value_as_integer(const std::string& attr_name, int def) const
{
	if (!exists(attr_name))
	{
		return def;
	}

	int val;
	std::istringstream strm(value(attr_name).c_str());

	strm >> val;

	if (strm.fail())
	{
		assert(false);
	}

	return val;
}

float Xml_Attributes::get_value_as_float(const std::string& attr_name, float def) const
{
	if (!exists(attr_name))
	{
		return def;
	}

	float val;
	std::istringstream strm(value(attr_name).c_str());

	strm >> val;

	if (strm.fail())
	{
		assert(false);
		return 0.0f;
	}

	return val;
}

World_Size Xml_Attributes::get_value_as_size(const std::string& attr_name) const
{
	if (!exists(attr_name))
	{
		return World_Size(0, 0);
	}

	int width;
	int height;
	const std::string& val = value(attr_name);

	sscanf(val.c_str(), "%d,%d", &width, &height);

	return World_Size(width, height);

}

World_Point Xml_Attributes::get_value_as_point(const std::string& attr_name) const
{
	if (!exists(attr_name))
	{
		return World_Point(0, 0);
	}

	int x;
	int y;
	const std::string& val = value(attr_name);

	sscanf(val.c_str(), "%d,%d", &x, &y);

	return World_Point(x, y);

}

World_Rect Xml_Attributes::get_value_as_rect(const std::string& attr_name) const
{
	if (!exists(attr_name))
	{
		return World_Rect(0, 0, 0, 0);
	}

	int left, top, right, bottom;
	const std::string& val = value(attr_name);

	sscanf(val.c_str(), "%d,%d,%d,%d", &left, &top, &right, &bottom);

	return World_Rect(left, top, right, bottom);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
}
