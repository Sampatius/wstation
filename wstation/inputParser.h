#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

enum commands {
	start,
	help,
	quit,
	search,
	check,
	end,
	previous,
	NOT_DEFINED
};

class inputParser
{
public:
	inputParser();
	~inputParser();

	// Getters
	inline std::string getInput() { return inputString; }
	inline std::vector<std::string> getInputs() { return inputsVec; }
	inline std::string getLocation() { return location; }

	// Static function used in iterator to determine presence of extra whitespaces
	static bool bothAreSpaces(char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); }

	std::string readInput();
	void parseInput(std::string input);
	commands mapInput(std::string input);

private:
	int maxInput;
	std::string inputString;
	std::vector<std::string> inputsVec;
	std::string location;
};