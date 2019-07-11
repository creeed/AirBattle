#include "XlbeEncryptResourceProvider.h"
#include<string.h>

////////////////////////////////////////////////////////////////////////////////////////////////
namespace xlbe {

#define PAKCET_KEY "gfdg9i9gflewirer"

#define ENCRYPT(x,xlen,KEY,BeginPlace)	if( (x)!=NULL ) \
		{ \
		\
			char* t_pBuffer = (x); \
			char* pKey = {KEY}; \
			uint32_t KeyLen = (uint32_t)strlen(pKey); \
			for (uint32_t i = 0; i < (xlen); i++) \
			{ \
				*t_pBuffer ^= pKey[(i+BeginPlace)%KeyLen]; \
				t_pBuffer++; \
			} \
		}


//#ifndef WIN32
//	void _split_whole_name(const char *whole_name, char *fname, char *ext)
//	{
//		char *p_ext;
//
//		p_ext = rindex(whole_name, '.');
//		if (NULL != p_ext)
//		{
//			strcpy(ext, p_ext);
//			snprintf(fname, p_ext - whole_name + 1, "%s", whole_name);
//		}
//		else
//		{
//			ext[0] = '\0';
//			strcpy(fname, whole_name);
//		}
//	}
//
//	void _splitpath(const char *path, char *drive, char *dir, char *fname, char *ext)
//	{
//		char *p_whole_name;
//
//		drive[0] = '\0';
//		if (NULL == path)
//		{
//			dir[0] = '\0';
//			fname[0] = '\0';
//			ext[0] = '\0';
//			return;
//		}
//
//		if ('/' == path[strlen(path)])
//		{
//			strcpy(dir, path);
//			fname[0] = '\0';
//			ext[0] = '\0';
//			return;
//		}
//
//		p_whole_name = rindex(path, '/');
//		if (NULL != p_whole_name)
//		{
//			p_whole_name++;
//			_split_whole_name(p_whole_name, fname, ext);
//
//			snprintf(dir, p_whole_name - path, "%s", path);
//		}
//		else
//		{
//			_split_whole_name(path, fname, ext);
//			dir[0] = '\0';
//		}
//	}
//#endif

////////////////////////////////////////////////////////////////////////////////////////////////
bool Encrypt_Resource_Provider::load_raw_data_container(const std::string& filename, Raw_Data_Container& output) 
{
    if (filename.empty())
	{
		assert(false);
		return false;
	}

    FILE* file = fopen(filename.c_str(), "rb");

    if (file == 0)
	{
		assert(false);
		return false;
	}

    fseek(file, 0, SEEK_END);
    const long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = new  char[size];

    const size_t size_read = fread(buffer, sizeof(char), size, file);
    fclose(file);

    if (size_read != size)
    {
        delete[] buffer;
        
		assert(false);
		return false;
    }

	//todo 

	//char ext[256];  
 //   _splitpath( filename.c_str(), 0, 0, 0, ext ); 
	//if (strcmp(ext, ".sprite") == 0 || strcmp(ext, ".png") == 0)
	//    ENCRYPT(buffer, size_read, PAKCET_KEY, 0);

    output.set_data((uint8_t*)buffer);
    output.set_size(size);

	return true;
}

void Encrypt_Resource_Provider::unload_raw_data_container(Raw_Data_Container &data)  
{ 
    uint8_t* const ptr = data.get_data_ptr();
    delete[] ptr;
    data.set_data(0);
    data.set_size(0);
}

////////////////////////////////////////////////////////////////////////////////////////////////
} 
