#include "filereader.h"

FileReader::FileReader(const std::string& file_name)
{
	if (file_name == NULL_FILE_NAME)
		this->__stream = new std::ifstream();
	else
	{
		if (!(this->__check_file_name(file_name)))
			throw WrongFileNameException(file_name);
		if (!(this->__is_exist(file_name)))
			throw NoSuchFileException(file_name);
		
		this->__stream = new std::ifstream(file_name);
		if (this->__stream->fail())
			throw FileOpenException(file_name);
	}
}

FileReader::FileReader() : FileReader(NULL_FILE_NAME)
{
}

FileReader::~FileReader()
{
	delete this->__stream;
}

inline bool FileReader::__check_file_name(const std::string& file_name)
{
	return ((file_name.starts_with(LEVEL_FILE_NAME) || file_name.starts_with(SAVE_FILE_NAME)) && file_name.ends_with(FILE_EXT));
}

inline bool FileReader::__is_exist(const std::string& file_name)
{
	return std::filesystem::exists(file_name);
}
