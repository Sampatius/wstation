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
	inline std::vector<std::string> getInputs() { return inputsVec; }
	inline std::vector<std::string> getParams() { return paramsVec; }

	// Static function used in iterator to determine presence of extra whitespaces
	static bool bothAreSpaces(char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); }

	std::string readInput();
	void listHelp();
	void parseInput(std::string input);

private:
	int maxInput;
	std::string inputString;
	std::vector<std::string> inputsVec;
	std::vector<std::string> paramsVec;
};