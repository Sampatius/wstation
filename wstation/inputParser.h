#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

class inputParser
{

public:
	inputParser(int maxInput_);
	~inputParser();

	void readInput();
	char* getInputArr();
	void listCommands();

private:
	int maxInput;
	char *inputArr;
};