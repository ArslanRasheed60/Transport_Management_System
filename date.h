#pragma once

#include <iostream>
#include <fstream>
using namespace std;

class Date
{
	int day;
	int month;
	int year;
public:
	Date();								//constructors
	Date(int d, int m, int y);
	Date(const Date& d);
										//setters
	void set_day(int d);
	void set_month(int m);
	void set_year(int y);
										//getters
	int get_day();
	int get_month();
	int get_year();

	friend ostream& operator << (ostream& out, const Date& d);
	friend ofstream& operator << (ofstream& fout, Date& d);
	friend ifstream& operator >> (ifstream& fin, Date& d);
	bool operator == (const Date& d2);

};
