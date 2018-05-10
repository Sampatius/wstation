#pragma once
#include "curlHandler.h"
#include <vector>

class taskHandler
{
public:
	taskHandler();
	~taskHandler();

	void startTask(std::vector<std::string> inputs, std::string location);

private:
	curlHandler cHandler;
	std::string url = "http://data.fmi.fi/fmi-apikey/KEY/wfs?request=getFeature&storedquery_id=fmi::observations::weather::daily::simple&";
};