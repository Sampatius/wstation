#include "inputParser.h"
#include "messagePrinter.h"
#include "taskHandler.h"
#include "logger.h"

void signalHandler(int signo);

// Objects
inputParser parser;
messagePrinter printer;
taskHandler handler;
logger log;

int main() {	

	// Variables and initialization Vectors
	std::string userInput;
	int interval;
	std::vector<std::string> availableCommands = { "start", "help", "quit" };
	std::vector<std::string> availableSubMenuCommands = { "place", "parameters", "starttime", "endtime" , "timestep"};

	// Loop condition
	bool loop = true;

	signal(SIGINT, signalHandler);

	// Initialize the printer class with commands, options and parameters
	printer.initLists(availableCommands, availableSubMenuCommands);

	log.openFile();

	// Print intro
	printer.printIntro();

	log.writeLog("TEST");
	log.writeLog("TEST2");
	log.writeLog("TEST3");

	log.closeFile();
	/*
	// Main loop
	while (loop) {

		// Read user input
		userInput = parser.readInput();

		// First layer of switch case to handle so called Main Menu
		switch (parser.mapInput(userInput)) {

		// Sub Menu -- User has other actions available
		case start:
			printer.printMsg("START");
			userInput = parser.readInput();

			// Second layer of switch case to handle the functionality in so called Sub Menu
			switch (parser.mapInput(userInput)) {

			// Search case -- User starts a new process to monitor selected location
			case search:
				printer.printMsg("SEARCH");
				userInput = parser.readInput();
				printer.printMsg("ENTER DELAY");
				interval = parser.parseInt(parser.readInput());
				if (interval < 0) {
					printer.printMsg("Invalid or negative value given for interval. Returning to Main menu.");
					break;
				}
				else {
					handler.startTask(userInput, interval);
					break;
				}

			// Check case -- Display report about weather monitoring
			case check:
				printer.printMsg("CHECK");
				for (auto &record : handler.getRecords()) {
					printer.printMsg(record.second);
				}
				break;
			
			// End case -- Terminate a process
			case end:
				printer.printMsg("END");
				userInput = parser.readInput();
				if (handler.endTask(userInput)) {
					printer.printMsg("Process ended.");
				}
				else {
					printer.printMsg("No process found with given location.");
				}
				break;

			// Previous case -- Return back to Main Menu
			case previous:
				printer.printMsg("PREVIOUS");
				break;

			// NOT_DEFINED case -- Invalid input in Sub Menu
			case NOT_DEFINED:
				printer.printMsg("NOT DEFINED SUBMENU");
				break;

			// Default case -- Should never be seen
			default:
				printer.printMsg("SUB MENU DEFAULT");
				break;
			}

		// Help case -- Print out info about commands
		case help:
			printer.printMsg("HELP");
			break;

		// Quit case -- Exit program and close all program related processes
		case quit:
			printer.printMsg("QUIT");
			loop = false;
			handler.quitClean();
			break;
		
		// NOT_DEFINED case -- If input doesn't get matched in mapping function, enter this case
		case NOT_DEFINED:
			printer.printMsg("FAILED INPUT");
			break;

		// Default case -- Should never be seen
		default:
			printer.printMsg("DEFAULT CASE");
			break;
		}
	}
	log.closeFile();
	exit(0);*/
}

void signalHandler(int signo)
{
	if (signo == SIGINT) {
		printer.printMsg("CTRL-C!");
		handler.quitClean();
		exit(0);
	}
}
