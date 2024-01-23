#include "Library.h"

Library::Library()
{
	this->student = new Student * [20]{ NULL };
	this->room = new Room * [20]{ NULL };
	this->reservation = new Reservation * [20]{ NULL};
}

Library::~Library()
{
	delete student;
	delete room;
	delete reservation;
}

bool Library::addStudent(const string& name, const string& number)
{
	for (int i = 0; i < 20; i++) {
		if (student[i] == NULL) {
		student[i] = new Student(name, number);
		return true;
		}
	}

	return false;
}

bool Library::addRoom(string name, int capacity, int computers, bool whiteborad)
{
	for (int i = 0; i < 20; i++) {
		if (room[i] == NULL) {
		room[i] = new Room(name, capacity, computers, whiteborad);
		return true;
		}
	}
	return false;
}

bool Library::addRoom(string name, int capacity, int computers)
{
	for (int i = 0; i < 20; i++) {
		if (room[i] == NULL) {
		room[i] = new Room(name, capacity, computers, false);
		return true;
		}
	}
	return false;
}

bool Library::addRoom(string name, int capacity)
{
	for (int i = 0; i < 20; i++) {
		if (room[i] == NULL) {
		room[i] = new Room(name, capacity, 0, false);
		return true;
		}
	}
	return false;
}

bool Library::addRoom(string name)
{
	for (int i = 0; i < 20; i++) {
		if (room[i] == NULL) {
		room[i] = new Room(name, 1, 0, false);
		return true;
		}
	}
	return false;
}

bool Library::getStudent(const string& name, Student** student)
{
	for (int i = 0; i < 20; i++) {
		if (this->student[i]->getName() == name) {
			for (int j = 0; j < 20; j++) {
				if (student[j] == NULL) {
					student[j] = this->student[i];
				}
			}

		}
	}
	return false;
}

bool Library::getRoom(const string& roomName, Room** room)
{
	for (int i = 0; i < 20; i++) {
		if (this->room[i]->getName() == roomName) {
			for (int j = 0; j < 20; j++) {
				if (room[j] == NULL) {
					room[j] = this->room[i];
				}
			}

		}
	}
	return false;
}

bool Library::isFree(const string& room, Date& d)
{
	int key = 0;
	for (int i = 0; i < 20; i++) {
		if (this->room[i] != NULL) {
			key = 1;
		}
	}

	if (key == 0) {
		return false;
	}
	else {
		for (int j = 0; j < 20; j++) {
			if (this->reservation[j]!=NULL) {
				if (this->reservation[j]->overlaps(room, d) == true) {
					return false;
				}				
			}			
		}
	}
	return true;
}

bool Library::makeReservation(const string& student, const string& room, Date& d)
{
	Student* stu = new Student(student, "");
	Room* ro = new  Room(room, 1, 0, false);
	int key = 0;
	int flag = 0;
	for (int i = 0; i < 20; i++) {
		if (this->student[i] !=NULL && this->student[i]->getName() == student) {
			stu = this->student[i];
			key = 1;
		}

		if (this->room[i] != NULL && this->room[i]->getName() == room) {
			ro = this->room[i];
			key = 1;
		}

		if(this->reservation[i]!=NULL)
		if (this->reservation[i]->overlaps(this->reservation[i]->getRoom()->getName(), d) == false) {
			flag = 0;
		}
		if (this->reservation[20] != NULL) {
			flag = 1;
		}
	}
	if (key == 0) {
		return false;
	}
	else
	{		
			Reservation* res = new Reservation(stu, ro, d);
			for (int i = 0; i < 20; i++)
			{
				if (this->reservation[i] == NULL)
				{
					this->reservation[i] = res;
					break;
				}
			}
			if (flag == 1) {
				return false;
			}
	}
	return true;
}

void Library::printReservations()
{
	for (int i = 0; i < 20; i++)
	{
		if (this->reservation[i] != NULL)
		{
			this->reservation[i]->getStudent()->print();
			cout  << "\t" << this->reservation[i]->getRoom()->getName() 
				<< "\t" << endl;
			this->reservation[i]->getDate().print();
		}
	}
}
