#include "mtime.h";
#include <iostream>
#include <fstream>

using namespace std;

mTime::mTime()						//default constrcutor
{
	hour = 0;
	min = 0;
	sec = 0;
}
mTime::mTime(int h, int m, int s)		//parametized constructor
{
	hour = h;
	min = m;
	sec = s;
}
mTime::mTime(const mTime& t)			//copy constructor
{
	hour = t.hour;
	min = t.min;
	sec = t.sec;
}

//setters
void mTime::set_hour(int h)
{
	hour = h;
}
void mTime::set_min(int m)
{
	min = m;
}
void mTime::set_sec(int s)
{
	sec = s;
}

//getters
int mTime::get_hour()
{
	return hour;
}
int mTime::get_min()
{
	return min;
}
int mTime::get_sec()
{
	return sec;
}

ostream& operator<<(ostream& out, const mTime& t)
{
	out <<  "Time: " << t.hour << " : " << t.min << " : " << t.sec;
	return out;
}


ofstream& operator<<(ofstream& fout, mTime& t)
{
	fout << t.hour;
	fout << endl;
	fout << t.min;
	fout << endl;
	fout << t.sec;
	fout << endl;

	return fout;
}

ifstream& operator>>(ifstream& fin, mTime& t)
{
	fin >> t.hour;
	fin >> t.min;
	fin >> t.sec;
	return fin;
}