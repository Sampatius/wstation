#include "logger.h"



logger::logger()
{
}


logger::~logger()
{
}

void logger::openFile()
{
	fileDesc = open("log.txt", (O_CREAT | O_WRONLY | O_APPEND), (S_IRUSR | S_IWUSR));
}

void logger::closeFile()
{
	close(fileDesc);
}

void logger::writeLog(std::string input)
{
	char timerBuffer[30];
	time_t logTime;

	std::string tempBuff;
	time(&logTime);
	std::tm *timeToLog = localtime(&logTime);
	strftime(timerBuffer, sizeof timerBuffer, "(%Y-%m-%d %H:%M:%S) ", timeToLog);
	input.append("\n");
	tempBuff = timerBuffer + input;
	write(fileDesc, tempBuff.c_str(), sizeof(tempBuff));
}
