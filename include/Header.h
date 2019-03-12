#include <vector>
#include <iostream>
using namespace std;

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata 
{
private:
	STATES state;
	unsigned int cash;
	vector<string> menu{ "Americano", "Latte", "Cappucino", "Tea" };
	vector<unsigned int> prices{ 30, 40, 25, 20 };
public:
	Automata();
	void on(); // ��������� ��������
	void off(); // ���������� ��������
	void coin(unsigned int); // ��������� ����� �� ���� �������������
	void cancel(); // ������ ������ ������������ �������������
	bool check(unsigned int); //�������� ������� ����������� �����
	void choice(unsigned int); //����� ������� �������������
	void cook(unsigned int); //�������� �������� ������������� �������
	int getCash();
};
