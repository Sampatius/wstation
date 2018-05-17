#pragma once
#include <iostream>
#include <vector>

class messagePrinter
{
public:
	messagePrinter();
	~messagePrinter();

	void initLists(std::vector<std::string> commandsVec, std::vector<std::string> subMenuVec);
	void printLine();
	void printIntro();
	void printInstructions();
	void printMainMenuHelp();
	void printSubMenuHelp();
	void printFailedInput();
	void printQuit();

	void printMsg(std::string message);

private:
	std::vector<std::string> listOfCommands;
	std::vector<std::string> listOfSubMenuCommands;
};

