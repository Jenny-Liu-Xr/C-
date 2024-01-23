#include "Student.h"

Student::Student()
{

}

Student::Student(string name, string number)
{
	this->name = name;
	this->name = number;
}

Student::Student(const Student& student)
{
	this->name = student.name;
	this->number = student.number;
}

string Student::getName()
{
	return this->name;
}

string Student::getNumber()
{
	return this->number;
}

void Student::setName(string name)
{
	this->name = name;
}

void Student::setNumber(string number)
{
	this->number = number;
}

bool Student::lessThan(Student& s)
{
	if (strcmp(this->number.c_str(), s.number.c_str()))
	{
		return true;
	}
	return false;
}

void Student::print()
{
	cout << this->getNumber() << "\t" << this->getNumber() << endl;
}
