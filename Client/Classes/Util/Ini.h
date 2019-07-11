#ifndef __INI_H__
#define __INI_H__

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Ini
{
public:
	typedef std::vector<std::string> Lines;

public:
	Ini(const std::string &file);
    ~Ini();

public:
	std::string read_string(const std::string &section, const std::string &key, const std::string &value, bool comments = false);
	int read_int(const std::string &section, const std::string &key, int value);
	bool read_bool(const std::string &section, const std::string &key, bool value);
	float read_float(const std::string &section, const std::string &key, float value);

	bool write_string(const std::string &section, const std::string &key, const std::string &value);
	bool write_int(const std::string &section, const std::string &key, int value);
	bool write_bool(const std::string &section, const std::string &key, bool value);
	bool write_float(const std::string &section, const std::string &key, float value);

	void delete_section(const std::string &section);
	void delete_key(const std::string &section, const std::string &key);

private:
	bool parse_file(const std::string &file);
	void save_file(const std::string &file);

	const char* get_line_from_memory(char* string_buffer, int buffer_size, const char* memory, const char* memory_end);

private:
	std::string file_;
	Lines lines_; 

};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif