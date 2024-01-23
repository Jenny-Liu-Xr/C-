
#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include"Part.h"
#include"Array.h"

class Aircraft {
private:
	string type;
	string registration;
	int flighthours;
	Array<Part *> parts;

public:
	string getRegistration() const;
	Aircraft(const string& type, const string& registration);
	~Aircraft();
	string getType()const;
	void install(Part*, Date&);
	void takeFlight(int hours);
	Array<Part*> inspectionReport(Date&);
	friend ostream& operator<<(ostream& os,Aircraft& aircraft);
};


#endif

