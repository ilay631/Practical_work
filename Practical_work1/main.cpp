#include <iostream>



void task1() {
	int arr[6]{ 1, 2, 3, 4, 5, 6 };
	int k = 0;
	for (int* i = &k; *i < 6; (*i)++) {
		std::cout << arr[*i] << " ";
	}
}






int main() {
	// Task 1
	task1();

	// Task 2




	return 0;
}
