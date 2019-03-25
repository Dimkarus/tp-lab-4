#pragma once
#include <iostream>
#include <string>
#include <vector>


class Automata
{
private:

	std::vector<double> price;
	std::vector<std::string> menu;
	double cash;
	enum STATES {
		OFF,
		WAIT,
		ACCEPT,
		CHECK,
		COOK
	};
	STATES state;
public:
	Automata(const std::vector<double> &tmp_price,
		const std::vector<std::string> &tmp_menu);
	void on();
	void off();
	void coin(double mon);
	void printMenu();
	void printState();
	void cancel();
	void choice();
	bool check(double tmp_price);
	void cook(const std::string &tmp_menu);
	void finish();
};
