#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Person.h"

using namespace std;

class WIT_Student : public Person
{

	friend istream& operator>> (istream&, WIT_Student&);
	friend ifstream& operator>> (ifstream&, WIT_Student&);


private:


public:
	string getWage(void);
	string getHours(void);
	void setHours(string h);  //Public because hours often change
	void setWage(string w);

	string hourly_wage;
	string hours_worked;


	//Default ctor
	WIT_Student();
	//Dtor
	virtual ~WIT_Student();
	//Custom ctor
	WIT_Student(string n, string addr, string w_n, string w, string h);
	//Student Hourly
	string payMe(void) const;
	string getRole(void) const;
	string wageOut(void) const;
	string hoursOut(void) const;
};
