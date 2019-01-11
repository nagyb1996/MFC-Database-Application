#include "stdafx.h"
#include <iostream>
#include <string>
#include "WIT_Student.h"
#include <fstream>
#include <limits>

using namespace std;

//Getters
string WIT_Student::getWage()
{
	return hourly_wage;
}

string WIT_Student::getHours()
{
	return hours_worked;
}

//Setters
void WIT_Student::setWage(string w)
{
	hourly_wage = w;
}

void WIT_Student::setHours(string h)
{
	hours_worked = h;
}

//Default
WIT_Student::WIT_Student()
{
	name = string();
	address = string();
	w_num = string();
	role = "Student";
	hourly_wage = string();
	hours_worked = string();
}

//Destructor
WIT_Student::~WIT_Student()
{
}

//Custom Constructor
WIT_Student::WIT_Student(string n, string addr, string w_n, string w, string h)
{
	name = n;
	address = addr;
	w_num = w_n;
	role = "Student";
	hourly_wage = w;
	hours_worked = h;
}

string WIT_Student::payMe() const
{
	int pay = 0;
	int wage = stoi(hourly_wage, nullptr, 10);
	int hours = stoi(hours_worked, nullptr, 10);
	pay = (wage * hours);
	return to_string(pay);
}

string WIT_Student::getRole() const
{
	return "Student";
}

string WIT_Student::wageOut() const
{
	return hourly_wage;

}

string WIT_Student::hoursOut() const
{
	return hours_worked;

}

//Overload >> to read data to set person values
istream& operator>> (istream& strm, WIT_Student& obj)
{
	cout << "Enter Name:" << "\n";
	getline(strm, obj.name);
	cout << "Enter Address:" << "\n";
	getline(strm, obj.address);
	cout << "Enter W-Number:" << "\n";
	getline(strm, obj.w_num);
	cout << "Enter Hourly Wage:" << "\n";
	getline(strm, obj.hourly_wage);
	cout << "Enter Hours Worked:" << "\n";
	getline(strm, obj.hours_worked);
	return strm;
}

//Overload >> to read from .txt and create people
ifstream& operator>> (ifstream& strm, WIT_Student& obj)
{
	getline(strm, obj.name);
	getline(strm, obj.address);
	getline(strm, obj.w_num);
	getline(strm, obj.hourly_wage);
	getline(strm, obj.hours_worked);

	return strm;
}
