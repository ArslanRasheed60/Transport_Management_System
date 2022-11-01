#pragma once

#include "date.h"
#include "service.h"
#include "feature.h"
#include <iostream>
using namespace std;

class Vehicle
{
	int vid;
	int registration_no;
	float avg_Mileage;
	char* Licence_type;				//liscene required for driving the vehicle
	bool status;				//false for free, true if booked in a service already;
	char* fuel_type;
	float over_all_ranking;
	Date manufacturing_date;
	Feature* flist;
	Service** service_history;
	//Add services address in the array for tracking complete information of service.

public:
	static int service_size;
				//constructors
	
	Vehicle();
	Vehicle(int vid, int reg_no, float avg_milge, char* liscence, bool stat, char* fueltyp, float v_rank,
		int dy, int mnth, int yer, int fid, char* descrip, float cost, char* sorce, char* destin, float dist,
		int b_dy, int b_mnth, int b_yer, int hor, int min, int sec,bool ser_stat, float fuelrat, int cId, int dId);
	Vehicle(Vehicle& v);

			//setters
	void set_vID(int vid);
	void set_registration_no(int reg_no);
	void set_average_mileage(float avg_mileage);
	void set_liscence_type(char* liscence);
	void set_status(bool stat);
	void set_fuel_type(char* fueltype);
	void set_vehicle_rank(float v_rank);
	void set_manufacturing_date(int dy, int mnth, int yer);
	void set_flist(int fid, char* descrip, float cost);
	void set_service_history(char* sorce, char* destin, float dist,
		int b_dy, int b_mnth, int b_yer, int hor, int min, int sec, bool ser_stat, float fuelrat, int cId, int dId, int vId);

		//getters
	int get_vID();
	int get_registration_no();
	float get_average_mileage();
	char* get_liscence_type();
	bool get_status();
	char* get_fuel_type();
	float get_vehicle_rank();
	Date get_manufacturing_date();
	Feature get_feature_list();
	Service** get_service_history();

	friend ostream& operator<< (ostream& out, Vehicle& v);

	~Vehicle();

};