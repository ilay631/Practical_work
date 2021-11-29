#include <iostream>
#include <string>
using namespace std;


void sortNames(string* mas, int length) {
	for (int i = 0; i < length - 1; i++) {
		for (int j = i + 1; j < length; j++) {
			if (mas[i] > mas[j]) {
				string t = mas[i];
				mas[i] = mas[j];
				mas[j] = t;
			}
		}
	}
}


void task_1() {
	int n;
	cout << "Input number of names " << endl;
	cin >> n;
	string* nameMas = new string[n];
	for (int i = 0; i < n; i++) {
		cout << "Input name " << i << endl;
		cin >> nameMas[i];
	}
	sortNames(nameMas, n);

	cout << "Sorted list of names" << endl;
	for (int i = 0; i < n; i++) {
		cout << nameMas[i] << endl;
	}
}


int main() {
	task_1();

	return 0;
}