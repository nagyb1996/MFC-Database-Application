#pragma once

#include "Person.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class WIT_Staff : public Person
{
	friend istream& operator>> (istream&, WIT_Staff&);
	friend ifstream& operator>> (ifstream&, WIT_Staff&);


private:


public:
	string getWage(void);
	void setWage(string w);
	string getHours(void);
	void setHours(string h);  //Public because hours often change

	string hourly_wage;
	string hours_worked;

							  //Default ctor
	WIT_Staff();
	//Dtor
	virtual ~WIT_Staff();
	//Custom ctor
	WIT_Staff(string n, string addr, string w_n, string w, string h);
	//Staff Hourly
	string payMe(void) const;
	string wageOut(void) const;
	string hoursOut(void) const;
};

