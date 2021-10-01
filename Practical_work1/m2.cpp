/*
Дано число целое число A и B. Можно ли представить число A в
виде суммы B простых чисел. Например, A = 14, B = 2, 13 + 1 =
14 — да. Вход: N – количество тестов, A, B — целые числа (int).
Выход: h –— строка "Да "Нет".
*/

#include <iostream>


int isSimple(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}


void numberSumOfPrimes() {
    using namespace std;
	setlocale(LC_ALL, "Russian");

    int num, N;
	cout << "Введите число ";
    cin >> num;
	cout << "Введите количество простых чисел ";
	cin >> N;

	for (int i = 2; i < num; i++) {
		if (isSimple(i))
			cout << i << " ";
	}

	if (N > num / 2)
		cout << "Нет" << endl;
	else
		cout << "Да" << endl;

}