#include <iostream>
#include <map>
#include <string>

using namespace std;

enum Month {
	JAN = 1, FEB = 2, MAR = 3, APR = 4, MAY = 5, JUN = 6, JUL = 7, AUG = 8, SEP = 9, OCT = 10, NOV = 11, DEC = 12
};

enum Weekday {
	MON = 0, TUE = 1, WED = 2, THI = 3, FRI = 4, SAT = 5, SUN = 6
};

int main() {
	map<Month, int> daysSinceNY;
	map<Month, int> monthCapacity;
	string weekdayNames[7];

	weekdayNames[0] = "Sunday";
	weekdayNames[1] = "Monday";
	weekdayNames[2] = "Tuesday";
	weekdayNames[3] = "Wednesday";
	weekdayNames[4] = "Thursday";
	weekdayNames[5] = "Friday";
	weekdayNames[6] = "Saturday";

	daysSinceNY[JAN] = 0;
	daysSinceNY[FEB] = 31;
	daysSinceNY[MAR] = 59;
	daysSinceNY[APR] = 90;
	daysSinceNY[MAY] = 120;
	daysSinceNY[JUN] = 151;
	daysSinceNY[JUL] = 181;
	daysSinceNY[AUG] = 212;
	daysSinceNY[SEP] = 243;
	daysSinceNY[OCT] = 273;
	daysSinceNY[NOV] = 304;
	daysSinceNY[DEC] = 334;

	monthCapacity[JAN] = 31;
	monthCapacity[FEB] = 28;
	monthCapacity[MAR] = 31;
	monthCapacity[APR] = 30;
	monthCapacity[MAY] = 31;
	monthCapacity[JUN] = 30;
	monthCapacity[JUL] = 31;
	monthCapacity[AUG] = 31;
	monthCapacity[SEP] = 30;
	monthCapacity[OCT] = 31;
	monthCapacity[NOV] = 30;
	monthCapacity[DEC] = 31;

	cout << "Enter the date in three steps like, 2002 07 10\n";
	int year;
	do {
		cout << "Enter the year: ";
		cin >> year;
	} while (year < 1);

	bool isHigher = year % 4 == 0 && year % 100 != 0 && year % 400 == 0;

	int temp1;
	do {
		cout << "Enter the month number: ";
		cin >> temp1;
	} while (temp1 > 12 || temp1 < 1);

	Month month = Month(temp1);

	int date;
	int temp2;
	if (month == FEB && isHigher) {
		temp2 = 29;
	} else {
		temp2 = monthCapacity[month];
	}
	do {
		cout << "Enter the day: ";
		cin >> date;
	} while (date > temp2 || date < 1);

	cout << date << " " << month << " " << year << "\n";

	int result = date + daysSinceNY[month] + (year - 1) * 365;
	int additional = (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
	if (isHigher && daysSinceNY[month] + date > 59) {
		additional += 1;
	}
	result += additional;
	cout << weekdayNames[Weekday(result % 7)];
	cin.get();
}
