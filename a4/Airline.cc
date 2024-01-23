
#include"Airline.h"


Airline::Airline(const string& name) {
	this->name = name;
}

Airline::~Airline() {

}

Aircraft* Airline::getAircraft(const string& registration)  {
	for (int i = 0; i < aircrafts.getSize(); i++)
		if (aircrafts.get(i)->getRegistration() == registration)
			return aircrafts.get(i);
	return aircrafts.get(0);
}

Part* Airline::getPart(const string& name) {
	for (int i = 0; i < parts.getSize(); i++)
		if (parts.get(i)->getName() == name)
			return parts.get(i);
	return parts.get(0);
}

void Airline::addAircraft(const string& type, const string& registration) {
	Aircraft *aircraft = new Aircraft(type, registration);
	aircrafts.add(aircraft);
}


void Airline::addPart(const string& part, int fh_inspect, int it_inspect) {
	if (fh_inspect == 0) {
		IT_Part* it_part = new IT_Part(part, it_inspect);
		parts.add(it_part);
	}
	else if(it_inspect==0) {
		FH_Part* fh_part = new FH_Part(part, fh_inspect);
		parts.add(fh_part);
	}else {
		FHIT_Part* fhit_part = new FHIT_Part(part, fh_inspect,it_inspect);
		parts.add(fhit_part);
	}

}

void Airline::takeFlight(const string& reg, int hours) {
	for (int i = 0; i < aircrafts.getSize(); i++)
		if (aircrafts.get(i)->getRegistration() == reg)
			aircrafts.get(i)->takeFlight(hours);
}

void Airline::printAircraft() {
	for (int i = 0; i < aircrafts.getSize(); i++)
		cout<<*aircrafts.get(i);
}

void Airline::printParts() {
	for (int i = 0; i < parts.getSize(); i++) {
		FH_Part* p1 = dynamic_cast <FH_Part*>(parts.get(i));
		IT_Part* p2 = dynamic_cast <IT_Part*>(parts.get(i));
		FHIT_Part* p3 = dynamic_cast <FHIT_Part*>(parts.get(i));
		if(p3)
			cout << *p3;
		else if (p1)
			cout << *p1;
		else if (p2)
			cout << *p2;
	}
}

void Airline::inspectionReport(const string& reg, Date& date) {
	for (int i = 0; i < aircrafts.getSize(); i++)
		if (aircrafts.get(i)->getRegistration() == reg) {
			cout << "The following parts from " << aircrafts.get(i)->getRegistration() << " require inspection:" << endl;
			Array<Part*> tempparts = aircrafts.get(i)->inspectionReport(date);
			for (int j = 0; j < tempparts.getSize(); j++) {
				FH_Part* p1 = dynamic_cast <FH_Part*>(tempparts.get(j));
				IT_Part* p2 = dynamic_cast <IT_Part*>(tempparts.get(j));
				FHIT_Part* p3 = dynamic_cast <FHIT_Part*>(tempparts.get(j));
				if (p3)
					cout << *p3;
				else if (p1)
					cout << *p1;
				else if (p2)
					cout << *p2;
			}
			cout << endl << endl;
			break;
		}
}

bool Airline::install(const string& registration, const string& name, Date& date) {
	bool flag1 = false, flag2 = false;
	int i, j;
	for ( i = 0; i < aircrafts.getSize(); i++)
		if (aircrafts.get(i)->getRegistration() == registration) {
			flag1 = 1;
			break;
		}
					
	for ( j = 0; j < parts.getSize(); j++)
		if (parts.get(j)->getName() == name)
		{
			flag2 = 1;
			break;
		}

	if (flag1 && flag2) {
		aircrafts.get(i)->install(parts.get(j), date);
		return true;
	}
	return false;
}