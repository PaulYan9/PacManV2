#include "leveltxtparser.h"

std::vector<std::string> LevelTxtParser::__split_line(std::string line)
{
	std::vector<std::string> tokens;
	std::stringstream ss(line);
	std::string token;
	while (std::getline(ss, token, SPLIT_CHAR))
		tokens.push_back(token);

	return tokens;
}
