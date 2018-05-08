#include "inputParser.h"



inputParser::inputParser(int maxInput_)
{
	maxInput = maxInput_;
	inputArr = new char[maxInput_];
}


inputParser::~inputParser()
{
}

void inputParser::readInput() {
	char c;
	for (int i = 0; i < maxInput; i++) {
		c = getchar();
		if (c != '\n') {
			inputArr[i] = c;
		}
		else {
			inputArr[i] = 0;
			break;
		}
	}
}

char* inputParser::getInputArr() {
	return inputArr;
}

void inputParser::listCommands() {

}