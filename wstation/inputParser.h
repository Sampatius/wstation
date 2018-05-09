#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

class inputParser
{
public:
	inputParser();
	~inputParser();

	inline std::string getInput() { return inputString; }
	inline std::vector<std::string> getCommmands() { return commandsVec; }

	// Static function used in iterator to determine presence of extra whitespaces
	static bool bothAreSpaces(char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); }

	void readInput();
	void listCommands();
	void parseInput();

private:
	int maxInput;
	std::string inputString;
	std::vector<std::string> commandsVec;
};