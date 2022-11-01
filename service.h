#pragma once

#include "date.h"
#include "mtime.h";
#include <iostream>
#include <fstream>
using namespace std;

class Service
{
	char* source;
	char* destination;
	float distance;	//in km
	Date booking_Date;
	mTime booking_Time;
	bool status; //false for pending true for complete
	float fuel_rate;

	int cID;	//customer id
	int dID;	//driver id
	int vID;	//vehicle id
public:
		//constructors
	Service();
	Service(char* sorce, char* destin, float dist, int dy, int mnth, int yer, int sec, int min, int hr, bool stat,
		float fuelrat, int c_id, int d_id, int v_id);
	Service(Service& s);


	//setters
	void set_source(char* sorce);
	void set_destination(char* destin);
	void set_distance(float dist);
	void set_booking_date(int dy, int mnth, int yer);
	void set_booking_time(int sec, int min, int hr);
	void set_status(bool stat);
	void set_fuel_rate(float fuelrat);
	void set_c_id(int c_id);
	void set_d_id(int d_id);
	void set_v_id(int v_id);

	//getters

	char* get_source();
	char* get_destination();
	float get_distance();
	Date get_date();
	mTime get_time();
	bool get_status();
	float get_fuel_rate();
	int get_c_id();
	int get_d_id();
	int get_v_id();


	friend ofstream& operator<<(ofstream& fout, Service& s);
	friend ifstream& operator>>(ifstream& fin, Service& s);
	friend ostream& operator<<(ostream& out, Service& s);

	//destructor
	~Service();
};
