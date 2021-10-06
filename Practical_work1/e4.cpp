/*
Человек вводит свою дату рождения в виде 10 09 1995, и хочет
получить сколько дней он прожил до сегодня. Поможете ему?
*/

#include <iostream>
#include <Windows.h>


void daysYourLive() {
	using namespace std;
	SYSTEMTIME st;
	GetLocalTime(&st);
	int curDay = st.wDay;
	int curMonth = st.wMonth;
	int curYear = st.wYear;

	int bDay, bMonth, bYear;
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	cout << "Input your birthday" << endl;
	cin >> bDay >> bMonth >> bYear;

	int livedDays = 0;

	if (bYear != curYear || bMonth != curMonth) {
		livedDays += month[bMonth - 1] - bDay + 1;
	}

	if (bYear != curYear) {
		for (int i = bMonth; i < 12; i++) {
			livedDays += month[i];
		}
	}

	for (int i = bYear + 1; i < curYear; i++) {
		livedDays += 365;
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			livedDays++;
	}

	if (bMonth + 1 < curMonth) {
		for (int i = 0; i < curMonth - 1; i++) {
			livedDays += month[i];
		}
	}

	livedDays += curDay;

	cout << livedDays << endl;

}
