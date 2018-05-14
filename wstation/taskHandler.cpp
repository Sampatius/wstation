#include "taskHandler.h"
#include <iostream>
#include <sys/wait.h>



taskHandler::taskHandler()
{
}


taskHandler::~taskHandler()
{
}

void taskHandler::startTask(std::vector<std::string> inputs, int delay)
{
	/*
	for (auto &input : inputs) {
		url.append(input);
		url.append("&");
	}

	while (taskRunning) {
		cHandler.initCurl(url);

		cHandler.openAndWrite(fileName);

		cHandler.cleanUp();
		sleep(10);
	}
	*/
	std::cout << "CHILD! PID: " << ::getpid() << std::endl;
	sleep(5);
}

void taskHandler::endTask(std::string locationID)
{
	for (auto &record : pidRecord) {
		if (record.second == locationID) {
			kill(record.first, SIGKILL);
		}
	}
	std::cout << "ENDED!" << std::endl;
}

void taskHandler::recordTask(pid_t pid, std::string locationID)
{
	pidRecord.push_back(std::make_pair(pid, locationID));
}
