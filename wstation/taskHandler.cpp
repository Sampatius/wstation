#include "taskHandler.h"
#include <iostream>



taskHandler::taskHandler()
{
}


taskHandler::~taskHandler()
{
}

/* Function for starting tasks */

void taskHandler::startTask(std::string input, int delay)
{
	url.append(input);

	pid = fork();
	recordTask(pid, input);
	if (pid == 0) {
		while (1) {
			std::cout << "CHILD! PID: " << ::getpid() << std::endl;
			sleep(5);
		}
	}
	else {
		std::cout << "PARENT!" << std::endl;
	}
}

/* Function for ending task based on user given location */

int taskHandler::endTask(std::string locationID)
{
	for (auto &record : pidRecords) {
		if (record.second == locationID) {
			kill(record.first, SIGINT);
			return 1;
		}
	}
	return 0;
}

/* Record process ID and location parameter's value to a Vector as a pair */

void taskHandler::recordTask(pid_t pid, std::string locationID)
{
	pidRecords.push_back(std::make_pair(pid, locationID));
}

void taskHandler::testFunc()
{
	cHandler.initCurl(url);

	cHandler.openAndWrite("test");

	cHandler.cleanUp();
}
