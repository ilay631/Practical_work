#include <iostream>
#include "header.h"


int main() {
	int N;
	std::cout << "Input number of tests ";
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		findPoint();
	}
	return 0;
}
