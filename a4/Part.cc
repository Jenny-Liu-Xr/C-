#include "Part.h"

string Part::getName() const {
	return name;
}

Part::Part(const string& name) {
	this->name = name;
	flighthours = 0;
}

Part::~Part() {

}

int Part::getFlighthours() const {
	return flighthours;
}

void Part::addFlightHours(int hours)  {
	flighthours += hours;
}

void Part::install(Date& isntallationDate) {
	this ->installationDate = isntallationDate;
}

Date Part::getIsntallationDate() const {
	return installationDate;
}

ostream& operator<<(ostream& os, Part& part) {
	os << "Part:              " << part.getName() << endl;
	os << "Flight hours:      " <<  part.getFlighthours() << endl;
	os << "Installation Date: " << part.getIsntallationDate().getMonthName() << " " << part.getIsntallationDate().getDay() << ", " << part.getIsntallationDate().getYear() << endl << endl;
	//os << "Inspect every:     " << part.getFh_inspect() << endl;
	return os;
}


ostream& operator<<(ostream& os, FH_Part& fh_part) {
	os << "Part:              " << fh_part.getName() << endl;
	os << "Flight hours:      " << fh_part.getFlighthours() << endl;
	os << "Installation Date: " << fh_part.getIsntallationDate().getMonthName() << " " << fh_part.getIsntallationDate().getDay() << ", " << fh_part.getIsntallationDate().getYear() << endl;
	os << "Inspect every:     " << fh_part.getFh_inspect()<<" flight hours"<< endl << endl;
	return os;
}

ostream& operator<<(ostream& os, IT_Part& it_part) {
	os << "Part:              " << it_part.getName() << endl;
	os << "Flight hours:      " << it_part.getFlighthours() << endl;
	os << "Installation Date: " << it_part.getIsntallationDate().getMonthName() << " " << it_part.getIsntallationDate().getDay() << ", " << it_part.getIsntallationDate().getYear() << endl;
	os << "Inspect every:     " << it_part.getIt_inspect() << " days installed" << endl<<endl;
	return os;
}

ostream& operator<<(ostream& os, FHIT_Part& fhit_part) {
	os << "Part:              " << fhit_part.getName() << endl;
	os << "Flight hours:      " << fhit_part.getFlighthours() << endl;
	os << "Installation Date: " << fhit_part.getIsntallationDate().getMonthName() << " " << fhit_part.getIsntallationDate().getDay() << ", " << fhit_part.getIsntallationDate().getYear() << endl;
	os << "Inspect every:     " << fhit_part.getFh_inspect() << " flight hours" << endl;
	os << "Inspect every:     " << fhit_part.getIt_inspect() << " days installed" << endl << endl;
	return os;
}


FH_Part::FH_Part(const string& name, int fh_inspect):Part(name) {
	this->fh_inspect = fh_inspect;
}

FH_Part::~FH_Part() {

}

int FH_Part::getFh_inspect()const {
	return fh_inspect;
}

bool FH_Part::inspection(Date& date) {
	if (getFlighthours() >= fh_inspect)
		return 1;
	return 0;
}

IT_Part::IT_Part(const string& name, int it_inspect) :Part(name) {
	this->it_inspect = it_inspect;
}

IT_Part::~IT_Part() {

}

bool IT_Part::inspection(Date& date) {
	if (date.toDays()- getIsntallationDate().toDays() >= it_inspect)
		return 1;
	return 0;
}

int  IT_Part::getIt_inspect()const {
	return it_inspect;
}

FHIT_Part::FHIT_Part(const string& name, int fh_inspect, int it_inspect):FH_Part(name,fh_inspect),IT_Part(name,it_inspect),Part(name){

}

FHIT_Part::~FHIT_Part() {

}

bool FHIT_Part::inspection(Date& date) {
	if (IT_Part::inspection(date) || FH_Part::inspection(date))
		return 1;
	else
		return 0;
}