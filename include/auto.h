#pragma once
#include <iostream>
#include <string>
#include <vector>


class Automata
{
private:

	std::vector<int> price;
	std::vector<std::string> menu;
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
	Automata(const std::vector<int> &tmp_price,
		const std::vector<std::string> &tmp_menu);
	void on();
	void off();
	void coin(int mon);
	void printMenu();
	void printState();
	void cancel();
	void choice();
	bool check(int tmp_price);
	void cook(const std::string &tmp_menu);
	void finish();
};
