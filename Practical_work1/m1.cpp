/*
����� ���� ����� ����� F. ��������� �������� �� ����� F �����
�� ����� ���� ���������.
����: N � ���������� ������, F � ����� �����.
�����: ������ ����������, ���� F �������� ������ ���������, �����, ���� �� ��������
*/
#include <iostream>

void isFibonacci() {
	using namespace std;
	setlocale(LC_ALL, "Russian");
	
	int num;
	cout << "������� ����� ";
	cin >> num;

	int fib1(1), fib2(1);
	while (fib2 < num) {
		int t = fib2 + fib1;
		fib1 = fib2;
		fib2 = t;
	}

	if (num == fib2)
		cout << "���������" << endl;
	else
		cout << "���" << endl;

}