#ifndef STUDENT
#define STUDENT

#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string name;
	string number;
public:
	Student();
	Student(string name, string number);
	Student(const Student& student);
	string getName();
	string getNumber();
	void setName(string name);
	void setNumber(string number);
	bool lessThan(Student& s);
	void print();
};
#endif
