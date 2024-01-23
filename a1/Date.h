
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

static int maxd = 3;

class Date {

public:
	//constructor
	Date();
	Date(int year, int month, int day, int hour, int duration);

	//setters
	void setDay(int d);
	void setMonth(int d);
	void setYear(int);
	void setDate(int year, int month, int day, int hour, int duration);
	void setDate(Date& d);
	void setHour(int hour);
	void setDuration(int duration);

	//getters
	int getDay();
	int getMonth();
	int getYear();
	const string& getMonthName();

	//other
	bool lessThan(Date& d);
	bool overlaps(Date& d);
	void print();

private:
	//functions
	int getMaxDay();


	//variables
	int day;
	int month;
	int year;
	int hour;
	int duration;

	const string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	const string smonths[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec" };

};
#endif
