#pragma once

const short m_days[12]{31,28,31,30,31,30,31,31,30,31,30,31};

class Date {
private:
	int day;
	int month;
	int year;
	int toDays() const;

public:
	Date(int day_, int month_, int year_);
	Date() : Date(1, 1, 2020) {}

	Date getDate() { return { day, month, year }; }
	void setDate();
	bool checkDate(Date d);		// check days, months
	int checkDaysInYear() const;
	int checkDaysInMonth() const;

	int operator-(const Date& date2) const;
	Date operator-(const int days) const;
	Date operator+(const int days) const;

	friend void displayDate(Date date);
	friend Date operator+(const int days, const Date& date2);
	friend std::ostream& operator<<(std::ostream& os, const Date& date);
	friend std::istream& operator>>(std::istream& is, Date& date);
};

// 4 100 400

// WET  DRY 
