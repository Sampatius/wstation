#pragma once
#include <curses.h>
#include <menu.h>

class menu
{
public:
	menu();
	~menu();

	void printMenu();

private:
	ITEM * *my_items;
	int c;
	MENU *my_menu;
	int n_choices, i;
	ITEM *cur_item;

	char const **options;
};