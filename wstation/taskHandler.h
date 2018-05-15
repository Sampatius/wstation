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

	void startTask(std::vector<std::string> inputs, int delay);
	void endTask(std::string locationID);
	void recordTask(pid_t pid, std::string locationID);

private:
	curlHandler cHandler;
	std::string url = "http://data.fmi.fi/fmi-apikey/KEY/wfs?request=getFeature&storedquery_id=fmi::observations::weather::daily::simple&place=helsinki&";
	pid_t pid;
	std::vector<std::pair<pid_t, std::string>> pidRecord;
};
