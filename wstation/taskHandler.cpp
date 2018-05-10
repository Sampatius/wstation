#include "taskHandler.h"



taskHandler::taskHandler()
{
}


taskHandler::~taskHandler()
{
}

void taskHandler::startTask(std::vector<std::string> inputs, std::string location)
{
	for (auto &input : inputs) {
		url.append(input);
		url.append("&");
	}

	cHandler.initCurl(url);

	cHandler.openAndWrite(location);

	cHandler.cleanUp();
}
