#include "curlHandler.h"

/*	Init function
Responsible for setting up curl for use

PARAMS:
char* url	URL to site
*/

curlHandler::curlHandler() {

}

curlHandler::~curlHandler() {

}

void curlHandler::initCurl(char const *url) {

	curl_global_init(CURL_GLOBAL_ALL);

	// Init curl session
	curl_handle = curl_easy_init();

	// Set URL
	curl_easy_setopt(curl_handle, CURLOPT_URL, url);

	// Use full protocol / debug output while testing
	curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1L);

	// Disable progress meter
	curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);

	// Send all data to this write function
	curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, writeData(0, 0, 0, 0));
}

/*	File handler function
Responsible for opening, closing and handling the file
*/

void curlHandler::openAndWrite() {

	// Open the file
	pagefile = fopen(pagefilename, "wb");
	if (pagefile) {

		// Write the page body to this file handle
		curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, pagefile);

		// Get it
		curl_easy_perform(curl_handle);

		// CLose the file
		fclose(pagefile);
	}
}

/*	Write function
Used to write the data to stream
*/
size_t curlHandler::writeData(void *ptr, size_t size, size_t nmemb, void *stream) {
	size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
	return written;
}

/*	Clean up function
Performs required cleans for curl
*/
void curlHandler::cleanUp() {
	curl_easy_cleanup(curl_handle);

	curl_global_cleanup();
}