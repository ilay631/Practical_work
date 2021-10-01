#include <iostream>

void findPoint() {
	int N, x1, x2, y1, y2;
	std::cout << "Input number of tests ";
 	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cout << "Input coord of first point ";
		std::cin >> x1 >> y1;
		std::cout << "Input coord of second point ";
		std::cin >> x2 >> y2;

		std::cout << "Coord point 90 degree of : " << -(y2 - y1) << " ; " << (x2 - x1) << std::endl;
	}


}