
#ifndef AIRLINE_H
#define AIRLINE_H
#include "Aircraft.h"

class Airline {
private:
	string name;
	Array<Part *> parts;
	Array<Aircraft *> aircrafts;

public:
	Airline(const string &name);
	~Airline();
	Aircraft* getAircraft(const string& registration) ;
	Part* getPart(const string& name) ;
	void addAircraft(const string& type, const string& registration);
	void addPart(const string& part, int fh_inspect, int it_inspect);
	void takeFlight(const string& reg, int hours);
	void printAircraft();
	void printParts();
	void inspectionReport(const string& reg, Date& date);
	bool install(const string& registration, const string& name, Date& date);


};





#endif