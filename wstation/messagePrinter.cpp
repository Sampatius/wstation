#include "messagePrinter.h"



messagePrinter::messagePrinter()
{
}


messagePrinter::~messagePrinter()
{
}

void messagePrinter::initLists(std::vector<std::string> commandsVec, std::vector<std::string> subMenuVec)
{
	for (auto &commands : commandsVec) {
		listOfCommands.push_back(commands);
	}

	for (auto &options : subMenuVec) {
		listOfSubMenuCommands.push_back(options);
	}
}

void messagePrinter::printLine()
{
	std::cout << "----------------------------------------" << std::endl;
}

void messagePrinter::printIntro()
{
	std::cout << "#----------------------#" << std::endl;
	std::cout << "# WEATHER STATION 9000 #" << std::endl;
	std::cout << "#----------------------#" << std::endl;
}

void messagePrinter::printInstructions()
{
	std::cout << "Please enter the location to monitor." << std::endl;

}

void messagePrinter::printMainMenuHelp()
{
	std::cout << "Available Main Menu commands are listed below:" << std::endl;
	printLine();
	for (auto &commands : listOfCommands) {
		std::cout << commands << std::endl;
	}
	
	std::cout << std::endl;
}

void messagePrinter::printSubMenuHelp()
{
	std::cout << "Available Sub Menu commands are listed below:" << std::endl;
	printLine();
	for (auto &subCom : listOfSubMenuCommands) {
		std::cout << subCom << std::endl;
	}
	std::cout << std::endl;
}

void messagePrinter::printFailedInput()
{
	std::cout << "Input not recognized. Try 'help' to list available commands." << std::endl;
}

void messagePrinter::printQuit()
{
	std::cout << "Exiting program." << std::endl;
}

void messagePrinter::printMsg(std::string message)
{
	std::cout << message << std::endl;
}
