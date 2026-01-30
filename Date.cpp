#include <iostream>
#include <iomanip>
#include <ctime>

#include "Date.h"

Date::Date(int day_, int month_, int year_)
	: day{ day_ }, month{ month_ }, year{ year_ } {
	// checkDate(*this);	// check days, months
	// ...
	if (!checkDate(*this)) {
		std::cout << "Invalid data, default to 1.1.2000" << std::endl;
		day = 1; month = 1; year = 2000;
	}
}

int Date::checkDaysInYear() const{
	bool isLeap = (this->year % 400 == 0) ||
					(this->year % 4 == 0 && this->year % 100 != 0);
	return  isLeap ? 366 : 365;
}

int Date::checkDaysInMonth() const {
	bool isLeap = (this->year % 400 == 0) ||
					(this->year % 4 == 0 && this->year % 100 != 0);
	if (this->month == 2 && isLeap) {
		return 29;
	}
	return m_days[this->month - 1];
}

void Date::setDate() {
	// cin ...
	// check days, months
	// ...
	std::cout << "Day> Month> Year> ";
	std::cin >> day; std::cin.ignore(1); std::cin >> month; std::cin.ignore(1); std::cin >> year;

	if (!checkDate(*this)) {
		std::cout << "Invalid date! Setting to default (01.01.2000)" << std::endl;
		day = 1;
		month = 1;
		year = 2000;
	}
}

int Date::toDays() const {
	int totalDays{0};

	for (int y = 1; y < year; y++) {
		bool isLeap = (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
		totalDays += isLeap ? 366 : 365;
	}

	for (int m = 1; m < month; m++) {
		totalDays += m_days[m - 1];
		if (m == 2) {
			bool isLeap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
			if (isLeap) totalDays++;
		}
	}

	totalDays += day;

	return totalDays;
}

int Date::operator-(const Date& date2) const {
	int days{0};
	// 365.2425

	int days1 = toDays();
	int days2 = date2.toDays();

	days = days1 - days2;
	return days;
}

Date Date::operator-(const int days) const {
    Date result = *this;
    int newDays = days;

	while (newDays >= 365) {
		result.year--;
		int daysInYear = result.checkDaysInYear();

		if (newDays >= daysInYear) {
			newDays -= daysInYear;
		} else {
			result.year++;
			break;
		}
	}

    while (newDays >= 28) {
    	int daysInMonth = result.checkDaysInMonth();
		result.month--;

		if (result.month < 1) {
			result.month = 12;
			result.year--;
		}

        if (newDays >= daysInMonth) {
           newDays -= daysInMonth;
        }  else {
           result.month++;
           if (result.month > 12) {
              result.month = 1;
              result.year++;
           }
           break;
       }
    }

    result.day -= newDays;
	int daysInMonth = result.checkDaysInMonth();
    if (result.day < 1) {
        result.month--;

        if (result.month < 1) {
           result.month = 12;
           result.year--;
        }

        result.day += daysInMonth;
    }

    return result;
}

Date Date::operator+(const int days) const {
	Date result = *this;
	int newDays = days;

	while (newDays >= 365) {
		result.year--;
		int daysInYear = result.checkDaysInYear();

		if (newDays >= daysInYear) {
			newDays -= daysInYear;
		} else {
			result.year++;
			break;
		}
	}

	while (newDays >= 28) {
		int daysInMonth = result.checkDaysInMonth();

		if (newDays >= daysInMonth) {
			result.month++;
			newDays -= daysInMonth;

			if (result.month > 12) {
				result.month = 1;
				result.year++;
			}
		} else {
			break;
		}
	}

	result.day += newDays;

	int daysInMonth = result.checkDaysInMonth();

	if (result.day > daysInMonth) {
		result.day -= daysInMonth;
		result.month++;

		if (result.month > 12) {
			result.month = 1;
			result.year++;
		}
	}

	return result;
}

Date operator+(const int days, const Date& date2) { return  date2 + days; }

void displayDate(Date date) {
	std::cout << std::setfill('0') << std::setw(2) << date.day << "."
			  << std::setw(2) << date.month << "."
			  << date.year << std::endl;
}

// friend cin, cout ...
std::ostream& operator<<(std::ostream& os, const Date& date) {
	os << std::setfill('0') << std::setw(2) << date.day << "."
	   << std::setw(2) << date.month << "."
	   << date.year;
	return os;
}

std::istream& operator>>(std::istream& is, Date& date) {
	char delimiter;
	is >> date.day >> delimiter >> date.month >> delimiter >> date.year;

	if (!date.checkDate(date)) {
		is.setstate(std::ios::failbit);
	}
	return is;
}

bool Date::checkDate(Date d) {
	bool isLeap = (d.year % 400 == 0) || (d.year % 4 == 0 && d.year % 100 != 0);

	if (d.month < 1 || d.month > 12)
		return false;

	if (isLeap && d.month == 2 && (d.day < 1 || d.day > 29))
			return false;

	if (d.day < 1 || d.day > m_days[d.month-1])
		return false;

	return true;
}

// ...
