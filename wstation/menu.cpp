#include "menu.h"



menu::menu() {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	options = new char const*[5];
	options[0] = "1";
	options[1] = "2";
	options[2] = "3";
	options[3] = "4";
	options[4] = "Exit";
}

menu::~menu() {
	delete options;
}

void menu::printMenu() {
	for (int i = 0; i < 5; i++) {
		printf(options[i]);
	}
}