/*
Пусть даны две точки с координатами a = (x1, y1) и b = (x2, y2).
Найти такую точку c = (x3, y3), которая получается при проведении отрезка между точками a и b и повороте его на 90◦ по часовой
стрелке.
Вход: N —– количество тестов, x1, y1, x2, y2 — координаты точек
и b(int).
Выход: x3, y3 — координаты результирующей точки
*/


#include <iostream>

void findPoint() {
	int x1, x2, y1, y2;
	
	std::cout << "Input coord of first point ";
	std::cin >> x1 >> y1;
	std::cout << "Input coord of second point ";
	std::cin >> x2 >> y2;

	std::cout << "Coord point 90 degree of: (" << -(y2 - y1) + x1 << "; " << (x2 - x1) + y1 << ")\n";
}
