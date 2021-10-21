#include <iostream>
#include <string>


void outputMas(int* mas, int length) {
	for (int i = 0; i < length; i++) {
		std::cout << mas[i] << " ";
	}
	std::cout << "\n";
}


void task_1() {
	int arr[6]{ 1, 2, 3, 4, 5, 6 };
	int k = 0;
	for (int* i = &k; *i < 6; (*i)++) {
		std::cout << arr[*i] << " ";
	}
}



// TODO
void task_2() {
	using namespace std;

	int var1(10);
	char var2('A');
	bool var3(true);
	short var4(42);
	long var5(228);
	float var6(1.5);
	double var7(1.488);
	long double var8(3.22);
	int arr[5]{ 1, 2, 3, 4, 5 };

	cout << &var1 << "\n";
	cout << &var2 << "\n";
	cout << &var3 << "\n";
	cout << &var4 << "\n";
	cout << &var5 << "\n";
	cout << &var6 << "\n";
	cout << &var7 << "\n";
	cout << &var8 << "\n";
	cout << &arr << "\n";

	cout << (int*)(&var1) - (int*)(&var2) << " - " << sizeof(var2) << "\n";
	cout << (int*)(&var2) - (int*)(&var3) << " - " << sizeof(var3) << "\n";
	cout << (int*)(&var3) - (int*)(&var4) << " - " << sizeof(var4) << "\n";
	cout << (int*)(&var4) - (int*)(&var5) << " - " << sizeof(var5) << "\n";
	cout << (int*)(&var5) - (int*)(&var6) << " - " << sizeof(var6) << "\n";
	cout << (int*)(&var6) - (int*)(&var7) << " - " << sizeof(var7) << "\n";
	cout << (int*)(&var7) - (int*)(&var8) << " - " << sizeof(var8) << "\n";
	cout << (int*)(&var8) - (int*)(&arr) << " - " << sizeof(arr) << "\n";
}



void task_3(int n, int m) {
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = rand() % 100 + 1;
			std::cout << arr[i][j] << " ";
		}
		std::cout << "\n";
	}

}



void task_4() {
	int length;
	std::cin >> length;
	char* arr = new char[length];
	for (int i = 0; i < length; i++) {
		arr[i] = char (rand() % 128);
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

	for (int i = 0; i < length; i++) {
		std::cout << (void*) &arr[i] << "\n";
	}
}



void task_5() {
	int length;
	std::cout << "Input massive length\n";
	std::cin >> length;
	int* mas = new int[length];
	for (int i = 0; i < length; i++)
		mas[i] = rand() % 200 - 100;

	std::cout << "Original massive\n";
	outputMas(mas, length);

	std::cout << "Reverse massive\n";
	int* ind = mas + length - 1;
	for (int i = 0; i < length; i++) {
		std::cout << *ind << " ";
		ind--;
	}

}



int main() {
	// task_1();

	// task_2();

	// task_3(10, 10);

	// task_4();

	task_5();

	return 0;
}
