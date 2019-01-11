#include "stdafx.h"
#include <iostream>
#include <string>
#include "WIT_Faculty.h"
#include <fstream>
#include <limits>

using namespace std;

using namespace std;

//Getters
string WIT_Faculty::getSalary()
{
	return salary;
}

string WIT_Faculty::getSalaryPeriods()
{
	return salary_periods;
}

//Setters
void WIT_Faculty::setSalary(string s)
{
	salary = s;
}

void WIT_Faculty::setSalaryPeriods(string sp)
{
	salary_periods = sp;
}

//Default
WIT_Faculty::WIT_Faculty()
{
	name = string();
	address = string();
	w_num = string();
	role = "Faculty";
	salary = string();
	salary_periods = string();
}

//Destructor
WIT_Faculty::~WIT_Faculty()
{
}

//Custom Constructor
WIT_Faculty::WIT_Faculty(string n, string addr, string w_n, string s, string sp)
{
	name = n;
	address = addr;
	w_num = w_n;
	role = "Faculty";
	salary = s;
	salary_periods = sp;
}

string WIT_Faculty::payMe() const
{
	float pay = 0;
	float wage = stoi(salary, nullptr, 10);
	float hours = stoi(salary_periods, nullptr, 10);
	float dhours = (hours / 12);
	pay = (wage * dhours);
	return to_string(pay);
}


string WIT_Faculty::wageOut() const
{
	return salary;
}

string WIT_Faculty::hoursOut() const
{
	return salary_periods;
}

//Overload >> to read data to set person values
istream& operator>> (istream& strm, WIT_Faculty& obj)
{
	cout << "Enter Name:" << "\n";
	getline(strm, obj.name);
	cout << "Enter Address:" << "\n";
	getline(strm, obj.address);
	cout << "Enter W-Number:" << "\n";
	getline(strm, obj.w_num);
	cout << "Enter Salary:" << "\n";
	getline(strm, obj.salary);
	cout << "Enter Periods Worked:" << "\n";
	getline(strm, obj.salary_periods);
	return strm;
}

//Overload >> to read from .txt and create people
ifstream& operator>> (ifstream& strm, WIT_Faculty& obj)
{
	getline(strm, obj.name);
	getline(strm, obj.address);
	getline(strm, obj.w_num);
	getline(strm, obj.salary);
	getline(strm, obj.salary_periods);
	return strm;
}