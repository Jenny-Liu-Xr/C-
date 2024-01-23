#ifndef ROOM
#define ROOM

#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Room
{
private:
	string name;
	int capacity;
	int computers;
	bool whiteborad;
public:
	Room(string name, int capacity, int computers, bool whiteborad);
	Room(const Room& room);
	string getName();
	int getCapacity();
	int getComputers();
	bool hasWhiteboard();
	bool meetsCriteria(int capacity, int computers, bool whiteboard);
	bool lessThan(Room& r);
	void print();
};

#endif
