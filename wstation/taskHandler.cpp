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
	// Set the terminal locale
	setenv("FI", "/usr/share/zoneinfo/Europe/Helsinki", 1);
	char startTime[30], endTime[30];

	// Fork and let the child process handle curl
	pid = fork();

	// Record the child process' pid and identifier to a Vector
	recordTask(pid, input);

	if (pid == 0) {
		while (1) {
			printf("CHILD RUNNING!\n");
			// Get current time and format them to ISO 8601 format
			std::time_t start = std::time(nullptr);
			std::time_t end = std::time(nullptr);
			std::tm* startLocal = std::localtime(&start);
			std::tm* endLocal = std::localtime(&end);
			std::strftime(startTime, sizeof(startTime), "%Y-%m-%dT%H:%M:00Z", startLocal);
			std::strftime(endTime, sizeof(endTime), "%Y-%m-%dT%H:%M:30Z", endLocal);

			// Set up the url with given location and current start and end times
			sprintf(url, "http://data.fmi.fi/fmi-apikey/5a633ac3-ef79-4ba6-ae28-b3b737b76871/wfs?request=getFeature&storedquery_id=fmi::forecast::hirlam::surface::point::simple&parameters=temperature&place=%s&starttime=%s&endtime=%s&timestep=1", input.c_str(), startTime, endTime);
			
			// Handle curl stuff
			cHandler.initCurl(url);
			cHandler.openAndWrite(input);
			cHandler.cleanUp();

			// Sleep for the desired time
			sleep(delay * 60);
		}
	}
}

/* Function for ending task based on user given location */

int taskHandler::endTask(std::string locationID)
{
	/*	Loop through the pidRecords Vector and kill the child process based on it's identifier,
		remove the terminated child process from the vector. Return value based on the success of 
		termination.
	*/
	for (int i = 0; i < pidRecords.size(); i++) {
		if (pidRecords.at(i).second == locationID) {
			kill(pidRecords.at(i).first, SIGHUP);
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

/* Kill all childs before exiting */

void taskHandler::quitClean()
{
	for (auto &record : pidRecords) {
		kill(record.first, SIGHUP);
	}
}
