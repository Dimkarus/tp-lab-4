#include "auto.h"


Automata::Automata(const std::vector<double> &tmp_price,
	const std::vector<std::string> &tmp_menu) {
	this->price = tmp_price;
	this->menu = tmp_menu;
	this->cash = 0.0;
	this->state = OFF;
}

void Automata::on() {
	this->state = WAIT;
}

void Automata::off() {
	this->state = OFF;
}

void Automata::coin() {
	this->state = ACCEPT;
	double money;
	std::cout << "������� ��������" << std::endl;
	std::cin >> money;
	if (money < 0) {
		std::cout << "������ ����� �������� �������" << std::endl;
		coin();
	}
	else {
		this->cash += money;
		choice();
	}
}

void Automata::printMenu() {
	for (size_t i = 0; i < this->price.size(); ++i) {
		std::cout << i + 1 << " - " << this->menu[i] << " - " << this->price[i] << "���." << std::endl;
	}
}

void Automata::printState() {
	switch (state) {
	case OFF:
		std::cout << "���������";
	case WAIT:
		std::cout << "��������";
	case ACCEPT:
		std::cout << "���� �����";
	case CHECK:
		std::cout << "�������� ����������";
	case COOK:
		std::cout << "�������������";
	}
	std::cout << std::endl;
}


void Automata::choice() {
	this->state = CHECK;
	int tmp;
	std::cout << "�������� �������" << std::endl;
	printMenu();
	std::cin >> tmp;
	if (tmp == 0 || tmp > this->menu.size()) {
		std::cout << "�������� ����" << std::endl;
	}
	else {
		if (check(price[tmp - 1])) {
			this->cash -= price[tmp - 1];
			cook(menu[tmp - 1]);
		}
		else {
			std::cout << "������������ �������" << std::endl;
			coin();
			choice();
		}
	}
}

bool Automata::check(double tmp_price) {
	return tmp_price <= this->cash;
}

void Automata::finish() {
	this->state = WAIT;
}

void Automata::cook(const std::string &tmp_menu) {
	this->state = COOK;
	std::cout << "������������� " << tmp_menu << std::endl;
	finish();
}

void Automata::cancel() {
	this->state = WAIT;
}


