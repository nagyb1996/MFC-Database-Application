#include "stdafx.h"
#include <iostream>
#include <string>
#include "WIT_Staff.h"
#include <fstream>
#include <limits>

using namespace std;

//Getters
string WIT_Staff::getWage()
{
	return hourly_wage;
}

string WIT_Staff::getHours()
{
	return hours_worked;
}

//Setters
void WIT_Staff::setWage(string w)
{
	hourly_wage = w;
}

void WIT_Staff::setHours(string h)
{
	hours_worked = h;
}

//Default
WIT_Staff::WIT_Staff()
{
	name = string();
	address = string();
	w_num = string();
	role = "Staff";
	hourly_wage = string();
	hours_worked = string();
}

//Destructor
WIT_Staff::~WIT_Staff()
{
}

//Custom Constructor
WIT_Staff::WIT_Staff(string n, string addr, string w_n, string w, string h)
{
	name = n;
	address = addr;
	w_num = w_n;
	role = "Staff";
	hourly_wage = w;
	hours_worked = h;
}

string WIT_Staff::payMe() const
{
	float overtime = 0;
	float overtime_pay = 0;
	float pay = 0;

	float wage = stoi(hourly_wage);
	float hours = stoi(hours_worked);

	if (hours > 40)
	{
		overtime = (hours - 40);
		overtime_pay = (overtime * (wage * 1.5));
		pay = ((hours - overtime) * wage) + overtime_pay;
		return to_string(pay);
	}
	else
	{
		pay = (wage * hours);
		return to_string(pay);
	}
}

string WIT_Staff::wageOut() const
{
	return hourly_wage;

}

string WIT_Staff::hoursOut() const
{
	return hours_worked;

}



//Overload >> to read data to set person values
istream& operator>> (istream& strm, WIT_Staff& obj)
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
ifstream& operator>> (ifstream& strm, WIT_Staff& obj)
{
	getline(strm, obj.name);
	getline(strm, obj.address);
	getline(strm, obj.w_num);
	getline(strm, obj.hourly_wage);
	getline(strm, obj.hours_worked);

	return strm;
}