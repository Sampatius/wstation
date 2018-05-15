#include "inputParser.h"
#include "messagePrinter.h"
#include "taskHandler.h"

int main() {

	// Objects
	inputParser parser;
	messagePrinter printer;
	taskHandler handler;

	// Variables and initialization Vectors
	std::string userInput;
	std::vector<std::string> availableCommands = { "start", "help", "quit" };
	std::vector<std::string> availableOptions = { "place", "parameters", "starttime", "endtime" , "timestep"};
	std::vector<std::string> availableParameters = { "tday", "tmin", "tmax" };

	// Loop condition
	bool loop = true;

	// Initialize the printer class with commands, options and parameters
	printer.initLists(availableCommands, availableOptions, availableParameters);

	// Print intro
	printer.printIntro();

	// Main loop
	while (loop) {

		// Read user input
		userInput = parser.readInput();

		// First layer of switch case to handle so called Main Menu
		switch (parser.mapInput(userInput)) {

		// Sub Menu -- User has other actions available
		case start:
			printer.printDebug("START");
			userInput = parser.readInput();

			// Second layer of switch case to handle the functionality in so called Sub Menu
			switch (parser.mapInput(userInput)) {

			// Search case -- User starts a new process to monitor selected location
			case search:
				printer.printDebug("SEARCH");
				userInput = parser.readInput();
				parser.parseInput(userInput);
				printer.printDebug("ENTER DELAY");
				userInput = parser.readInput();
				handler.startTask(parser.getInputs(), std::stoi(userInput), parser.getLocation());
				break;

			// Check case -- Display report about weather monitoring
			case check:
				printer.printDebug("CHECK");
				break;
			
			// End case -- Terminate a process
			case end:
				printer.printDebug("END");
				userInput = parser.readInput();
				handler.endTask(userInput);
				break;

			// Previous case -- Return back to Main Menu
			case previous:
				printer.printDebug("PREVIOUS");
				break;

			// NOT_DEFINED case -- Invalid input in Sub Menu
			case NOT_DEFINED:
				printer.printDebug("NOT DEFINED SUBMENU");
				break;

			// Default case -- Should never be seen
			default:
				printer.printDebug("START MENU DEFAULT");
			}
			break;

		// Help case -- Print out info about commands
		case help:
			printer.printDebug("HELP");
			break;

		// Quit case -- Exit program and close all program related processes
		case quit:
			printer.printDebug("QUIT");
			loop = false;
			break;
		
		// NOT_DEFINED case -- If input doesn't get matched in mapping function, enter this case
		case NOT_DEFINED:
			printer.printDebug("FAILED INPUT");
			break;

		// Default case -- Should never be seen
		default:
			printer.printDebug("DEFAULT CASE");
			break;
		}

	}
}