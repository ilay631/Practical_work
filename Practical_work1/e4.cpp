/*
Человек вводит свою дату рождения в виде 10 09 1995, и хочет
получить сколько дней он прожил до сегодня. Поможете ему?
*/

#include <iostream>
#include <ctime>

struct DayPerMonth {
	int january = 31;
	int february = 28;
	int march = 31;
	int april = 30;
	int may = 31;
	int june = 30;
	int july = 31;
	int august = 30;
	int september = 31;
	int october = 30;
};


void daysYourLive() {
	using namespace std;
	int day, month, year;
	cout << "Input your birthday";
	cin >> day >> month >> year;

	
	

}