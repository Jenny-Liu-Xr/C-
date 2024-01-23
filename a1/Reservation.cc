#include "Reservation.h"

Reservation::Reservation(Student* student, Room* room, Date& date)
{
	this->student = student;
	this->room = room;
	this->date.setDay(date.getDay());
	this->date.setMonth(date.getMonth());
	this->date.setYear(date.getYear());
}

Reservation::~Reservation()
{

}

Date Reservation::getDate()
{
	return this->date;
}

Room* Reservation::getRoom()
{
	return this->room;
}

Student* Reservation::getStudent()
{
	return this->student;
}

bool Reservation::lessThan(Reservation& res)
{
	if (this->date.lessThan(res.date)) {
		return true;
	}
	return false;
}

bool Reservation::overlaps(string r, Date& d)
{
	if (this->date.overlaps(d) && strcmp(this->room->getName().c_str(), r.c_str()) == 0) {
		return true;
	}
	return false;
}

void Reservation::print()
{
	cout << "student" << endl;
	this->student->print();
	cout << "date" << endl;
	this->date.print();
	cout << "room" << endl;
	this->room->print();
}
