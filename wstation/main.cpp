#include "curlHandler.h"
#include "inputParser.h"
#include "menu.h"
#include <iostream>

#define CURL_TEST   0
#define INPUT_TEST  1
#define MENU_TEST   0
int main() {

	while (1) {
#if CURL_TEST
		char url[250];
		char loc[] = "helsinki";

		sprintf(url, "http://data.fmi.fi/fmi-apikey/5a633ac3-ef79-4ba6-ae28-b3b737b76871/wfs?request=getFeature&storedquery_id=fmi::observations::weather::daily::simple&place=%s&parameters=temperature&", loc);

		curlHandler handler;

		handler.initCurl(url);

		handler.openAndWrite();

		handler.cleanUp();
#endif

#if INPUT_TEST
		inputParser parser;
		parser.readInput();
		parser.parseInput();
		std::vector<std::string> test = parser.getCommmands();

		for (int i = 0; i < test.size(); i++) {
			std::cout << test[i] << '\n';
		}

		parser.readInput();
#endif

#if MENU_TEST
		menu menu;
#endif
		cbreak();
	}
}