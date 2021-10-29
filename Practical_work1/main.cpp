#include <iostream>
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


int main() {
	// task_1();
	task_2();

	return 0;
}