#pragma once
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <ctime>

class logger
{
public:
	logger();
	~logger();

	void openFile();
	void closeFile();
	void writeLog(std::string input);

private:
	int fileDesc;
};

