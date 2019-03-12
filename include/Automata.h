#pragma once
//#include <iostream>
#include <string>
using namespace std;

#ifndef _AUTOMATA_H_
#define _AUTOMATA_H_

enum STATES {
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata {
private:
	int cash;              //��� �������� ������� �����
	string menu[4] = { "Cappuccino", "Latte     ", "Espresso  ", "Americano " };       //������ ����� �������� ��������
	int prices[4] = { 70, 80, 90, 100 };        //������ ��� ��������(������������� ������� menu)
	STATES state = OFF;    //������� ��������� ��������
	void cook(int);
	string finish();

public:
	Automata();
	string on();             //��������� �������� 
	string off();            //���������� ��������
	int coin(int);           //��������� ����� �� ���� ������������� 
	void printMenu();      //����������� ���� � ��������� � ������ ��� ������������
	string printState();     //����������� �������� ��������� ��� ������������
	string choice(int);         //����� ������� �������������;
	//void check(int);          //�������� ������� ����������� �����;
	//void cancel();         //������ ������ ������������ �������������;
	int change();        //�����
};

#endif