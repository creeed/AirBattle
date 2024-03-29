#ifndef __XLBE_RAW_DATA_CONTAINER_H__
#define __XLBE_RAW_DATA_CONTAINER_H__

////////////////////////////////////////////////////////////////////////////////////////////////
#include "Types.h"

////////////////////////////////////////////////////////////////////////////////////////////////
namespace xlbe {

////////////////////////////////////////////////////////////////////////////////////////////////
class  Raw_Data_Container
{
public:
	Raw_Data_Container()
		: data_(0),
		size_(0)
	{
	}

	~Raw_Data_Container() 
	{ 
		release();
	}

	void set_data(uint8_t* data) { data_ = data; }
	uint8_t* get_data_ptr() { return data_; }
	const uint8_t* get_data_ptr() const { return data_; }

	void set_size(size_t size) { size_ = size; }
	int get_size() const { return size_; }

	void release();

private:
	uint8_t* data_;
	size_t size_;
};

////////////////////////////////////////////////////////////////////////////////////////////////
} 

#endif	