/*
Пусть дано целое число F. Проверить является ли число F одним
из чисел ряда Фибоначчи.
Вход: N – количество тестов, F — целое число.
Выход: строка «Фибоначчи», если F является числом Фибоначчи, «Увы», если не является
*/
#include <iostream>

void isFibonacci() {
	using namespace std;
	setlocale(LC_ALL, "Russian");
	
	int num;
	cout << "Введите число ";
	cin >> num;

	int fib1(1), fib2(1);
	while (fib2 < num) {
		int t = fib2 + fib1;
		fib1 = fib2;
		fib2 = t;
	}

	if (num == fib2)
		cout << "Фибоначчи" << endl;
	else
		cout << "Увы" << endl;

}