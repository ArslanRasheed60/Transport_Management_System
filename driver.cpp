#include <iostream>
#include "service.h"
#include "driver.h"
#include "person.h";
#include <fstream>
#include <cstring>
using namespace std;


int Driver::rank_count = 0;
int Driver::service_count = 1;

Driver::Driver() :Person()
{
	dId = 0;
	LicencesList = NULL;
	noofLicences = 0;
	overallRanking = 0;
	salary = 0;
	experience = 0;
	status = 0; // 1 for free, 2 if booked and 3 if canceled
	serviceHistory = NULL;
}
//Driver(const Driver& d);

void Driver::set_dID(int d)
{
	dId = d;
}
void Driver::set_liscence_list(char* liscnce, int n)
{
	if (LicencesList == NULL)
	{
		LicencesList = new char*[n];
		for (int i = 0; i < n; i++)
		{
			LicencesList[i] = new char[(strlen(liscnce)+1)];
			strcpy(LicencesList[i], liscnce);
		}
	}
	else
	{
		char** temp = new char* [n];
		for (int i = 0; i < n-1; i++)
		{
			temp[i] = new char;
			temp[i] = LicencesList[i];
		}
		temp[n - 1] = new char[(strlen(liscnce) + 1)];
		strcpy(temp[n - 1], liscnce);

		delete[]LicencesList;
		LicencesList = new char* [n];
		for (int i = 0; i < n; i++)
		{
			LicencesList[i] = new char;
			LicencesList[i] = temp[i];
		}
		delete[]temp;
	}
}
void Driver::set_no_of_liscences(int n)
{
	noofLicences = n;
}
void Driver::set_over_all_ranking(float rank)
{
	overallRanking = ((overallRanking * rank_count) + rank);
	rank_count++;
	overallRanking = overallRanking / rank_count;
}
void Driver::set_salary(float sal)
{
	salary = sal;
}
void Driver::set_experience(int ex)
{
	experience = ex;
}
void Driver::set_status(int n)
{
	status = n;
}
void Driver::set_service_history(Service** ser_his)
{
	serviceHistory = ser_his;
}



int Driver::get_dID()
{
	return dId;
}
char* Driver::get_liscence_list(int n)
{
	return LicencesList[n];
}
int Driver::get_no_of_liscences()
{
	return noofLicences;
}
float Driver::get_over_all_ranking()
{
	return overallRanking;
}
float Driver::get_salary()
{
	return salary;
}
int Driver::get_experience()
{
	return experience;
}
int Driver::get_statuc()
{
	return status;
}
Service** Driver::get_service_history()
{
	return serviceHistory;
}

ofstream& operator<<(ofstream& fout, Driver& D)
{

	D.person_file_save(fout);

	fout << D.dId;
	fout << endl;
	fout << D.noofLicences;
	fout << endl;
	for (int i = 0; i < D.noofLicences; i++)
	{
		fout << D.LicencesList[i];
		fout << endl;
	}

	fout << D.overallRanking;
	fout << endl;
	fout << D.salary;
	fout << endl;
	fout << D.experience;
	fout << endl;
	fout << D.status;
	fout << endl;

	return fout;
}
ifstream& operator>>(ifstream& fin, Driver& D)
{
	D.person_file_read(fin);
	fin >> D.dId;
	
	fin >> D.noofLicences;
	D.LicencesList = new char* [D.noofLicences];
	for (int i = 0; i < D.noofLicences; i++)
	{
		char arr[20];
		fin >> arr;
		
		D.LicencesList[i] = new char[(strlen(arr) + 1)];
		strcpy(D.LicencesList[i], arr);
		//cout << "********" << D.LicencesList[i];
	}
	
	fin >> D.overallRanking;
	fin >> D.salary;
	fin >> D.experience;
	fin >> D.status;

	return fin;

}

void Driver::print_service_history()					//printing service history of driver: 
{
	for (int i = 0; i < service_count - 1; i++)
	{
		cout << serviceHistory[i][0];
	}
}

//ostream& operator<< (ostream& out, Driver& D)
//{
//
//}


Driver::~Driver()
{
	if (LicencesList != NULL)
	{
		for (int i = 0; i < noofLicences; i++)
		{
			if (LicencesList[i] != NULL)
			{
				delete[]LicencesList[i];
			}
		}
		delete[]LicencesList;
	}
	serviceHistory = NULL;
}

