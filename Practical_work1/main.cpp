#include <iostream>
using namespace std;

// Task 1
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


int main() {
	task_1();

	return 0;
}