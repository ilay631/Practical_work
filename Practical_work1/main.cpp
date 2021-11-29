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


void sortThreeVariables(int* p1, int* p2, int* p3) {
	int a = *p1;
	int b = *p2;
	int c = *p3;
	*p1 = max(max(a, b), c);
	*p3 = min(min(a, b), c);
	int sr = a + b + c - *p1 - *p3;
	*p2 = sr;
}


void task_2() {
	int a, b, c;
	cout << "Input three variables" << endl;
	cin >> a >> b >> c;

	int* p_a = &a;
	int* p_b = &b;
	int* p_c = &c;

	sortThreeVariables(p_a, p_b, p_c);

	cout << a << " " << b << " " << c << endl;
}


void rearrangeBytesInCircle(int* num) {
	int last_b = *num % 256;
	*num >>= 24;
	*num += last_b * 256 * 256 * 256;
}


void task_3() {
	int num(0);
	int* p_num = &num;
	cout << "Input int number" << endl;
	cin >> *p_num;

	rearrangeBytesInCircle(p_num);

	cout << *p_num << endl;
}


void aliveFunction(int N) {
	static int n = -10;
	if (n == -10) {
		n = N;
		cout << "Hello world! I was born!!!" << endl;
	}
	else if (n > 0) {
		n--;
		cout << "I'm alive" << endl;
	}
	else if (n == 0) {
		cout << "Bye, bye, dear, I'm already asleep..." << endl;
	}
}


void task_4() {
	int n, m;
	cout << "Input life number of function" << endl;
	cin >> m;
	cout << "Input number of calls" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		aliveFunction(m);
	}
}



int main() {
	// task_1();
	// task_2();
	// task_3();
	task_4();

	return 0;
}