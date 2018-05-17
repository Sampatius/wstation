#pragma once
#include "curlHandler.h"
#include <vector>
#include <unistd.h>
#include <signal.h>
#include <ctime>
#include <locale>

class taskHandler
{
public:
	taskHandler();
	~taskHandler();

	inline std::vector<std::pair<pid_t, std::string>> getRecords() { return pidRecords; }

	void startTask(std::string input, int delay);
	int endTask(std::string locationID);
	void recordTask(pid_t pid, std::string locationID);
	void quitClean();
	void testFunc();

private:
	curlHandler cHandler;
	char* url;
	pid_t pid;
	std::vector<std::pair<pid_t, std::string>> pidRecords;
};