#pragma once
#include <iostream>
#include <vector>

class messagePrinter
{
public:
	messagePrinter();
	~messagePrinter();

	void initLists(std::vector<std::string> commandsVec, std::vector<std::string> optionsVec, std::vector<std::string> parametersVec);
	void printLine();
	void printIntro();
	void printInstructions();
	void printHelp();
	void printFailedInput();
	void printQuit();

	void printMsg(std::string message);

private:
	std::vector<std::string> listOfCommands;
	std::vector<std::string> listOfQueryOptions;
	std::vector<std::string> listOfParameters;
};

