#include "person.h";
#include "service.h";
#include "customer.h"
#include <fstream>
#include <iostream>
using namespace std;

int Customer::service_count = 1;

Customer::Customer()
{
	cID = 0;
	bookingHistory = new Service*[service_count];
	for (int i = 0; i < service_count; i++)
	{
		bookingHistory[i] = new Service;
	}
}
//Customer::Customer(int id, Service** book_history)
//{
//	cID = id;
//	bookingHistory = new Service * [Service_count];
//	for (int i = 0; i < count; i++)
//	{
//		bookingHistory[i] = new Service;
//	}
//	for (int i = 0; i < count; i++)
//	{
//		for(int )
//	}
//}
//Customer::Customer(Customer& c);

//setters
void Customer::set_cId(int id)
{
	cID = id;
}
void Customer::set_booking_History(char* sorce, char* destin, float dist,
	int b_dy, int b_mnth, int b_yer, int hor, int min, int sec, bool ser_stat, float fuelrat, int cId, int dId, int vId)
{
	int i = service_count - 1;
	bookingHistory[i]->set_source(sorce);
	bookingHistory[i]->set_destination(destin);
	bookingHistory[i]->set_distance(dist);
	bookingHistory[i]->set_booking_date(b_dy, b_mnth, b_yer);
	bookingHistory[i]->set_booking_time(sec, min, hor);
	bookingHistory[i]->set_status(ser_stat);
	bookingHistory[i]->set_fuel_rate(fuelrat);
	bookingHistory[i]->set_c_id(cId);
	bookingHistory[i]->set_d_id(dId);
	bookingHistory[i]->set_v_id(vId);
}

//getters
int Customer::get_cID()
{
	return cID;
}
void Customer::print_booking_history(Customer& c)
{
	for (int i = 0; i < service_count-1; i++)
	{
		cout << c.bookingHistory[i][0];
	}
}

ofstream& operator<<(ofstream& fout, Customer& c)
{
	fout << c.cID;											//customer filing # 2;
	fout << endl;
	fout << c.service_count;								//customer filing # 3
	fout << endl;
	c.person_file_save(fout);
	fout << endl;
	/*if (c.service_count > 1)
	{
		for (int i = 0; i < c.service_count - 1; i++)
		{
			fout << c.bookingHistory[i][0];
		}
	}
	else
		fout << 0;*/
	
	return fout;
}

ifstream& operator>>(ifstream& fin, Customer& c)
{
	fin >> c.cID;
	fin >> c.service_count;
	c.person_file_read(fin);

	
	
	
	/*for (int i = 0; i < c.service_count - 1; i++)
	{
		if (c.bookingHistory == NULL)
		{
			c.bookingHistory = new Service * [c.service_count];
			for (int j = 0; j < c.service_count; j++)
			{
				c.bookingHistory[j] = new Service;
			}
		}
		fin >> c.bookingHistory[i][0];
	}*/
	return fin;
}


Customer::~Customer()
{
	if (bookingHistory != NULL)
	{
		for (int i = 0; i < service_count; i++)
		{
			if (bookingHistory[i] != NULL)
			{
				delete bookingHistory[i];
			}
		}
		delete[]bookingHistory;
	}
	bookingHistory = NULL;
}