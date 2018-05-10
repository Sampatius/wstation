#pragma once
#include <stdlib.h>
#include <curl/curl.h>
#include <stdio.h>
#include <string>
#include <unistd.h>

class curlHandler
{

public:
	curlHandler();
	~curlHandler();

	void initCurl(std::string url);
	void openAndWrite(std::string filename);
	void cleanUp();

private:
	CURL * curl_handle;
	FILE* pagefile;
};