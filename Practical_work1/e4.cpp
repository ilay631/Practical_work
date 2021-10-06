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

	int bday, bmonth, byear;
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	cout << "Input your birthday" << endl;
	cin >> bday >> bmonth >> byear;


	int livedDays = month[curMonth - 1] - bday;
	for (int i = bmonth - 1; i < 12; i++) {
		livedDays += month[i];
	}
	for (int i = byear; i < curYear - 1; i++) {
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			livedDays += 366;
		else
			livedDays += 365;
	}
	for (int i = 0; i < curMonth - 2; i++) {
		livedDays += month[i];
	}

	livedDays += curDay;

	cout << livedDays << endl;

}
