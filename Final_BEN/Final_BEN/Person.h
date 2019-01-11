#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <stdlib.h>


using namespace std;

 class Person
{
private:
	//Copy ctor     person d(b) 
	Person(const Person &obj);
	//Assignment  b=c
	Person& operator= (const Person &obj);

	//Mutators now private
	void setName(string n);
	void setAddr(string a);
	void setWnumber(string w);

protected:
	friend ostream& operator<< (ostream&, const Person&);
	friend istream& operator>> (istream&, Person&);
	friend ifstream& operator>> (ifstream&, Person&);
	friend ofstream& operator<< (ofstream&, const Person&);

	string name;
	string address;
	string w_num;
	string role;


public:
	virtual string payMe(void) const = 0;
	virtual string wageOut(void) const = 0;
	virtual string hoursOut(void) const = 0;


	string getName(void);
	string getAddress(void);
	string getW_num(void);
	string get_Role(){ return role; }


	//Default ctor
	Person();
	//Dtor
	virtual ~Person();
	//Print Function
	//printPerson(void);
	//Custom ctor
	Person(string n, string addr, string w_n);

 };
