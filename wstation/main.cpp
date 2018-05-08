#include "curlHandler.h"
#include "inputParser.h"
#include "menu.h"

#define CURL_TEST   1
#define INPUT_TEST  0
#define MENU_TEST   0
int main() {

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
	inputParser parser(10);
	parser.readInput();
#endif

#if MENU_TEST
	menu menu;
	menu.printMenu();
#endif
	cbreak();
}