/*
Человек вводит свою дату рождения в виде 10 09 1995, и хочет
получить сколько дней он прожил до сегодня. Поможете ему?
*/

#include <iostream>
#include <Windows.h>


bool isLeapYear(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	else
		return false;
}



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
	// Проверка на дурака
	if (bYear > curYear || (bYear == curYear && bMonth > curMonth) || (bYear == curYear && bMonth == curMonth && bDay > curDay))
		cout << "Error, date is incorrect!" << endl;
	else {
		int livedDays = 0;

		if (bYear == curYear) {
			if (bMonth == curMonth) { // один и тот же год, один и тот же месяц
				livedDays += curDay - bDay;
			}
			else { // один и тот же год, разные месяца
				livedDays += month[bMonth - 1] - bDay;
				for (int i = bMonth; i < curMonth - 1; i++) {
					livedDays += month[i];
					if (i == 1 && isLeapYear(bYear)) // Учли високосный ферваль
						livedDays++;
				}
				livedDays += curDay;
			}
		}
		else { // разные года
			livedDays += month[bMonth - 1] - bDay;
			for (int i = bMonth; i < 12; i++) {
				livedDays += month[i];
				if (i == 1 && isLeapYear(bYear)) // Учли високосный ферваль
					livedDays++;
			}

			for (int i = bYear + 1; i < curYear; i++) {
				livedDays += 365;
				if (isLeapYear(i))
					livedDays++;
			}

			for (int i = 0; i < curMonth - 1; i++) {
				livedDays += month[i];
				if (i == 1 && isLeapYear(curYear)) // Учли високосный ферваль
					livedDays++;
			}

			livedDays += curDay;
		}

		cout << "You already living on this planet " << livedDays <<  " days!" << endl;
	}
}
