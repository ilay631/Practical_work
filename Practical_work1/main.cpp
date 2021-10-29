#include <iostream>
#include <string>
using namespace std;


// Task 1.
int sumOfDigits(int num) {
	int s = 0;
	while (num > 0) {
		s += num % 10;
		num /= 10;
	}
	return s;
}


void task_1() {
	int a, b;
	cout << "Input borders\n";
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		int sum = sumOfDigits(i);
		bool fl = true;
		for (int j = 2; j <= 9; j++) {
			if (sum != sumOfDigits(i * j)) {
				fl = false;
			}
		}

		if (fl)
			cout << i << endl;
	}
}


// Task 2.
void task_2() {
	int n;
	cout << "Input number n\n";
	cin >> n;
	int m = 0;
	for (int i = 0; i <= pow(n, 1.0 / 3); i++) {
		if (n % (int)(pow(3, i)) == 0)
			m = i;
	}
	cout << m << endl;
}


// Task 3
string convertFullName(string fullName) {
	string name("");
	string surname(""); 
	string patronymic("");
	int k = 0;
	for (int i = 0; i < fullName.size(); i++) {
		if (fullName[i] == ' ') {
			k++;
			continue;
		}

		if (k == 0)
			name += fullName[i];
		else if (k == 1)
			patronymic += fullName[i];
		else
			surname += fullName[i];
	}

	return surname + " " + name[0] + "." + patronymic[0] + ".";
}


void task_3() {
	string fullName;
	cout << "Input your full name" << endl;
	getline(cin, fullName);
	cout << convertFullName(fullName) << endl;
}



int main() {
	// task_1();
	// task_2();
	task_3();
	
	return 0;
}