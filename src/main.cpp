#include "auto.h"

int main() {
	setlocale(LC_ALL, "Russian");
	std::vector<std::string> menu = { "Cap", "Tea", "Coffe","Espresso" };
	std::vector<double> price = { 30.0, 20.0, 25.0, 35.0 };
	Automata tmp(price, menu);
	tmp.on();
	tmp.coin(10.0);
}
