#include "date.h"
#include "service.h"
#include "feature.h"
#include "vehicle.h"
#include <iostream>
#include <cstring>
using namespace std;

int Vehicle::service_size = 1;

//constructors
Vehicle::Vehicle() :manufacturing_date()
{
	vid = 0;
	registration_no = 0;
	avg_Mileage = 0;
	Licence_type = NULL;				//liscene required for driving the vehicle
	status = true;				//false for free, true if booked in a service already;
	fuel_type = NULL;
	over_all_ranking = 0;
	flist = NULL;
	service_history = new Service * [service_size];
	for (int i = 0; i < service_size; i++)
	{
		service_history[i] = new Service;
	}
}
Vehicle::Vehicle(int vid, int reg_no, float avg_milge, char* liscence, bool stat, char* fueltyp, float v_rank,
	int dy, int mnth, int yer, int fid, char* descrip, float cost, char* sorce, char* destin, float dist,
	int b_dy, int b_mnth, int b_yer, int hor, int min, int sec,bool ser_stat, float fuelrat, int cId, int dId)
	:manufacturing_date(dy,mnth,yer)
{
	this->vid = vid;
	registration_no = reg_no;
	avg_Mileage = avg_milge;

	Licence_type = new char[(strlen(liscence)+1)];			//liscence tyoe
	strcpy(Licence_type, liscence);

	status = stat;	

	fuel_type = new char[(strlen(fueltyp) + 1)];			//fuel type
	strcpy(fuel_type, fueltyp);

	over_all_ranking = v_rank;

	flist = new Feature(fid,descrip,cost);				//feature pointer

	service_history = new Service*[service_size];			//service history
	for (int i = 0; i < service_size; i++)
	{
		service_history[i] = new Service(sorce, destin, dist, b_dy, b_mnth, b_yer, sec, min, hor, ser_stat, fuelrat, cId, dId, vid);
	}
}
//Vehicle::Vehicle(Vehicle& v)	//**************************************************
//{
//
//}

//setters
void Vehicle::set_vID(int vid)			//set vid;
{
	this->vid = vid;
}
void Vehicle::set_registration_no(int reg_no)		//set registration no.
{
	registration_no = reg_no;
}
void Vehicle::set_average_mileage(float avg_mileage)	//set average milage
{
	avg_Mileage = avg_mileage;
}

void Vehicle::set_liscence_type(char* liscence)			//set liscence type
{
	if (Licence_type != NULL)
	{
		delete[]Licence_type;
		Licence_type = new char[(strlen(liscence) + 1)];			//liscence tyoe
		strcpy(Licence_type, liscence);
	}
	else
	{
		Licence_type = new char[(strlen(liscence) + 1)];			//liscence tyoe
		strcpy(Licence_type, liscence);
	}
}
void Vehicle::set_status(bool stat)					//set status
{
	status = stat;
}
void Vehicle::set_fuel_type(char* fueltype)				//set fuel type
{
	if (fuel_type != NULL)
	{
		delete[]fuel_type;
		fuel_type = new char[(strlen(fueltype) + 1)];			//fuel type
		strcpy(fuel_type, fueltype);
	}
	else
	{
		fuel_type = new char[(strlen(fueltype) + 1)];			//fuel type
		strcpy(fuel_type, fueltype);
	}
}
void Vehicle::set_vehicle_rank(float v_rank)
{
	over_all_ranking = v_rank;
}
void Vehicle::set_manufacturing_date(int dy, int mnth, int yer)
{
	manufacturing_date.set_day(dy);
	manufacturing_date.set_month(mnth);
	manufacturing_date.set_year(yer);
}
void Vehicle::set_flist(int fid, char* descrip, float cost)
{
	if (flist != NULL)
	{
		flist->set_fID(fid);
		flist->set_description(descrip);
		flist->set_cost(cost);
	}
	else
	{
		flist = new Feature(fid, descrip, cost);				//feature pointer
	}
	
}
void Vehicle::set_service_history(char* sorce, char* destin, float dist,
	int b_dy, int b_mnth, int b_yer, int hor, int min, int sec, bool ser_stat, float fuelrat, int cId, int dId, int vId)
{
	int i = service_size - 1;
	service_history[i]->set_source(sorce);
	service_history[i]->set_destination(destin);
	service_history[i]->set_distance(dist);
	service_history[i]->set_booking_date(b_dy, b_mnth, b_yer);
	service_history[i]->set_booking_time(sec, min, hor);
	service_history[i]->set_status(ser_stat);
	service_history[i]->set_fuel_rate(fuelrat);
	service_history[i]->set_c_id(cId);
	service_history[i]->set_d_id(dId);
	service_history[i]->set_v_id(vId);
}

//getters
int Vehicle::get_vID()
{
	return vid;
}
int Vehicle::get_registration_no()
{
	return registration_no;
}
float Vehicle::get_average_mileage()
{
	return avg_Mileage;
}
char* Vehicle::get_liscence_type()
{
	return Licence_type;
}
bool Vehicle::get_status()
{
	return status;
}
char* Vehicle::get_fuel_type()
{
	return fuel_type;
}
float Vehicle::get_vehicle_rank()
{
	return over_all_ranking;
}
Date Vehicle::get_manufacturing_date()
{
	return manufacturing_date;
}
Feature Vehicle::get_feature_list()
{
	return *flist;
}
Service** Vehicle::get_service_history()
{
	return service_history;
}

ostream& operator<< (ostream& out, Vehicle& v)
{
	out << "\nVid: " << v.vid;
	out << "\nRegistration # " << v.registration_no;
	out << "\nAverage mileage: " << v.avg_Mileage << " Km/h";
	out << "\nLiscence Type: " << v.Licence_type;
	if (v.status == false)
	{
		out << "\nStatus:  Free ";
	}
	else
	{
		out << "\nStatuc: booked a service atomatically ";
	}
	out << "\nFuel type: " << v.fuel_type;
	out << "\nOver All ranking: " << v.over_all_ranking;
	out << "\nManufacturing Date: " << v.manufacturing_date;
	out << v.flist[0];
	for (int i = 0; i < v.service_size; i++)
	{
		out << "\n*** Service History *** Number: " << i + 1 << endl;
		out << v.service_history[i][0] ;
	}
	return out;
}

Vehicle::~Vehicle()
{
	if (Licence_type != NULL)
	{
		delete[]Licence_type;
	}
	if (fuel_type != NULL)
	{
		delete[]fuel_type;
	}
	if (flist != nullptr)
	{
		delete flist;
	}
	if (service_history != NULL)
	{
		for (int i = 0; i < service_size; i++)
		{
			delete service_history[i];
		}
		delete[]service_history;
	}
}