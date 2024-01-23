#include "Room.h"

Room::Room(string name, int capacity, int computers, bool whiteborad)
{
	this->name = name;
	this->capacity = capacity;
	this->computers = computers;
	this->whiteborad = whiteborad;
}

Room::Room(const Room& room)
{
	this->name = room.name;
	this->capacity = room.capacity;
	this->computers = room.computers;
	this->whiteborad = room.whiteborad;
}

string Room::getName()
{
	return this->name;
}

int Room::getCapacity()
{
	return this->capacity;
}

int Room::getComputers()
{
	return this->computers;
}

bool Room::hasWhiteboard()
{
	return this->whiteborad;
}

bool Room::meetsCriteria(int capacity, int computers, bool whiteboard)
{
	if (capacity > this->capacity || computers > this->computers || this->whiteborad)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Room::lessThan(Room& r)
{
	if (strcmp(this->name.c_str(), r.name.c_str()))
	{
		return true;
	}
	return false;
}

void Room::print()
{
	cout << this->getName() << "\t" << this->getCapacity() << "\t" << this->getComputers() << "\t" << this->hasWhiteboard() << endl;
}
