#include"Aircraft.h"

string Aircraft::getRegistration() const {
	return registration;
}

Aircraft::Aircraft(const string& type, const string& registration) {
	this->type = type;
	this->registration = registration;
	flighthours = 0;
}

Aircraft::~Aircraft() {

}

void Aircraft::install(Part* part, Date& date) {
	part->install(date);
	parts.add(part);
}

void Aircraft::takeFlight(int hours) {
	flighthours += hours;
	for (int i = 0; i < parts.getSize(); i++)
		parts.get(i)->addFlightHours(hours);
}

Array<Part*> Aircraft::inspectionReport(Date& date) {
	Array<Part*> out;
	for (int i = 0; i < parts.getSize(); i++)
		if (parts.get(i)->inspection(date))
			out.add(parts.get(i));
	return out;
}

string Aircraft::getType()const {
	return type;
}

ostream& operator<<(ostream& os, Aircraft& aircraft) {
	os<<"Aircraft:      " << aircraft.getType()  << endl;
	os << "Registration:  " << aircraft.getRegistration() << endl;
	return os;
}