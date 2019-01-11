#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Person.h"

class WIT_Faculty : public Person
{
	friend istream& operator>> (istream&, WIT_Faculty&);
	friend ifstream& operator>> (ifstream&, WIT_Faculty&);


private:


public:
	string getSalary(void);
	void setSalary(string s);
	string getSalaryPeriods(void);
	void setSalaryPeriods(string sp);

	string salary; //salary 
	string salary_periods;

	//Default ctor
	WIT_Faculty();
	//Dtor
	virtual ~WIT_Faculty();
	//Custom ctor
	WIT_Faculty(string n, string addr, string w_n, string s, string sp);
	//Staff Hourly

	string payMe(void) const;
	string wageOut(void) const;
	string hoursOut(void) const;
};
