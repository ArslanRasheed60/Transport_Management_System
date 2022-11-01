#pragma once

#include <iostream>
#include <fstream>
using namespace std;

class Name
{
	char* fname;
	char* lname;
public:
	Name();
	Name(char* fN, char* lN);
	Name(const Name& n);
	
	void set_fname(char* fN);
	void set_lname(char* lN);

	char* get_fname();
	char* get_lname();

	friend ostream& operator<<(ostream& out, const Name& n);
	friend ofstream& operator<<(ofstream& fout, Name& n);
	friend ifstream& operator>>(ifstream& fin, Name& n);


	~Name();
};
