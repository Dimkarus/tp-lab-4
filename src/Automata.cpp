#include "Automata.h"
#include <iostream>
#include <string>
using namespace std;

Automata::Automata() {
	state = OFF;
	cash = 0;	
}

string Automata::on() {             //��������� �������� 
	if (state == OFF) {
		state = WAIT;
		cout << "Hello!" << endl;
	}
	return "Hello!";
}

string Automata::off() {             //���������� ��������
	if (state != OFF) {
		if (state == WAIT) {
			state = OFF;
			cout << "Goodbye!" << endl;
			return "Goodbye!";
		}
		else {
			cout << "You cannot turn off the automata right now" << endl;     //������� ������
			return "You cannot turn off the automata right now";
		}
	}
	return "0";
}

int Automata::coin(int ca) {           //��������� ����� �� ���� ������������� 
	if (state != OFF) {
		state = ACCEPT;
		cash = cash + ca;
		cout << "Cash is " << cash << endl;
		return cash;
	}
	return 0;
}

void Automata::printMenu() {      //����������� ���� � ��������� � ������ ��� ������������
	if (state != OFF) {
		state = CHECK;
		for (int i = 0; i < 4; i++) {
			cout << i + 1 << " - " << menu[i] << " -- " << prices[i] << endl;
		}
	}
}

string Automata::printState() {     //����������� �������� ��������� ��� ������������
	if (state != OFF) {
		string str;
		switch (state) {
		case 0:
			str = "OFF";
			break;
		case 1:
			str = "WAIT";
			break;
		case 2:
			str = "ACCEPT";
			break;
		case 3:
			str = "CHECK";
			break;
		case 4:
			str = "COOK";
			break;
		}
		cout << str << endl;
		return str;
	}
	return "0";
}

string Automata::choice(int cho) {         //����� ������� �������������;
	if (state != OFF) {
		state = CHECK;
		if (cash >= prices[cho - 1]) {
			cash = cash - prices[cho - 1];
			Automata::cook(cho - 1);
			return "Ok";
		}
		else {
			cout << "Give more money or make another choice" << endl;
			return "Give more money or make another choice";
		}
	}
	return "0";
}

void Automata::cook(int cho) {           //�������� �������� ������������� �������;
	state = COOK; 
	cout << menu[cho] << " is cooking" << endl;
	//cook
	Automata::finish();
}

string Automata::finish() {         //���������� ������������ ������������
	state = CHECK;
	cout << "Done! Cash is " << cash << endl; 
	return "Done!";
}

int Automata::change() {         //������ �����
	if (state != OFF) {
		int c = cash;
		cash = 0;
		state = WAIT;
		return c;
	}
	return 0;
}

