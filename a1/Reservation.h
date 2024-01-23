#ifndef RESERVATION
#define RESERVATION

#include <iostream>
#include <string>
#include <cstring>
#include "Date.h"
#include "Room.h"
#include "Student.h"

using namespace std;

class Reservation
{
private:
	Date date;
	Room* room;
	Student* student;
public:
	Reservation(Student* student, Room* room, Date& date);
	~Reservation();
	Date getDate();
	Room* getRoom();
	Student* getStudent();
	bool lessThan(Reservation& res);
	bool overlaps(string r, Date& d);
	void print();
};

#endif
