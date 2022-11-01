#pragma once

#include "service.h"
#include "person.h"
#include <iostream>
#include <fstream>

class Driver: public Person
{
private:
	int dId;
	char** LicencesList;
	int noofLicences;
	float overallRanking;
	float salary;
	int experience;
	int status; // 1 for free, 2 if booked and 3 if canceled
	Service** serviceHistory;
public:
	Driver();
	//Driver(const Driver& d);

	static int rank_count;
	static int service_count;

	void set_dID(int d);
	void set_liscence_list(char* liscnce,int n);
	void set_no_of_liscences(int n);
	void set_over_all_ranking(float rank);
	void set_salary(float sal);
	void set_experience(int ex);
	void set_status(int n);
	void set_service_history(Service** ser_his);



	int get_dID();
	char* get_liscence_list(int n);
	int get_no_of_liscences();
	float get_over_all_ranking();
	float get_salary();
	int get_experience();
	int get_statuc();
	Service** get_service_history();

	void print_service_history();

	friend ofstream& operator<<(ofstream& fout, Driver& D);
	friend ifstream& operator>>(ifstream& fin, Driver& D);

	friend ostream& operator<< (ostream& out, Driver& D);

	~Driver();
	
};