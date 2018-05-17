#include "inputParser.h"
#include "messagePrinter.h"
#include "taskHandler.h"
#include "logger.h"

int main() {

	// Objects
	inputParser parser;
	messagePrinter printer;
	taskHandler handler;
	logger log;

	// Variables and initialization Vectors
	std::string userInput;
	int interval;
	std::vector<std::string> availableCommands = { "start", "help", "quit" };
	std::vector<std::string> availableSubMenuCommands = { "new - start a new monitoring process", "check - display currently running processes", "end - end a process", "previous - return to main menu"};

	// Loop condition
	bool loop = true;

	// Initialize the printer class with commands, options and parameters
	printer.initLists(availableCommands, availableSubMenuCommands);

	log.openFile();

	// Print intro
	printer.printIntro();

	// Print Main Menu help
	printer.printMainMenuHelp();

	handler.initSignalHandling();

	// Main loop
	while (loop) {

		// Read user input
		userInput = parser.readInput();

		// First layer of switch case to handle so called Main Menu
		switch (parser.mapInput(userInput)) {

		// Sub Menu -- User has other actions available
		case start:

			// Print Sub Menu help and get user input
			printer.printSubMenuHelp();
			userInput = parser.readInput();

			// Second layer of switch case to handle the functionality in so called Sub Menu
			switch (parser.mapInput(userInput)) {

			// Search case -- User starts a new process to monitor selected location
			case search:
				printer.printMsg("Please enter a location to monitor.");
				userInput = parser.readInput();
				printer.printMsg("Please enter delay in minutes.");
				interval = parser.parseInt(parser.readInput());
				if (interval < 0) {
					printer.printMsg("Invalid or negative value given for interval. Returning to Main menu.");
					log.writeLog(ERROR_LOG, "INVALID DELAY GIVEN TO NEW PROCESS.");
				}
				else {
					handler.startTask(userInput, interval);
					log.writeLog(REPORT_LOG, "PROCESS STARTED FOR LOCATION: " + userInput + " WITH DELAY OF: " + std::to_string(interval) + " MINUTE(S).");
				}
				break;

			// Check case -- Display running processes
			case check:
				printer.printMsg("Below you can see all currently running processes.");
				printer.printLine();
				for (auto &record : handler.getRecords()) {
					printer.printMsg(record.second);
				}
				break;
			
			// End case -- Terminate a process
			case end:
				printer.printMsg("Please enter the name of the process you wish to end.");
				printer.printLine();
				userInput = parser.readInput();
				if (handler.endTask(userInput)) {
					printer.printMsg("Process ended.");
					log.writeLog(REPORT_LOG, "PROCESS ENDED FOR LOCATION: " + userInput);
				}
				else {
					printer.printMsg("No process found with given location.");
					log.writeLog(ERROR_LOG, "INVALID LOCATION ID GIVEN. CAN'T TERMINATE PROCESS.");
				}
				break;

			// Previous case -- Return back to Main Menu
			case previous:
				break;

			// NOT_DEFINED case -- Invalid input in Sub Menu
			case NOT_DEFINED:
				printer.printMsg("Input failed. Logging action.");
				log.writeLog(ERROR_LOG, "INPUT FAILED IN MAIN MENU");
				break;

			// Default case -- Should never be seen
			default:
				printer.printMsg("Sub Menu default case. This should not be seen.");
				log.writeLog(ERROR_LOG, "DEFAULT CASE REACHED IN SUB MENU");
				break;
			}
		break;

		// Help case -- Print out info about commands
		case help:
			printer.printMainMenuHelp();
			printer.printSubMenuHelp();
			break;

		// Quit case -- Exit program and close all program related processes
		case quit:
			loop = false;
			handler.quitClean();
			break;
		
		// NOT_DEFINED case -- If input doesn't get matched in mapping function, enter this case
		case NOT_DEFINED:
			printer.printMsg("Input failed. Logging action.");
			log.writeLog(ERROR_LOG, "INPUT FAILED IN MAIN MENU");
			break;

		// Default case -- Should never be seen
		default:
			printer.printMsg("Default case. This should not be seen.");
			log.writeLog(ERROR_LOG, "DEFAULT CASE REACHED IN MAIN MENU");
			break;
		}
	}
	log.closeFile();
	exit(0);
}