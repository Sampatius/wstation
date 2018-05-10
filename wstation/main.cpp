#include "curlHandler.h"
#include "inputParser.h"
#include "menu.h"
#include <iostream>

#define CURL_TEST   1
#define INPUT_TEST  0
#define MENU_TEST   0
int main() {
#if CURL_TEST

		std::string url = "http://data.fmi.fi/fmi-apikey/KEY/wfs?request=getFeature&storedquery_id=fmi::observations::weather::daily::simple&place=helsinki&";

		curlHandler handler;

		handler.initCurl(url);

		handler.openAndWrite("test.out");

		handler.cleanUp();
#endif

#if INPUT_TEST
		inputParser parser;

		std::string input = parser.readInput();
		parser.parseInput(input);

		std::cout << "Inputs: \n";
		for (int i = 0; i < parser.getInputs().size(); i++) {
			std::cout << parser.getInputs().at(i) << '\n';
		}

		std::cout << "Params: \n";
		for (int i = 0; i < parser.getParams().size(); i++) {
			std::cout << parser.getParams().at(i) << '\n';
		}
		input = parser.readInput();
	}
#endif

#if MENU_TEST
	menu menu;
#endif
}