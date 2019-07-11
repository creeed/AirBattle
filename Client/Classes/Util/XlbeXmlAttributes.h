#ifndef __XLBE_XML_ATTRIBUTES_H__
#define __XLBE_XML_ATTRIBUTES_H__

////////////////////////////////////////////////////////////////////////////////////////////
#include <map>
#include <assert.h>
#include <sstream>
#include "WorldRect.h"

////////////////////////////////////////////////////////////////////////////////////////////
namespace xlbe {

////////////////////////////////////////////////////////////////////////////////////////////

class  Xml_Attributes : private std::map<std::string, std::string>
{
public:
    typedef std::map<std::string, std::string> Base;

    using Base::iterator;
    using Base::reverse_iterator;
    using Base::begin;
    using Base::end;
    using Base::rbegin;
    using Base::rend;
    using Base::size;
    using Base::empty;

public:
    Xml_Attributes();
    virtual ~Xml_Attributes();

    void insert(const std::string& attr_name, const std::string& attr_value);
    void erase(const std::string& attr_name);
    bool exists(const std::string& attr_name) const;
    const std::string& key(size_t index) const;
    const std::string& value(size_t index) const;
    const std::string& value(const std::string& attr_name) const;

    const std::string& get_value_as_string(const std::string& attr_name, const std::string& def = "") const;
    bool get_value_as_bool(const std::string& attr_name, bool def = false) const;
    int get_value_as_integer(const std::string& attr_name, int def = 0) const;
    float get_value_as_float(const std::string& attr_name, float def = 0.0f) const;

	World_Size get_value_as_size(const std::string& attr_name) const;
	World_Point get_value_as_point(const std::string& attr_name) const;
	World_Rect get_value_as_rect(const std::string& attr_name) const;
};

////////////////////////////////////////////////////////////////////////////////////////////
}

#endif