#pragma once
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <ctime>

#define ERROR_LOG	1
#define REPORT_LOG	2

class logger
{
public:
	logger();
	~logger();

	void openFile();
	void closeFile();
	void writeLog(int logType, std::string input);

private:
	int errorDesc, reportDesc;
};

