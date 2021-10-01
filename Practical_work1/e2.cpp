/*
ѕусть дано a Ч основание равнобедренного треугольника, S Ч
его площадь. Ќайти минимальную высоту h.
¬ход: N Ц количество тестов, a Ч основание (int), S Ч площадь
(int).
¬ыход: h ЦЧ минимальна€ высота треугольника
*/

#include <iostream>

void findMinHeight() {
	using namespace std;
	int a, S;
	cout << "Input base of triangle ";
	cin >> a;
	cout << "Input square of triangle ";
	cin >> S;

	double h1 = 2.f * S / a;
	double b = sqrt(pow(a, 2) / 4 + pow(h1, 2));
	double h2 = 2.f * S / b;

	cout << "Min height of this triangle = " << min(h1, h2) << endl;
}
