#include <iostream>


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
	cout << (void*) &var2 << "\n";
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


int task_6(void* p1, void* p2) {
	if (p1 == p2)
		return 1;
	else
		return 0;
}


// Task 7
int** createUpperTriangularMatrix(int n) {
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int [n - i];
	}

	return matrix;
}


void fillMatrix(int** mat, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			mat[i][j] = rand() % 200 - 100;
		}
	}
}


void outputMatrix(int** mat, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j < i)
				std::cout << 0 << " ";
			else
				std::cout << mat[i][j - i] << " ";
		}
		std::cout << "\n";
	}
}


const int* findRefInMatrix(int** mas, int line, int col) {
	static const int zero = 0;
	if (col < line)
		return &zero;
	else
		return &mas[line][col - line];
}


int* task_8() {
	static int variable;
	std::cout << "Variable created with type int. \n";
	int* p = &variable;
	return p;
}


// Task 9
void mySwap(int& a, int& b) {
	a = a + b;
	b = a - b;
	a = a - b;
}


void quickSortRecursive(int* mas, int length) {
	int i = 0;
	int j = length - 1;
	int mid = mas[length / 2];

	do {
		while (mas[i] < mid) {
			i++;
		}
		while (mas[j] > mid) {
			j--;
		}

		if (i <= j) {
			mySwap(mas[i], mas[j]);

			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) {
		quickSortRecursive(mas, j + 1);
	}
	if (i < length) {
		quickSortRecursive(&mas[i], length - i);
	}
}


// Task 10
bool normalComprassion(int a, int b) {
	if (a > b)
		return true;
	else
		return false;
}


void insertSort(int* mas, int length, bool (*func)(int, int)) {
	for (int i = 0; i < length; i++) {
		for (int j = i + 1; j < length; j++) {
			if (func(mas[i], mas[j])) {
				int t = mas[i];
				mas[i] = mas[j];
				mas[j] = t;
			}
		}
	}
}


int main() {
	// task_1();

	// task_2();

	// task_3(10, 10);

	// task_4();

	// task_5();

	// Task 6
	/*
	int x = 10;
	int* p1 = &x;
	int* p2 = &x;
	std::cout << task_6(p1, p2);
	*/

	// Task 7
	/*
	int** mat = createUpperTriangularMatrix(5);
	fillMatrix(mat, 5);
	outputMatrix(mat, 5);
	std::cout << &mat[0][2] << "\n" << findRefInMatrix(mat, 0, 2);
	*/

	// std::cout << task_8();

	// Task 9
	/*
	int* mas = new int[10];
	for (int i = 0; i < 10; i++) {
		mas[i] = rand() % 200 - 100;
	}
	outputMas(mas, 10);
	quickSortRecursive(mas, 10);
	outputMas(mas, 10);
	*/

	// Task 10
	/*
	int* mas = new int[10];
	for (int i = 0; i < 10; i++) {
		mas[i] = rand() % 200 - 100;
	}
	outputMas(mas, 10);
	insertSort(mas, 10, &normalComprassion);
	outputMas(mas, 10);
	*/

	return 0;
}
