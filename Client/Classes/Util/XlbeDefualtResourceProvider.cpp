
#include "XlbeDefualtResourceProvider.h"
#include "cocos2d.h"

////////////////////////////////////////////////////////////////////////////////////////////////
namespace xlbe {

////////////////////////////////////////////////////////////////////////////////////////////////
bool Default_Resource_Provider::load_raw_data_container(const std::string& filename, Raw_Data_Container& output) 
{
	if (filename.empty())
	{
		assert(false);
		return false;
	}

	//   FILE* file = fopen(filename.c_str(), "rb");

	//if (file == 0)
	//{
	//	assert(false);
	//	return false;
	//}

	//   fseek(file, 0, SEEK_END);
	//   const long size = ftell(file);
	//   fseek(file, 0, SEEK_SET);

	ssize_t len = 0;
	unsigned char* const buffer = cocos2d::FileUtils::getInstance()->getFileData(filename, "r", &len);

	//const size_t size_read = fread(buffer, sizeof(char), size, file);
	//fclose(file);

	//  if (size_read != size)
	//  {
	//      delete[] buffer;
	//      
	//assert(false);
	//return false;
	//  }

	output.set_data(buffer);
	output.set_size(len);

	return true;
}

void Default_Resource_Provider::unload_raw_data_container(Raw_Data_Container &data)  
{ 
    uint8_t* const ptr = data.get_data_ptr();
    delete[] ptr;
    data.set_data(0);
    data.set_size(0);
}



////////////////////////////////////////////////////////////////////////////////////////////////
} 
