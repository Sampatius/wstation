#include "taskHandler.h"
#include <iostream>



taskHandler::taskHandler()
{
}


taskHandler::~taskHandler()
{
}

void taskHandler::startTask(std::vector<std::string> inputs, int delay, std::string locationID)
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
	pid = fork();
	if (pid == 0) {
		recordTask(::getpid(), locationID);
		while (1) {
			std::cout << "CHILD! PID: " << ::getpid() << std::endl;
			sleep(5);
		}
	}
	else {
		std::cout << "PARENT!" << std::endl;
	}
}

void taskHandler::endTask(std::string locationID)
{
	for (auto &record : pidRecords) {
		if (record.second == locationID) {
			kill(record.first, SIGKILL);
			std::cout << "KILLED!" << std::endl;
		}
	}
}

void taskHandler::recordTask(pid_t pid, std::string locationID)
{
	pidRecords.push_back(std::make_pair(pid, locationID));
}
