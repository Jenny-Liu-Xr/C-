
#ifndef PART_H
#define PART_H

#include<iostream>
#include"Date.h"
#include<string>

using namespace std;

class Part {
private:
	string name;
	Date installationDate;
	int flighthours;
public:
	string getName() const;
	int getFlighthours() const;
	Date getIsntallationDate() const;
	Part(const string& name);
	~Part();
	void addFlightHours(int);
	void install(Date&);
	friend ostream& operator<<(ostream& os, Part& part);
	virtual bool inspection(Date&) = 0;
};

class FH_Part :virtual public Part {
private:
	int fh_inspect;
public:
	FH_Part(const string& name, int fh_inspect);
	friend ostream& operator<<(ostream& os, FH_Part& fh_part);
	int getFh_inspect()const;
	~FH_Part();
	virtual bool inspection(Date&);
};

class IT_Part :virtual public Part {
private:
	int it_inspect;
public:
	IT_Part(const string& name, int it_inspect);
	int getIt_inspect()const;
	friend ostream& operator<<(ostream& os, IT_Part& it_part);
	~IT_Part();
	virtual bool inspection(Date&);
};

class FHIT_Part :public FH_Part, public IT_Part {
public:
	FHIT_Part(const string& name,int fh_inspect, int it_inspect);
	friend ostream& operator<<(ostream& os, FHIT_Part& fhit_part);
	~FHIT_Part();
	bool inspection(Date&);
};


#endif
