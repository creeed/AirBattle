#ifndef __XLBE_ENCRYPT_RESOURCE_PRIVOIDER_H__
#define __XLBE_ENCRYPT_RESOURCE_PRIVOIDER_H__


////////////////////////////////////////////////////////////////////////////////////////////////
#include "XlbeRawDataContainer.h"
#include "XlbeResourceProvider.h"

////////////////////////////////////////////////////////////////////////////////////////////////
namespace xlbe {

////////////////////////////////////////////////////////////////////////////////////////////////
class Encrypt_Resource_Provider : public Resource_Provider
{
public:
    Encrypt_Resource_Provider() { }
    virtual ~Encrypt_Resource_Provider() { }

public:
    virtual bool load_raw_data_container(const std::string& filename, Raw_Data_Container& output) ;
    virtual void unload_raw_data_container(Raw_Data_Container &data) ;
};

////////////////////////////////////////////////////////////////////////////////////////////////
} 

#endif	