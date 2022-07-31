#pragma once

#include <fstream>
#include <filesystem>

#include "datadesc.h"
#include "modelexception.h"

#define NULL_FILE_NAME ""


class FileReader
{
	private:
		std::ifstream* __stream;

	public:
		FileReader(const std::string& file_name);
		FileReader();
		~FileReader();

	private:
		inline bool __check_file_name(const std::string& file_name);
		inline bool __is_exist(const std::string& file_name);
};