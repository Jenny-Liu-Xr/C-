
#ifndef LIBRARY
#define LIBRARY

#include <string>
#include <iostream>
#include "Reservation.h"
#include "Room.h"
#include "Student.h"

using namespace std;

class Library
{
private:
	Student** student;
	Room** room;
	Reservation** reservation;
public:
	Library();
	~Library();
	bool addStudent(const string& name, const string& number);
	bool addRoom(string name, int capacity, int computers, bool whiteborad);
	bool addRoom(string name, int capacity, int computers);
	bool addRoom(string name, int capacity);
	bool addRoom(string name);
	bool getStudent(const string& name, Student** student);
	bool getRoom(const string& roomName, Room** room);
	bool isFree(const string& room, Date& d);
	bool makeReservation(const string& student, const string& room, Date& d);
	void printReservations();
};
#endif