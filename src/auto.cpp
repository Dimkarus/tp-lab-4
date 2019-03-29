#include "auto.h"


Automata::Automata() {
	this->cash = 0;
	this->state = OFF;
}

void Automata::on() {
	this->state = WAIT;
}

void Automata::off() {
	this->state = OFF;
}

void Automata::coin(int mon) {
	this->state = ACCEPT;
	int money = mon;
	std::cout << "Ââåäèòå ñðåäñòâà" << std::endl;
	//std::cin >> money;
	if (money < 0) {
		std::cout << "Îøèáêà ââîäà äåíåæíûõ ñðåäñòâ" << std::endl;
		coin(0);
	}
	else {
		this->cash += money;
		choice();
	}
}

void Automata::printMenu() {
	for (size_t i = 0; i < this->price.size(); ++i) {
		std::cout << i + 1 << " - " << this->menu[i] << " - " << this->price[i] << "ðóá." << std::endl;
	}
}

void Automata::printState() {
	switch (state) {
	case OFF:
		std::cout << "Âûêëþ÷åíî";
	case WAIT:
		std::cout << "Îæèäàíèå";
	case ACCEPT:
		std::cout << "Ïðè¸ì äåíåã";
	case CHECK:
		std::cout << "Ïðîâåðêà íàëè÷íîñòè";
	case COOK:
		std::cout << "Ïðèãîòîâëåíèå";
	}
	std::cout << std::endl;
}


void Automata::choice(int tmp_choice) {
	this->state = CHECK;
	int tmp;
	std::cout << "Âûáåðèòå íàïèòîê" << std::endl;
	printMenu();
	//std::cin >> tmp;
	tmp = tmp_choice;
	if (tmp == 0 || tmp > this->menu.size()) {
		std::cout << "Íåâåðíûé ââîä" << std::endl;
	}
	else {
		if (check(price[tmp - 1])) {
			this->cash -= price[tmp - 1];
			cook(menu[tmp - 1]);
		}
		else {
			std::cout << "Íåäîñòàòî÷íî ñðåäñòâ" << std::endl;
			cancel();
		}
	}
}

bool Automata::check(int tmp_price) {
	return tmp_price <= this->cash;
}

void Automata::finish() {
	this->state = WAIT;
	std::cout<<"Your cash: " << this->cash << std::endl;
	this->cash = 0;
}

void Automata::cook(const std::string &tmp_menu) {
	this->state = COOK;
	std::cout << "Ïðèãîòîâëåíèå " << tmp_menu << std::endl;
	finish();
}

void Automata::cancel() {
	this->state = WAIT;
}


