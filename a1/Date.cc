
#include "Date.h"

Date::Date() {
	setDate(1, 1, 1901, 0, 0);
}

Date::Date(int year, int month, int day, int hour, int duration) {
	setDate(year, month, day, hour, duration);
}


//setters
void Date::setDay(int d) {
	int max = getMaxDay();
	if (d > max) d = max;
	if (d < 1) d = 1;
	day = d;
}

void Date::setMonth(int m) {
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

void Date::setYear(int y) {
	if (y < 1901) y = 1901;
	year = y;
}

void Date::setDate(int year, int month, int day, int hour, int duration) {
	setMonth(month);
	setDay(day);
	setYear(year);
	setHour(hour);
	setDuration(duration);
}

void Date::setDate(Date& d) {
	setDate(d.year, d.month, d.day, d.hour, d.duration);
}

void Date::setHour(int hour)
{
	this->hour = hour % 24;
	this->day = getDay() + hour / 24;
}

void Date::setDuration(int duration)
{
	if (duration < 0)
	{
		this->duration = 0;
	}
	else if (duration > maxd)
	{
		this->duration = maxd;
	}
	else
	{
		this->duration = duration;
	}
}


//getters
int Date::getDay() { return day; }
int Date::getMonth() { return month; }
int Date::getYear() { return year; }
const string& Date::getMonthName() { return months[month - 1]; }


//other

bool Date::lessThan(Date& d) {
	if (year == d.year) {
		if (month == d.month) {
			if (day == d.day) {
				return hour < d.hour;
			}
			else {
				return day < d.day;
			}
		}
		else {
			return month < d.month;
		}
	}
	else {
		return year < d.year;
	}
}

bool Date::overlaps(Date& d)
{
	if (year == d.year && month == d.month) {
		if (day == d.day) {
			if (hour < d.hour) {
				if (hour + duration > d.hour)
					return true;
			}
			else {
				if (d.hour + d.duration > hour)
					return true;
			}
		}
		return false;
	}

	return false;
}

void Date::print() {
	cout << getMonthName() << " " << getDay() << ", " << getYear() << endl;
}

int Date::getMaxDay() {
	switch (getMonth()) {
	case 4:
	case 6:
	case 9:
	case 11: 			return 30;
	case 2:				return 28;
	default:			return 31;
	}
}

