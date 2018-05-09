#include "inputParser.h"
#include <iostream>

inputParser::inputParser() {
}

inputParser::~inputParser()
{
}

/*	Read user input
	Responsible for reading input from the user using char Vector that is used
	to construct a string
*/

void inputParser::readInput() {

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
			inputString = temp;
			break;
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

void inputParser::listCommands() {

}

/*	Parse users input
	Removes excess whitespaces from the user input and splits the string to a vector
*/

void inputParser::parseInput() {

	// Iterate over the string and remove excess whitespaces
	std::string::iterator new_end = std::unique(inputString.begin(), inputString.end(), bothAreSpaces);
	inputString.erase(new_end, inputString.end());

	std::string token;
	std::stringstream ss(inputString);

	// Loop over the string and split it according to single whitespaces to a Vector
	while (std::getline(ss, token, ' ')) {
		commandsVec.push_back(token);
	}
}