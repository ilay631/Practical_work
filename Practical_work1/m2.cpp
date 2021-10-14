/*
���� ����� ����� ����� A � B. ����� �� ����������� ����� A �
���� ����� B ������� �����. ��������, A = 14, B = 2, 13 + 1 =
14 � ��. ����: N � ���������� ������, A, B � ����� ����� (int).
�����: h �� ������ "�� "���".
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
	cout << "������� ����� ";
    cin >> num;
	cout << "������� ���������� ������� ����� ";
	cin >> N;

	if (N <= num / 2 && (isSimple(num) || N > 2))
		cout << "��" << endl;
	else
		cout << "���" << endl;

}