#include "curlHandler.h"

curlHandler::curlHandler() 
{

}

curlHandler::~curlHandler() 
{

}

/*	Init function
	Responsible for setting up curl for use
*/

void curlHandler::initCurl(std::string url) 
{

	curl_global_init(CURL_GLOBAL_ALL);

	// Init curl session
	curl_handle = curl_easy_init();

	// Set URL
	curl_easy_setopt(curl_handle, CURLOPT_URL, url.c_str());

	// Use full protocol / debug output while testing
	//curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1L);

	// Disable progress meter
	//curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);

	// Send all data to this write function
	curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, NULL);
}

/*	File handler function
	Responsible for opening, closing and handling the file
*/

void curlHandler::openAndWrite(std::string filename) 
{

	// Open the file
	pagefile = fopen(filename.c_str(), "ab");
	if (pagefile) {

		// Write the page body to this file handle
		curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, pagefile);

		// Get it
		curl_easy_perform(curl_handle);

		// CLose the file
		fclose(pagefile);
	}
}

/*	Clean up function
	Performs required cleans for curl
*/
void curlHandler::cleanUp() 
{
	curl_easy_cleanup(curl_handle);

	curl_global_cleanup();
}