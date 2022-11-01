#pragma once

#include "person.h";
#include "service.h";
#include <fstream>
#include <iostream>
using namespace std;

class Customer : public Person
{
	int cID;
	Service** bookingHistory;	//maintain and update history of a customer on each service
	
public:
	static int service_count;
				//customers 
	Customer();
	//Customer(int id, Service** book_history);
	//Customer(Customer& c);

					//setters
	void set_cId(int id);
	void set_booking_History(char* sorce, char* destin, float dist,
		int b_dy, int b_mnth, int b_yer, int hor, int min, int sec, bool ser_stat, float fuelrat, int cId, int dId, int vId);

					//getters
	int get_cID();
	void print_booking_history(Customer& c);

	friend ofstream& operator<<(ofstream& fout, Customer& c);
	friend ifstream& operator>>(ifstream& fin, Customer& c);

	~Customer();

};

