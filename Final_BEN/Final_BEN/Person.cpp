#include "stdafx.h"
#include <iostream>
#include <string>
#include "Person.h"
#include <fstream>
#include <limits>

using namespace std;

//Getters
string Person::getName()
{
	return name;
}

string Person::getAddress()
{
	return address;
}

string Person::getW_num()
{
	return w_num;
}


//Setters

void Person::setName(string n)
{
	name = n;
}

void Person::setAddr(string a)
{
	address = a;
}

void Person::setWnumber(string w)
{
	w_num = w;
}

//
//Overload << to print person
ostream& operator<< (ostream& strm, const Person& obj)
{
	strm << "The name is: " << obj.name << endl;
	strm << "The address is: " << obj.address << endl;
	strm << "The W-Number is: " << obj.w_num << endl;
	strm << "The Role is: " << obj.role << endl;
	strm << obj.payMe() << endl;
	return strm;
}

//Overload << to write array of people to .txt file 
ofstream& operator<< (ofstream & strm, const Person& obj)
{
	strm << obj.role << endl;
	strm << obj.name << endl;
	strm << obj.address << endl;
	strm << obj.w_num << endl;
	strm << obj.wageOut() << endl;
	strm << obj.hoursOut() << endl;
	return strm;
}

//Constructors & Destructors

//Default
Person::Person()
{
	name = string();
	address = string();
	w_num = string();
	role = string();
}


//Copy Constructor
Person::Person(const Person &obj)
{
	name = obj.name;
	address = obj.address;
	w_num = obj.w_num;
	role = obj.role;
}


//Destructor
Person::~Person()
{
}

//Custom Constructor
Person::Person(string n, string addr, string w_n)
{
	name = n;
	address = addr;
	w_num = w_n;
}

