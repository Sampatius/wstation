#include "inputParser.h"
#include <iostream>

inputParser::inputParser() 
{
}

inputParser::~inputParser()
{
}

/*	Read user input
	Responsible for reading input from the user using char Vector that is used
	to construct a string
*/

std::string inputParser::readInput() 
{

	// Variables for reading single characters and to hold the input in Vector
	int c;
	std::vector<char> inputBuff;

	// Loop until Enter is pressed
	while (1) {

		// Read a single character
		c = getchar();

		// If it is new line, construct a string from the buffer Vector and push it to input Vector and break from while loop
		if (c == '\n') {
			std::string temp(inputBuff.begin(), inputBuff.end());
			std::string::iterator new_end = std::unique(temp.begin(), temp.end(), bothAreSpaces);
			temp.erase(new_end, temp.end());
			return temp;
		}

		// Else if the input is backspace, pop back the buffer Vector
		else if (c == 127) {
			inputBuff.pop_back();
		}

		// Else, push back to buffer Vector
		else {
			inputBuff.push_back((char)tolower(c));
		}
	}
}

/*	Parse users input
	Removes excess whitespaces from the user input and splits the string to a vector
*/

void inputParser::parseInput(std::string input) 
{

	// Iterate over the string and remove excess whitespaces
	std::string::iterator new_end = std::unique(input.begin(), input.end(), bothAreSpaces);
	input.erase(new_end, input.end());

	std::string token;
	std::stringstream ss(input);

	// Loop over the string and split it according to single whitespaces to a Vector
	while (std::getline(ss, token, ' ')) {
		size_t pos = 0;
		std::string temp;

		// Look for = symbol in each string push them to Vector
		if ((pos = token.find('=')) != std::string::npos) {
			temp = token.substr(0, pos);
			if (temp.length() > 0) {
				temp = token.substr((pos + 1), std::string::npos);
				if (temp.length() > 0) {
					inputsVec.push_back(token);
				}
			}
		}
	}
}

int inputParser::parseInt(std::string input)
{
	try {
		return std::stoi(input);
	}
	catch (std::invalid_argument&) {
		return -1;
	}
}

/* Map input to a enum that is used in the Menu navigation */

commands inputParser::mapInput(std::string input) 
{
	if (input == "start") return start;
	if (input == "help") return help;
	if (input == "quit") return quit;
	if (input == "new") return search;
	if (input == "check") return check;
	if (input == "end") return end;
	if (input == "back") return previous;
	else {
		return NOT_DEFINED;
	}
}