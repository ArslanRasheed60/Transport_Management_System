#pragma once

#include <iostream>
#include <fstream>
using namespace std;

class mTime
{
	int hour;
	int min;
	int sec;
public:
	//constructors
	mTime();
	mTime(int h, int m, int s);
	mTime(const mTime& t);

	//setters
	void set_hour(int h);
	void set_min(int m);
	void set_sec(int s);

	//getters
	int get_hour();
	int get_min();
	int get_sec();

	friend ostream& operator<<(ostream& out, const mTime& t);
	friend ofstream& operator<<(ofstream& fout, mTime& t);
	friend ifstream& operator>>(ifstream& fin, mTime& t);

};