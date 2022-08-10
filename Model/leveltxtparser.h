#pragma once

#include <vector>
#include <sstream>

#include "idataparser.h"
#include "filereader.h"
#include "datadesc.h"

#define SPLIT_LINE "OTHER DATA"
#define SPLIT_CHAR ' '
#define DEFAULT_FHOST_NUM 1
#define DEFAULT_GHOST_TYPE 'L'
#define DEFAULT_LIFE_COUT 3

class LevelTxtParser : public IDataParser<filestructs::LevelInfo, std::vector<std::string>>
{
	public:
		LevelTxtParser();
		~LevelTxtParser();

		filestructs::LevelInfo parser(std::vector<std::string>) override;

	private:
		std::vector<std::string> __split_line(std::string line);

		template<typename T>
		inline T __get_val(std::string line);
};

template<typename T>
inline T __get_val(std::string line)
{
	return static_cast<T>(line);
}