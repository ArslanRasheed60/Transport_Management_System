#include "name.h";
#include "date.h";
#include "person.h";
#include <iostream>
#include <fstream>
using namespace std;


Person::Person():pname(),DOB()
{
	age = 0;
	Nid = 0;
}
Person::Person(char* fN, char* lN, int d, int m, int y, int age, int Nid)
	: pname(fN, lN), DOB(d, m, y)
{
	this->age = age;
	this->Nid = Nid;
}
Person::Person(Person& p)
{
	pname.set_fname(p.pname.get_fname());
	pname.set_lname(p.pname.get_lname());
	DOB.set_day(p.DOB.get_day());
	DOB.set_month(p.DOB.get_month());
	DOB.set_year(p.DOB.get_year());
	this->age = p.age;
	this->Nid = p.Nid;
}

//setters
void Person::set_person_name(char* fN, char* lname)
{
	pname.set_fname(fN);
	pname.set_lname(lname);
}
void Person::set_DOB(int d, int m, int y)
{
	DOB.set_day(d);
	DOB.set_month(m);
	DOB.set_year(y);
}
void Person::set_age(int age)
{
	this->age = age;
}
void Person::set_NID(int Nid)
{
	this->Nid = Nid;
}

//getters 
Name Person::get_person_name()
{
	return pname;
}
Date Person::get_DOB()
{
	return DOB;
}
int Person::get_age()
{
	return age;
}
int Person::get_NID()
{
	return Nid;
}

ostream& operator << (ostream& out, const Person& p)
{
	out << p.pname;
	out << p.DOB;
	out << "\nAge: " << p.age << "\nNID: " << p.Nid;
	return out;
}

void Person::person_file_save(ofstream& fout)
{
	fout << pname;
	fout << DOB;
	fout << age;
	fout << endl;
	fout << Nid;
	fout << endl;
}

void Person::person_file_read(ifstream& fin)
{
	fin >> pname;
	fin >> DOB;
	fin >> age;
	fin >> Nid;

}

ofstream& operator << (ofstream& fout, Person& p)
{
	fout << p.pname;
	fout << p.DOB;
	fout << p.age;
	fout << endl;
	fout << p.Nid;
	fout << endl;
	return fout;
}
ifstream& operator >> (ifstream& fin, Person& p)
{
	fin >> p.pname;
	fin >> p.DOB;
	fin >> p.age;
	fin >> p.Nid;
	return fin;
}