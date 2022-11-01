#pragma once
#include <iostream>
#include "date.h";
#include "mtime.h";
#include "name.h";
#include "service.h";
#include "ride.h";
#include "driver.h"
#include "customer.h";
#include "person.h";
#include "vehicle.h"
#include <iostream>

using namespace std;
class TMS
{
	
	Vehicle** Ride_vehicle_list;
	char** Ride_Vehicle_type;
	Vehicle** Transport_vehicle_list;
	char** Transport_Vehicle_type;
	Customer** customer_list;
	Service** service_list;
	Driver** driver_list;
public:
	static int Ride_vehicle_size;
	static int vehicle_type_size;				//for ride vehicles

	static int transport_vehicle_size;			//for transport vehicles
	static int transport_vehicle_type_size;

	static int service_size;
	static int  temp;

	TMS();								//deafault constructor

	/// 
	static int customer_size;
	static int custom_size;
	void add_customer();
	void Print_Customer();
	void read_customer_data();
	//
	void print_history_of_customer();
	void service_complete();
	void list_of_cust_dri();
	void list_of_pending_services_date();
	void list_of_pending_services_driver();
	void list_of_canceled_services();
	/// 
	
	//
	static int driver_size;
	void add_a_driver();
	void dravers();
	void remove_a_driver();
	void print_driver();
	void read_driver_data();
	//
	void print_history_of_driver();
	void print_list_drivers_ranking();				//print of drivers according to the ranking
	void print_list_drivers_liscences();
	void print_list_drivers_salary();

	//
	void serive_request_for_customer(int cho);
	//Customer& operator[] (int i);
	/// 
	


	
		
	void set_ride_vehicle_type(char* veh);				//for ride
	char* get_ride_vehicle_type(int n);
	void add_Ride_veh_details();
	void get_ride_vehicle_ids(int arr[],int &size);
	void print_ride_vehicle_details(int n);

	void add_Transport_veh_details();					//for transport
	void set_transport_vehicle_type(char* veh);
	char* get_transport_vehicle_type(int n);
	void get_transport_vehicle_ids(int arr[], int& size);
	void print_transport_vehicle_details(int n);

	void add_Ride_Vehicle();
	void add_Transport_Vehicle();

	void remove_ride_Vehicle(int n);
	void remove_transport_vehicle(int n);
	
	

	friend ofstream& operator<<(ofstream& fout, TMS& t);
	friend ifstream& operator>>(ifstream& fin, TMS& t);
	friend ostream& operator<<(ostream& out, TMS& t);
	~TMS();
};