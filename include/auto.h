#pragma once
#include <iostream>
#include <string>
#include <vector>


class Automata
{
private:

	std::vector<std::string> menu = { "Cap", "Tea", "Coffe","Espresso" };
	std::vector<int> price = { 30, 20, 25, 35 };
	int cash;
	enum STATES {
		OFF,
		WAIT,
		ACCEPT,
		CHECK,
		COOK
	};
	STATES state;
public:
	Automata();
	void on();
	void off();
	void coin(int mon);
	void printMenu();
	void printState();
	void cancel();
	void choice(int tmp_choice);
	bool check(int tmp_price);
	void cook(const std::string &tmp_menu);
	void finish();
};
