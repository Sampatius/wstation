#pragma once
#include "curlHandler.h"
#include <vector>
#include <unistd.h>
#include <signal.h>

class taskHandler
{
public:
	taskHandler();
	~taskHandler();

	void startTask(std::string input, int delay);
	int endTask(std::string locationID);
	void recordTask(pid_t pid, std::string locationID);
	void testFunc();

private:
	curlHandler cHandler;
	std::string url = "http://data.fmi.fi/fmi-apikey/KEY/wfs?request=getFeature&storedquery_id=fmi::observations::weather::daily::simple&place=helsinki&starttime=2018-05-14T00:00:00Z&endtime=2018-05-15T00:00:00Z&parameters=tday&timestep=60&";
	pid_t pid;
	std::vector<std::pair<pid_t, std::string>> pidRecords;
};