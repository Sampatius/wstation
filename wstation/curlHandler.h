#pragma once
#include <stdlib.h>
#include <curl/curl.h>
#include <stdio.h>
#include <unistd.h>

class curlHandler
{

public:
	curlHandler();
	~curlHandler();

	void initCurl(char const *url);
	void openAndWrite();
	void cleanUp();

	size_t writeData(void *ptr, size_t size, size_t nmemb, void *stream);

private:
	CURL * curl_handle;
	FILE* pagefile;
	char const *pagefilename = "test.out";
};