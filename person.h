#pragma once

#include "name.h";
#include "date.h";
#include <iostream>
#include <fstream>
using namespace std;

class Person
{
	Name pname;
	Date DOB;
	int age;
	int Nid;
public:
	//constructors 
	Person();
	Person(char*fN,char*lN,int d,int m,int y,int age,int Nid);
	Person(Person& p);

	//setters
	void set_person_name(char* fN, char* lname);
	void set_DOB(int d, int m, int y);
	void set_age(int age);
	void set_NID(int Nid);

	//getters 
	Name get_person_name();
	Date get_DOB();
	int get_age();
	int get_NID();

	void person_file_save(ofstream& fout);				//through customer
	void person_file_read(ifstream& fin);				//through customer

	//output 
	friend ostream& operator << (ostream& out, const Person& p);
	friend ofstream& operator << (ofstream& fout, Person& p);
	friend ifstream& operator >> (ifstream& fin, Person& p);
};