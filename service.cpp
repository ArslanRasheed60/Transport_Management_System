#include "mtime.h";
#include "date.h"
#include "service.h"
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

Service::Service()		//default constructor
{
	source = NULL;
	destination = NULL;
	distance = 0;
	booking_Date.set_day(0);
	booking_Date.set_month(0);
	booking_Date.set_year(0);

	booking_Time.set_hour(0);
	booking_Time.set_min(0);
	booking_Time.set_sec(0);

	status = true;							//suppose that service is completed
	fuel_rate = 0;

	cID = 0;
	dID = 0;
	vID = 0;
}
	//parametized constructor
Service::Service(char* sorce, char* destin, float dist, int dy, int mnth, int yer, int sec, int min, int hr, bool stat,
	float fuelrat, int c_id, int d_id, int v_id)
	:booking_Date(dy, mnth, yer), booking_Time(hr, min, sec)
{
	source = new char[(strlen(sorce) + 1)];				//creating and copy data of source
	strcpy(source, sorce);

	destination = new char[(strlen(destin) + 1)];		//creating and copy data of source
	strcpy(destination, destin);

	distance = dist;
	status = stat;
	fuel_rate = fuelrat;
	cID = c_id;
	dID = d_id;
	vID = v_id;
}
	//copy constructor
Service::Service(Service& s)
{
	source = new char[(strlen(s.source) + 1)];				//creating and copy data of source
	strcpy(source, s.source);

	destination = new char[(strlen(s.destination) + 1)];		//creating and copy data of source
	strcpy(destination, s.destination);

	distance = s.distance;
							// date setters
	booking_Date.set_day(s.booking_Date.get_day());
	booking_Date.set_month(s.booking_Date.get_month());
	booking_Date.set_year(s.booking_Date.get_year());
							// time setters
	booking_Time.set_hour(s.booking_Time.get_hour());
	booking_Time.set_min(s.booking_Time.get_min());
	booking_Time.set_sec(s.booking_Time.get_sec());

	status = s.status;
	fuel_rate = s.fuel_rate;
	cID = s.cID;
	dID = s.dID;
	vID = s.vID;
}

//setters
void Service::set_source(char* sorce)				//source setter
{
	if (source != NULL)
	{
		delete[]source;
		source = new char[(strlen(sorce) + 1)];				//creating and copy data of source
		strcpy(source, sorce);
	}
	else
	{
		source = new char[(strlen(sorce) + 1)];				//creating and copy data of source
		strcpy(source, sorce);
	}
}
void Service::set_destination(char* destin)			//destination setter
{
	destination = new char[(strlen(destin) + 1)];		//creating and copy data of source
	strcpy(destination, destin);
}
void Service::set_distance(float dist)				//set distance
{
	distance = dist;
}
void Service::set_booking_date(int dy, int mnth, int yer)			//set date
{
	booking_Date.set_day(dy);
	booking_Date.set_month(mnth);
	booking_Date.set_year(yer);
}
void Service::set_booking_time(int sec, int min, int hr)		//time setter
{
	booking_Time.set_sec(sec);
	booking_Time.set_min(min);
	booking_Time.set_hour(hr);
}
void Service::set_status(bool stat)				//status true(complete) or false(pending) check
{
	status = stat;
}
void Service::set_fuel_rate(float fuelrat)  //fuel rate
{
	fuel_rate = fuelrat;
}
	//customer id
void Service::set_c_id(int c_id)			
{
	cID = c_id;
}
	//driver id
void Service::set_d_id(int d_id)
{
	dID = d_id;
}
	//vehicle id
void Service::set_v_id(int v_id)
{
	vID = v_id;
}

//getters

char* Service::get_source()
{
	return source;
}
char* Service::get_destination()
{
	return destination;
}
float Service::get_distance()
{
	return distance;
}
Date Service::get_date()
{
	return booking_Date;
}
mTime Service::get_time()
{
	return booking_Time;
}
bool Service::get_status()
{
	return status;
}
float Service::get_fuel_rate()
{
	return fuel_rate;
}
int Service::get_c_id()
{
	return cID;
}
int Service::get_d_id()
{
	return dID;
}
int Service::get_v_id()
{
	return vID;
}

ostream& operator<<(ostream& out, Service& s)
{
	if (s.source != NULL)
	{
		out << "\nSource: " << s.source;
		out << "\nDestination: " << s.destination;
		out << "\nDistance: " << s.distance << " km";
		out << "\nBooking Date: " << s.booking_Date;
		out << "\nBooking Time: " << s.booking_Time;
		if (s.status == false)
		{
			out << "\nStatus:  Pending";
		}
		else
		{
			out << "\nStatus:  Complete";
		}
		out << "\nFuel Rate: " << s.fuel_rate << "  Rs";
		out << "\nCustomer ID: " << s.cID;
		out << "\nDriver ID: " << s.dID;
		out << "\nVehicle ID: " << s.vID;
	}
	else
	{
		out << "\nSorry: Currently there is no service history exists for this vehicle: ";
	}
	return out;
}

ofstream& operator<<(ofstream& fout, Service& s)
{
	if (s.source != NULL)
	{
		fout << s.source;
		fout << endl;
		fout << s.destination;
		fout << endl;
		fout << s.distance;
		fout << endl;
		fout << s.booking_Date;

		fout << s.booking_Time;

		if (s.status == false)
		{
			fout << 0;
			fout << endl;
		}
		else
		{
			fout << 1;
			fout << endl;
		}
		fout << s.fuel_rate;
		fout << endl;
		fout << s.cID;
		fout << endl;
		fout << s.dID;
		fout << endl;
		fout << s.vID;
		fout << endl;

		return fout;
	}
}

//ifstream& operator>>(ifstream& fin, Service& s)
//{
//	
//	//if (s.source == NULL)
//	//{
//	//	s.source = new char[100];
//	//	fin.get(s.source,100);
//	//	fin.ignore();
//	//	/*for (int i = 0; i < 100 && s.source[i] != '\0'; i++)
//	//	{
//
//	//	}*/
//	//}
//	//else
//	//{
//	//	fin.ignore();
//	//	fin.get(s.source, 100);
//	//	fin.ignore();
//	//}
//	/*fin.ignore();
//	s.source = new char[100];
//	fin.get(s.source,100);
//	fin.ignore();*/
//	/*for (int i = 0; i < 100 && s.source[i] != '\0'; i++)
//	{
//
//	}*/
//	if (s.destination == NULL)
//	{
//		s.destination = new char[100];
//		fin.get(s.destination, 100);
//	}
//
//	fin.ignore();
//	fin >> s.distance;
//	fin >> s.booking_Date;
//
//	fin >> s.booking_Time;
//	int n;
//	fin >> n;
//	if (n == 0)
//	{
//		s.status = false;
//	}
//	else
//	{
//		s.status = true;
//	}
//	fin >> s.fuel_rate;
//	fin >> s.cID;
//	fin >> s.dID;
//	fin >> s.vID;
//
//	return fin;
//}

//destructor
Service::~Service()
{
	if (source != NULL)
		delete[]source;

	if (destination != NULL)
		delete[]destination;
}