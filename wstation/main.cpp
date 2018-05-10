#include "inputParser.h"
#include "messagePrinter.h"
#include "taskHandler.h"

int main() {

	inputParser parser;
	messagePrinter printer;
	taskHandler handler;

	std::string userInput;
	std::vector<std::string> availableCommands = { "start", "help", "quit" };
	std::vector<std::string> availableOptions = { "place", "parameters", "starttime", "endtime" , "timestep"};
	std::vector<std::string> availableParameters = { "tday", "tmin", "tmax" };

	bool loop = true;

	printer.initLists(availableCommands, availableOptions, availableParameters);

	printer.printIntro();

	std::vector<std::string> test;

	while (loop) {

		userInput = parser.readInput();

		switch (parser.mapInput(userInput)) {
		case start:
			printer.printInstructions();
			userInput = parser.readInput();
			parser.parseInput(userInput);
			handler.startTask(parser.getInputs(), "helsinki");
			break;
		case help:
			printer.printHelp();
			break;
		case quit:
			printer.printQuit();
			loop = false;
			break;
		case NOT_DEFINED:
			printer.printFailedInput();
			break;
		default:
			std::cout << "THIS SHOULD NEVER BE SEEN!" << std::endl;
			break;
		}

	}
}