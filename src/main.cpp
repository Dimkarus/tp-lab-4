#include "auto.h"

int main() {
	setlocale(LC_ALL, "Russian");
	std::vector<std::string> menu = { "Cap", "Tea", "Coffe","Espresso" };
	std::vector<int> price = { 30, 20, 25, 35 };
	Automata tmp;
	tmp.on();
	tmp.coin(10);
}
