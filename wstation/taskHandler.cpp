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
	setenv("FI", "/usr/share/zoneinfo/Europe/Helsinki", 1);
	char startTime[30], endTime[30];

	pid = fork();

	recordTask(pid, input);

	if (pid == 0) {
		while (1) {
			std::cout << "CHILD!" << std::endl;
			std::time_t start = std::time(nullptr);
			std::time_t end = std::time(nullptr);
			std::tm* startLocal = std::localtime(&start);
			std::tm* endLocal = std::localtime(&end);
			std::strftime(startTime, sizeof startTime, "%Y-%m-%dT%H:%M:00Z", startLocal);
			std::strftime(endTime, sizeof endTime, "%Y-%m-%dT%H:%M:30Z", endLocal);
			sprintf(url, "http://data.fmi.fi/fmi-apikey/5a633ac3-ef79-4ba6-ae28-b3b737b76871/wfs?request=getFeature&storedquery_id=fmi::forecast::hirlam::surface::point::simple&parameters=temperature&place=%s&starttime=%s&endtime=%s&timestep=1", input.c_str(), startTime, endTime);
			cHandler.initCurl(url);
			cHandler.openAndWrite(input);
			cHandler.cleanUp();
			sleep(delay * 60);
		}
	}
}

/* Function for ending task based on user given location */

int taskHandler::endTask(std::string locationID)
{
	for (int i = 0; i < pidRecords.size(); i++) {
		if (pidRecords.at(i).second == locationID) {
			kill(pidRecords.at(i).first, SIGINT);
			pidRecords.erase(pidRecords.begin()+1);
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

void taskHandler::quitClean()
{
	for (auto &record : pidRecords) {
		kill(record.first, SIGINT);
	}
}

void taskHandler::testFunc()
{
	setenv("FI", "/usr/share/zoneinfo/Europe/Helsinki", 1);
	char startTime[30], endTime[30];

	while (1) {
		std::time_t start = std::time(nullptr);
		std::time_t end = std::time(nullptr);
		std::tm* startLocal = std::localtime(&start);
		std::tm* endLocal = std::localtime(&end);
		std::strftime(startTime, sizeof startTime, "%Y-%m-%dT%H:%M:00Z", startLocal);
		std::strftime(endTime, sizeof endTime, "%Y-%m-%dT%H:%M:30Z", endLocal);
		std::cout << startTime << std::endl;
		std::cout << endTime << std::endl;
		sleep(30);
	}
}
