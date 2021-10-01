#include <iostream>

void findPoint() {
	int x1, x2, y1, y2;
	
	std::cout << "Input coord of first point ";
	std::cin >> x1 >> y1;
	std::cout << "Input coord of second point ";
	std::cin >> x2 >> y2;

	std::cout << "Coord point 90 degree of: (" << -(y2 - y1) + x1 << "; " << (x2 - x1) + y1 << ")\n";
}
