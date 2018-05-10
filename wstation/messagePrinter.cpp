#include "messagePrinter.h"



messagePrinter::messagePrinter()
{
}


messagePrinter::~messagePrinter()
{
}

void messagePrinter::initLists(std::vector<std::string> commandsVec, std::vector<std::string> optionsVec, std::vector<std::string> parametersVec)
{
	for (auto &commands : commandsVec) {
		listOfCommands.push_back(commands);
	}

	for (auto &options : optionsVec) {
		listOfQueryOptions.push_back(options);
	}

	for (auto &parameters : parametersVec) {
		listOfParameters.push_back(parameters);
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
	std::cout << "Please enter the location and possible parameters for search." << std::endl;

}

void messagePrinter::printHelp()
{
	std::cout << "Available commands are listed below:" << std::endl;
	printLine();
	for (auto &commands : listOfCommands) {
		std::cout << commands << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "When performing a search for weather reports the search query must contain atleast location\n"\
		"in format 'location=target'. Query can be fitted with additional search options, described below.\n"\
		"Additional parameters can be introduced by adding 'parameters=' to the input." << std::endl;
	std::cout << std::endl;

	std::cout << "Available options:" << std::endl;
	printLine();
	for (auto &options : listOfQueryOptions) {
		std::cout << options << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Available parameters:" << std::endl;
	printLine();
	for (auto &parameters : listOfParameters) {
		std::cout << parameters << std::endl;
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
