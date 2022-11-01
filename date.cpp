#include "date.h";
#include <iostream>
#include <fstream>
using namespace std;

Date::Date()								//default constructors
{
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int d, int m, int y)				//parametized constructor
{
	day = d;
	month = m;
	year = y;
}
Date::Date(const Date& d)					//copy constructor
{
	day = d.day;
	month = d.month;
	year = d.year;
}
//setters
void Date::set_day(int d)
{
	day = d;
}
void Date::set_month(int m)
{
	month = m;
}
void Date::set_year(int y)
{
	year = y;
}
//getters
int Date::get_day()
{
	return day;
}
int Date::get_month()
{
	return month;
}
int Date::get_year()
{
	return year;
}

ostream& operator << (ostream& out, const Date& d)
{
	out << "Date: " << d.day << " / " << d.month << " / " << d.year;
	return out;
}

ofstream& operator << (ofstream& fout, Date& d)
{
	fout << d.day;
	fout << endl;
	fout << d.month;
	fout << endl;
	fout << d.year;
	fout << endl;
	return fout;
}

ifstream& operator >> (ifstream& fin, Date& d)
{
	fin >> d.day;
	fin >> d.month;
	fin >> d.year;
	return fin;
}

