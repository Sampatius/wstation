#include "logger.h"



logger::logger()
{
}


logger::~logger()
{
}

/* Open both error and report logs for write with append */
void logger::openFile()
{
	errorDesc = open("error.log", (O_CREAT | O_WRONLY | O_APPEND), (S_IRUSR | S_IWUSR));
	reportDesc = open("report.log", (O_CREAT | O_WRONLY | O_APPEND), (S_IRUSR | S_IWUSR));

}

/* Close both files */
void logger::closeFile()
{
	close(errorDesc);
	close(reportDesc);
}

/* Write to log files based on the log type */
void logger::writeLog(int logType, std::string input)
{
	char timerBuffer[60];
	time_t logTime;
	int desc;

	if (logType == ERROR_LOG) {
		desc = errorDesc;
	}
	if (logType == REPORT_LOG) {
		desc = reportDesc;
	}

	std::string tempBuff;
	time(&logTime);
	std::tm *timeToLog = localtime(&logTime);
	strftime(timerBuffer, sizeof(timerBuffer), "(%Y-%m-%d %H:%M:%S) ", timeToLog);
	tempBuff = timerBuffer + input + '\n';
	write(desc, tempBuff.c_str(), tempBuff.size());
}
