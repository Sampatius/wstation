#include "messagePrinter.h"



messagePrinter::messagePrinter()
{
}


messagePrinter::~messagePrinter()
{
}

/* Initialize the Vectors with given string Vectors of available commands in Main and Sub Menu */
void messagePrinter::initLists(std::vector<std::string> commandsVec, std::vector<std::string> subMenuVec)
{
	for (auto &commands : commandsVec) {
		listOfCommands.push_back(commands);
	}

	for (auto &options : subMenuVec) {
		listOfSubMenuCommands.push_back(options);
	}
}

/* Print line of dashes for aesthetics */
void messagePrinter::printLine()
{
	std::cout << "----------------------------------------" << std::endl;
}

/* Print the program name */
void messagePrinter::printIntro()
{
	std::cout << "#----------------------#" << std::endl;
	std::cout << "# WEATHER STATION 9000 #" << std::endl;
	std::cout << "#----------------------#" << std::endl;
}

/* Print Main Menu help from Vector */
void messagePrinter::printMainMenuHelp()
{
	std::cout << "Available Main Menu commands are listed below:" << std::endl;
	printLine();
	for (auto &commands : listOfCommands) {
		std::cout << commands << std::endl;
	}
	
	std::cout << std::endl;
}

/* Print Sub Menu help from Vector */
void messagePrinter::printSubMenuHelp()
{
	std::cout << "Available Sub Menu commands are listed below:" << std::endl;
	printLine();
	for (auto &subCom : listOfSubMenuCommands) {
		std::cout << subCom << std::endl;
	}
	std::cout << std::endl;
}

/* Function used to print smaller messages in the program */
void messagePrinter::printMsg(std::string message)
{
	std::cout << message << std::endl;
}
