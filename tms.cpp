#include <iostream>
#include "date.h";
#include "mtime.h";
#include "name.h";
#include "service.h";
#include "ride.h";
#include "customer.h";
#include "person.h";
#include "tms.h"
#include "vehicle.h"
#include <iostream>
#include <fstream>

using namespace std;

int TMS::Ride_vehicle_size = 9;
int TMS::vehicle_type_size = 1;					//ride vehicle type size
int TMS::transport_vehicle_size = 3;
int TMS::transport_vehicle_type_size = 1;

///			//customer
int TMS::custom_size = 1;
int TMS::customer_size = 15;
/// 

//			//driver
int TMS::driver_size = 1;
int TMS::service_size = 0;
int  TMS::temp = 0;
//

TMS::TMS()
{
				//Ride vehicles Type;
	Ride_Vehicle_type = new char*[1];
	Ride_Vehicle_type[0] = new char[50];

	//Transport vehicles Type;
	Transport_Vehicle_type = new char* [1];
	Transport_Vehicle_type[0] = new char[50];
								//Ride vehicle list
				//ride vehicles
	Ride_vehicle_list = new Vehicle * [Ride_vehicle_size];
	for (int i = 0; i < Ride_vehicle_size; i++)
	{
		Ride_vehicle_list[i] = new Vehicle;
	}
				//transport vehicle 
	Transport_vehicle_list = new Vehicle* [transport_vehicle_size];
	for (int i = 0; i < transport_vehicle_size; i++)
	{
		Transport_vehicle_list[i] = new Vehicle;
	}

	//**********************************************************************

	customer_list = NULL;
	service_list = NULL;
	driver_list = NULL;
}

void TMS::add_customer()
{
	if (custom_size == 1)
	{
		customer_list = new Customer* [custom_size];
		customer_list[0] = new Customer;
	}
	else
	{
		Customer** temp = new Customer * [custom_size];
		for (int i = 0; i < custom_size-1; i++)
		{
			temp[i] = new Customer;
			temp[i] = customer_list[i];
		}
		temp[custom_size - 1] = new Customer;
		delete[]customer_list;
		customer_list = new Customer * [custom_size];
		for (int i = 0; i < custom_size; i++)
		{
			customer_list[i] = new Customer;
			customer_list[i] = temp[i];
		}
		delete[]temp;
	}
	cout << "\n******** Adding New Customer **********\n";
	{
		cout << "ENTER YOUR AGE : ";						//set person age
		int age = 0;
		cin >> age;
		customer_list[custom_size - 1]->set_age(age);

		cout << "ENTER YOUR FIRST NAME : ";						//set person name
		char* fname = nullptr;
		fname = new char;
		cin >> fname;
		cout << "ENTER YOUR LAST NAME : ";
		char* lname = nullptr;
		lname = new char;
		cin >> lname;
		customer_list[custom_size - 1]->set_person_name(fname, lname);

		cout << "ENTER YOUR USERNAME (Numeric): ";								//set person username
		int un = 0;
		cin >> un;
		customer_list[custom_size - 1]->set_cId(un);

		cout << "ENTER YOUR DATE OF BIRTH\n";
		cout << "ENTER DATE : ";
		int date;
		cin >> date;
		cout << "ENTER MONTH : ";
		int month;
		cin >> month;
		cout << "ENTER YEAR : ";
		int Year = 0;
		cin >> Year;
		customer_list[custom_size - 1]->set_DOB(date, month, Year);

		cout << "ENTER YOUR NAME ID : ";
		int nid = 0;
		cin >> nid;
		customer_list[custom_size - 1]->set_NID(nid);
		cout << "CUSTOMER SUCCESSFULLY ADDED\n";

		ofstream fout;
		fout.open("Customer.txt");
		fout << endl;
		fout << custom_size;									//customer filing #1
		fout << endl;
		for (int i = 0; i < custom_size; i++)
		{
			fout << customer_list[custom_size - 1][0];				//
		}
		fout.close();

		custom_size++;

	}
}


void TMS::Print_Customer()
{
	for (int i = 0; i < custom_size - 1; i++)
	{
		cout << "\n********** Customer Number " << i + 1 << " **********\n";
		cout << i + 1 << "'S CUSTOMER ID IS : " << customer_list[i]->get_cID() << endl;
		cout << i + 1 << "'S CUSTOMER NAME IS : " << customer_list[i]->get_person_name() << endl;
		cout << i + 1 << "'S CUSTOMER AGE IS : " << customer_list[i]->get_age() << endl;
		cout << i + 1 << "'S CUSTOMER DOB IS : " << customer_list[i]->get_DOB() << endl;
		cout << i + 1 << "'S CUSTOMER NID IS : " << customer_list[i]->get_NID() << endl;
		cout << endl;
	}
}

//ofstream& operator<<(ofstream* fout, TMS& t)
//{
//
//}

void TMS::print_history_of_customer()
{
	cout << "\nEnter Customer ID/Username: ";
	int c_i_d = 0;
	cin >> c_i_d;
	bool flag = false;
	///////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < custom_size-1; i++)
	{
		if (custom_size > 1 && c_i_d == customer_list[i]->get_cID())
		{
			cout << "\nCustomer id: " << customer_list[i]->get_cID();
			cout << "\nCustomer name: " << customer_list[i]->get_person_name();
			cout << "\nCustomer NID: " << customer_list[i]->get_NID();
			cout << "\nCustomer AGe: " << customer_list[i]->get_age();
			cout << "\nCustomer DOB: " << customer_list[i]->get_DOB();
			if (Customer::service_count > 1)
			{
				int c_num = Customer::service_count - 1;
				cout << "\n***** Customer Service History *****";
				for (int j = 0; j < c_num; i++)
				{
					customer_list[j]->print_booking_history(customer_list[j][0]);
				}
			}
			else
			{
				cout << "\n**** No Customers Service History Exists ****";
			}
 		}
		else
		{
			cout << "\n *** Customer ID Not Exists ***";
		}
	}
}

void TMS::print_history_of_driver()
{
	cout << "\nEnter Driver ID/Username: ";
	int c_i_d = 0;
	cin >> c_i_d;
	bool flag = false;
	///////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < driver_size - 1; i++)
	{
		if (driver_size > 1 && c_i_d == driver_list[i]->get_dID())
		{
			cout << "\nDriver id: " << driver_list[i]->get_dID();
			cout << "\nDriver name: " << driver_list[i]->get_person_name();
			cout << "\nDriver NID: " << driver_list[i]->get_NID();
			cout << "\nDriver AGe: " << driver_list[i]->get_age();
			cout << "\nDriver DOB: " << driver_list[i]->get_DOB();
			cout << "\nDriver Nnumber Of Liscence: " << driver_list[i]->get_no_of_liscences();
			for (int j = 0; j < driver_list[j]->get_no_of_liscences(); j++)
			{
				cout << "\nLiscences are: " << driver_list[j]->get_liscence_list(i);
			}
			cout << endl;
			cout << "OVER ALL RANKING : " << driver_list[i]->get_over_all_ranking() << endl;
			cout << "Salary: " << driver_list[i]->get_salary() << endl;
			cout << "Experience: " << driver_list[i]->get_experience() << endl;
			cout << "Status:  ";
			if (driver_list[i]->get_statuc() == 1)
			{
				cout << " FREE" << endl;
			}
			else if (driver_list[i]->get_statuc() == 2)
			{
				cout << "  Booked" << endl;
			}

			if (Driver::service_count > 1)
			{
				int c_num = Driver::service_count - 1;
				cout << "\n***** Driver Service History *****";
				for (int j = 0; j < c_num; i++)
				{
					driver_list[j]->print_service_history();
				}
			}
			else
			{
				cout << "\n**** No Driver Service History Exists ****";
			}
		}
		else
		{
			cout << "\n *** Driver ID Not Exists ***";
		}
	}
}

void TMS::print_list_drivers_ranking()
{
	if (driver_size > 1)
	{
		cout << "\nList of Drivers who have ranking more than 4.5: \n";
		for (int i = 0; i < driver_size - 1; i++)
		{
			if (driver_list[i]->get_over_all_ranking() >= 4.5)
			{
				cout << "\nDriver id: " << driver_list[i]->get_dID();
				cout << "\nDriver name: " << driver_list[i]->get_person_name();
			}
		}
	}
	else
	{
		cout << "\nNo driver Exists: ";
	}
}

void TMS::list_of_cust_dri()
{
	if (temp > 0)
	{
		for (int i = 0; i < temp; i++)
		{
			cout << customer_list[i]->get_cID() << endl;
		}
	}
	else
	{
		cout << "No Same vehicle usage by customers: ";
	}
}

void TMS::list_of_pending_services_date()
{
	cout << "\nEnter DATE: ";
	int d, m, y;
	cout << "\nEnter day: ";
	cin >> d;
	cout << "\nEnter month: ";
	cin >> m;
	cout << "\nEnter year: ";
	cin >> y;


	cout << "\nNo pending services on a particular date: ";
}

void TMS::list_of_pending_services_driver()
{
	cout << "\nEnter Driver ID: ";
	int n;
	cin >> n;

	cout << "\nNo pending services on a particular ID: ";
}

void TMS::list_of_canceled_services()
{
	cout << "\nNo Canceled Services: ";
}

void TMS::print_list_drivers_liscences()
{
	if (driver_size > 1)
	{
		cout << "\nList of Drivers who have multiple liscences: \n";
		for (int i = 0; i < driver_size - 1; i++)
		{
			if (driver_list[i]->get_no_of_liscences() > 1)
			{
				cout << "\nDriver Nnumber Of Liscence: " << driver_list[i]->get_no_of_liscences();
				for (int j = 0; j < driver_list[j]->get_no_of_liscences(); j++)
				{
					cout << "\nLiscences are: " << driver_list[j]->get_liscence_list(i);
				}
			}
		}
	}
	else
	{
		cout << "\nNo driver Exists: ";
	}
}

void TMS::add_a_driver()
{
	if (driver_size == 1)
	{
		driver_list = new Driver * [driver_size];
		driver_list[0] = new Driver;
	}
	else
	{
		Driver** temp = new Driver * [driver_size];
		for (int i = 0; i < driver_size - 1; i++)
		{
			temp[i] = new Driver;
			temp[i] = driver_list[i];
		}
		temp[driver_size - 1] = new Driver;
		delete[]driver_list;
		driver_list = new Driver * [driver_size];
		for (int i = 0; i < driver_size; i++)
		{
			driver_list[i] = new Driver;
			driver_list[i] = temp[i];
		}
		delete[]temp;
	}
	cout << "\n******** Adding New Driver **********\n";
	{

		cout << "ENTER YOUR FIRST NAME : ";						//set person name
		char* fname = nullptr;
		fname = new char;
		cin >> fname;
		cout << "ENTER YOUR LAST NAME : ";
		char* lname = nullptr;
		lname = new char;
		cin >> lname;
		driver_list[driver_size - 1]->set_person_name(fname, lname);

		cout << "ENTER YOUR AGE : ";						//set person age
		int age = 0;
		cin >> age;
		driver_list[driver_size - 1]->set_age(age);

		cout << "ENTER YOUR user ID (Numeric): ";								//set person username
		int un = 0;
		cin >> un;
		driver_list[driver_size - 1]->set_dID(un);

		cout << "ENTER YOUR DATE OF BIRTH\n";
		cout << "ENTER DATE : ";
		int date;
		cin >> date;
		cout << "ENTER MONTH : ";
		int month;
		cin >> month;
		cout << "ENTER YEAR : ";
		int Year = 0;
		cin >> Year;
		driver_list[driver_size - 1]->set_DOB(date, month, Year);

		cout << "ENTER YOUR NAME NID : ";
		int nid = 0;
		cin >> nid;
		driver_list[driver_size - 1]->set_NID(nid);

		cout << "\nHow much liscences Do u have: ";
		int lis;
		cin >> lis;
		if (lis > 0)
		{
			driver_list[driver_size - 1]->set_no_of_liscences(lis);
			for (int k = 0; k < lis; k++)
			{
				char arr[100];
				cout << "\nEnter Liscnce # " << k + 1;
				cin >> arr;
				driver_list[driver_size - 1]->set_liscence_list(arr, k+1);
			}
		}
		cout << "\nHow much Experience do you have (Enter number of years): ";
		cin >> lis;
		driver_list[driver_size - 1]->set_experience(lis);
		cout << "\nEnter Salary: ";
		float sal;
		cin >> sal;
		driver_list[driver_size - 1]->set_salary(sal);
		driver_list[driver_size - 1]->set_status(1);

		cout << "Driver SUCCESSFULLY ADDED\n";

		ofstream fout;
		fout.open("Driver.txt");
		fout << endl;
		fout << driver_size;									//Driver filing #1
		fout << endl;
		for (int i = 0; i < driver_size; i++)				//
		{
			fout << driver_list[i][0];
		}
		fout.close();

		driver_size++;

	}
}

void TMS::remove_a_driver()
{
	cout << "\nEnter Driver ID Which You want to remove: ";
	int di;
	cout << endl;
	for (int i = 0; i < driver_size - 1; i++)
	{
		cout << driver_list[i]->get_dID() << " .  ";
	}
	cin >> di;
	for (int i = 0; i < driver_size -1 ; i++)
	{
		if (di == driver_list[i]->get_dID())
		{
			delete driver_list[i];
			for (int j = i; j < driver_size - 1; j++)
			{
				driver_list[j] = driver_list[j + 1];
			}
			driver_list[driver_size - 1] = NULL;

			Driver** temp = new Driver * [driver_size - 1];
			for (int j = 0; j < driver_size - 2 ; j++)
			{
				temp[j] = new Driver;
				temp[j] = driver_list[j];
			}
			delete[]driver_list;
			driver_size--;
			driver_list = new Driver * [driver_size];
			for (int j = 0; j < driver_size; j++)
			{
				driver_list[j] = new Driver;
				driver_list[j] = temp[j];
			}
			delete[]temp;
		}
	}

	ofstream fout;
	fout.open("Driver.txt");
	fout << endl;
	fout << driver_size ;									//Driver filing #1
	fout << endl;
	for (int i = 0; i < driver_size - 2; i++)
	{
		fout << driver_list[i][0];				//
	}
	fout.close();

}

void TMS::print_driver()
{
	if (driver_size > 1)
	{
		for (int i = 0; i < driver_size - 1; i++)
		{
			cout << "\n********** DRIVER Number " << i + 1 << " **********\n";
			cout << i + 1 << "'S DRIVER ID IS : " << driver_list[i]->get_dID() << endl;
			cout << i + 1 << "'S DRIVER NAME IS : " << driver_list[i]->get_person_name() << endl;
			cout << i + 1 << "'S DRIVER AGE IS : " << driver_list[i]->get_age() << endl;
			cout << i + 1 << "'S DRIVER DOB IS : " << driver_list[i]->get_DOB() << endl;
			cout << i + 1 << "'S DRIVER NID IS : " << driver_list[i]->get_NID() << endl;
			cout << i + 1 << "'S DRIVER NUMBER OF LISCENCES : " << driver_list[i]->get_no_of_liscences();
			for (int j = 0; j < driver_list[i]->get_no_of_liscences(); j++)
			{
				cout << "\nLiscences are: " << driver_list[i]->get_liscence_list(j);
			}
			cout << endl;
			cout << i + 1 << "'S OVER ALL RANKING: " << driver_list[i]->get_over_all_ranking() << endl;
			cout << i + 1 << "'S Salary: " << driver_list[i]->get_salary() << endl;
			cout << i + 1 << "'S Experience: " << driver_list[i]->get_experience() << endl;
			cout << i + 1 << "'S Status: ";
			if (driver_list[i]->get_statuc() == 1)
			{
				cout << " FREE" << endl;
			}
			else if (driver_list[i]->get_statuc() == 2)
			{
				cout << "  Booked" << endl;
			}
			cout << endl;
		}
	}
	else
	{
		cout << "\nNo driver exists: ";
	}
}

void TMS::print_list_drivers_salary()
{
	for (int i = 0; i < driver_size - 1; i++)
	{
		cout << "\nDriver# " << i + 1 << "  Salary: ";
		cout << driver_list[i]->get_salary();
	}
}

void TMS::read_driver_data()
{
	ifstream fin;
	fin.open("Driver.txt");
	bool flag = false;
	if (!fin)
	{
		cout << "\n ******* File Not Exists ********";
		flag = true;
	}
	else
	{
		
		fin >> driver_size;
		
		for (int i = 0; i < driver_size; i++)
		{
			if (driver_list == NULL)
			{
				driver_list = new Driver * [driver_size];
				for (int j = 0; j < driver_size; j++)
				{
					driver_list[j] = new Driver;
				}
			}
			fin >> driver_list[i][0];

		}
	}
	fin.close();
	if (flag == false)
	{
		driver_size++;
	}
}

/*
Customer& TMS::operator[] (int i)
{
	return driver_list[i];
}
*/


void TMS::set_ride_vehicle_type(char* veh)			//add vehicles type;
{
	if (vehicle_type_size == 1)
	{
		strcpy(Ride_Vehicle_type[0], veh);
		vehicle_type_size++;
	}
	else
	{
		char** temp = new char* [vehicle_type_size];				//copying of address to increase array size
		for (int i = 0; i < vehicle_type_size; i++)
		{
			temp[i] = new char;
		}
		for (int i = 0; i < vehicle_type_size-1; i++)
		{
			temp[i] = Ride_Vehicle_type[i];
		}
		strcpy(temp[vehicle_type_size - 1], veh);

		//Vehicle_type = NULL;
		delete[]Ride_Vehicle_type;

		Ride_Vehicle_type = new char* [vehicle_type_size];
		for (int i = 0; i < vehicle_type_size; i++)
		{
			Ride_Vehicle_type[i] = new char;
		}
		for (int i = 0; i < vehicle_type_size; i++)
		{
			Ride_Vehicle_type[i] = temp[i];
		}

		//temp = NULL;
		delete[]temp;

		vehicle_type_size++;
	}
}
char* TMS::get_ride_vehicle_type(int n)
{
	return Ride_Vehicle_type[n];
}

void TMS::add_Ride_veh_details()
{
	//bike details
	Ride_vehicle_list[0]->set_vID(101);
	Ride_vehicle_list[0]->set_registration_no(1901);
	Ride_vehicle_list[0]->set_average_mileage(70.5);		//km/h
	char temp[] = "Bike";
	set_ride_vehicle_type(temp);
	Ride_vehicle_list[0]->set_liscence_type(temp);
	Ride_vehicle_list[0]->set_status(false);
	char temp1[] = "Ocatane Gasolin(Petrol)";
	Ride_vehicle_list[0]->set_fuel_type(temp1);
	Ride_vehicle_list[0]->set_vehicle_rank(5.0);			//for 1 ride;
	Ride_vehicle_list[0]->set_manufacturing_date(1, 6, 2010);
	char temp2[] = "New vehicle, Soft Seat, Quick Ride, Good brakes, light sound, Two Tyres: ";
	Ride_vehicle_list[0]->set_flist(101, temp2, 15.0);        //cost 15Rs per kilometer

			//bike 1st ride service history
	char s_temp1[] = "Lahore Q-Block";
	Ride_vehicle_list[0]->set_service_history(temp, s_temp1, 10.25, 1, 1, 2020, 6, 30, 20, true, 100.5, 301, 401, 101);

	//*****************  Scooter *****************

	// details
	Ride_vehicle_list[1]->set_vID(102);
	Ride_vehicle_list[1]->set_registration_no(1911);
	Ride_vehicle_list[1]->set_average_mileage(40.0);		//km/h
	char temp_2[] = "Bike";
	Ride_vehicle_list[1]->set_liscence_type(temp_2);
	Ride_vehicle_list[1]->set_status(false);
	char temp1_2[] = "Ocatane Gasolin(Petrol)";
	Ride_vehicle_list[1]->set_fuel_type(temp1_2);
	Ride_vehicle_list[1]->set_vehicle_rank(4.0);			//for 1 ride;
	Ride_vehicle_list[1]->set_manufacturing_date(1, 6, 2007);
	char temp2_2[] = "New vehicle, Hard Seat, Slow Ride, Average brakes, Light sound, Two Tyres: ";
	Ride_vehicle_list[1]->set_flist(102, temp2_2, 10.0);        //cost 10 Rs per kilometer

			//scooter 1st ride service history
	char s_temp1_2[] = "Lahore H-Block";
	Ride_vehicle_list[1]->set_service_history(temp_2, s_temp1_2, 5.5, 2, 1, 2020, 4, 10, 30, true, 100.5, 302, 402, 102);

	char tem_2[] = "Scooter";				//add vehicle type
	set_ride_vehicle_type(tem_2);

	//*****************  Car *****************

	// details
	Ride_vehicle_list[2]->set_vID(103);
	Ride_vehicle_list[2]->set_registration_no(1921);
	Ride_vehicle_list[2]->set_average_mileage(120.0);		//km/h
	char temp_3[] = "Car";
	set_ride_vehicle_type(temp_3);
	Ride_vehicle_list[2]->set_liscence_type(temp_3);
	Ride_vehicle_list[2]->set_status(false);
	char temp1_3[] = "High Ocatane Gasolin(Petrol)";
	Ride_vehicle_list[2]->set_fuel_type(temp1_3);
	Ride_vehicle_list[2]->set_vehicle_rank(5.0);			//for 1 ride;
	Ride_vehicle_list[2]->set_manufacturing_date(1, 6, 2012);
	char temp2_3[] = "New vehicle, Soft and comfortable Seats, Fast Ride, Good brakes, No sound, Music installed, Four Tyres ,AC : ";
	Ride_vehicle_list[2]->set_flist(103, temp2_3, 25.0);        //cost 25 Rs per kilometer

			//Car 1st ride service history
	char s_temp1_3[] = "Lahore Khyaban-e-Amin";
	Ride_vehicle_list[2]->set_service_history(temp_3, s_temp1_3, 15.5, 3, 1, 2020, 2, 15, 30, true, 140.5, 303, 403, 103);


	//*****************  Rikshaws *****************

	// details
	Ride_vehicle_list[3]->set_vID(104);
	Ride_vehicle_list[3]->set_registration_no(1931);
	Ride_vehicle_list[3]->set_average_mileage(40.0);		//km/h
	char temp_4[] = "Motor Cycle Rikshaw";
	Ride_vehicle_list[3]->set_liscence_type(temp_4);
	Ride_vehicle_list[3]->set_status(false);
	char temp1_4[] = "Ocatane Gasolin(Petrol)";
	Ride_vehicle_list[3]->set_fuel_type(temp1_4);
	Ride_vehicle_list[3]->set_vehicle_rank(4.5);			//for 1 ride;
	Ride_vehicle_list[3]->set_manufacturing_date(1, 7, 2011);
	char temp2_4[] = "New vehicle, Average Seats, Slow Ride, Normal brakes, Huge vehicle sound, Three Tyres : ";
	Ride_vehicle_list[3]->set_flist(104, temp2_4, 10.0);        //cost 10 Rs per kilometer

			//Rikshaws 1st ride service history
	char s_temp1_4[] = "Lahore City bus stand";
	Ride_vehicle_list[3]->set_service_history(temp_4, s_temp1_4, 8.5, 4, 2, 2020, 3, 45, 30, true, 100.5, 304, 404, 104);


	char tem_4[] = "Rikshaw";
	set_ride_vehicle_type(tem_4);


	//*****************  Van *****************

	// details
	Ride_vehicle_list[4]->set_vID(105);
	Ride_vehicle_list[4]->set_registration_no(1801);
	Ride_vehicle_list[4]->set_average_mileage(50.0);		//km/h
	char temp_5[] = "LTV";
	Ride_vehicle_list[4]->set_liscence_type(temp_5);
	Ride_vehicle_list[4]->set_status(false);
	char temp1_5[] = "Gas";
	Ride_vehicle_list[4]->set_fuel_type(temp1_5);
	Ride_vehicle_list[4]->set_vehicle_rank(4.4);			//for 1 ride;
	Ride_vehicle_list[4]->set_manufacturing_date(2, 7, 2011);
	char temp2_5[] = "New vehicle, Average Seats, Average Ride, Normal brakes, Normal vehicle sound, four Tyres : ";
	Ride_vehicle_list[4]->set_flist(105, temp2_5, 12.0);        //cost 12 Rs per kilometer

			//Van 1st ride service history
	char s_temp1_5[] = "Gujranwala bus stand";
	char tem_5[] = "Van";
	Ride_vehicle_list[4]->set_service_history(tem_5, s_temp1_5, 90.5, 14, 2, 2020, 3, 45, 30, true, 80.5, 305, 405, 105);

	set_ride_vehicle_type(tem_5);

	//*****************  Bus *****************

	// details
	Ride_vehicle_list[5]->set_vID(106);
	Ride_vehicle_list[5]->set_registration_no(1811);
	Ride_vehicle_list[5]->set_average_mileage(65.0);		//km/h
	char temp_6[] = "HTV";
	Ride_vehicle_list[5]->set_liscence_type(temp_6);
	Ride_vehicle_list[5]->set_status(false);
	char temp1_6[] = "Gas";
	Ride_vehicle_list[5]->set_fuel_type(temp1_6);
	Ride_vehicle_list[5]->set_vehicle_rank(4.5);			//for 1 ride;
	Ride_vehicle_list[5]->set_manufacturing_date(2, 8, 2011);
	char temp2_6[] = "New vehicle, Average Seats, Good Ride, Good brakes, Normal vehicle sound, four Tyres, AC : ";
	Ride_vehicle_list[5]->set_flist(106, temp2_6, 11.0);        //cost 11 Rs per kilometer

			//Bus 1st ride service history
	char s_temp1_6[] = "Gujranwala bus stand";
	char tem_6[] = "Bus";
	Ride_vehicle_list[5]->set_service_history(tem_6, s_temp1_6, 90.5, 14, 2, 2020, 3, 45, 30, true, 80.5, 306, 406, 106);

	set_ride_vehicle_type(tem_6);

	//*****************  APV *****************

	// details
	Ride_vehicle_list[6]->set_vID(107);
	Ride_vehicle_list[6]->set_registration_no(1821);
	Ride_vehicle_list[6]->set_average_mileage(75.0);		//km/h
	char temp_7[] = "LTV";
	Ride_vehicle_list[6]->set_liscence_type(temp_7);
	Ride_vehicle_list[6]->set_status(false);
	char temp1_7[] = "Petrol";
	Ride_vehicle_list[6]->set_fuel_type(temp1_7);
	Ride_vehicle_list[6]->set_vehicle_rank(4.5);			//for 1 ride;
	Ride_vehicle_list[6]->set_manufacturing_date(4, 7, 2011);
	char temp2_7[] = "New vehicle, Good Seats, Good Ride, Good brakes, Normal vehicle sound, four Tyres, AC : ";
	Ride_vehicle_list[6]->set_flist(107, temp2_7, 14.0);        //cost 14 Rs per kilometer

			//APV 1st ride service history
	char s_temp1_7[] = "Sialkot bus stand";
	char tem_7[] = "APV";
	Ride_vehicle_list[6]->set_service_history(tem_7, s_temp1_7, 115.5, 12, 2, 2020, 3, 45, 30, true, 100.5, 307, 407, 107);

	set_ride_vehicle_type(tem_7);

	//*****************  Campervans *****************

	// details
	Ride_vehicle_list[7]->set_vID(108);
	Ride_vehicle_list[7]->set_registration_no(1831);
	Ride_vehicle_list[7]->set_average_mileage(75.0);		//km/h
	char temp_8[] = "HTV";
	Ride_vehicle_list[7]->set_liscence_type(temp_8);
	Ride_vehicle_list[7]->set_status(false);
	char temp1_8[] = "Gas";
	Ride_vehicle_list[7]->set_fuel_type(temp1_8);
	Ride_vehicle_list[7]->set_vehicle_rank(4.5);			//for 1 ride;
	Ride_vehicle_list[7]->set_manufacturing_date(4, 8, 2014);
	char temp2_8[] = "New vehicle, Good Seats, Good Ride, Good brakes, Light vehicle sound, four Tyres, AC ,Comfortale Beds: ";
	Ride_vehicle_list[7]->set_flist(108, temp2_8, 15.0);        //cost 15 Rs per kilometer

			//Campervans 1st ride service history
	char s_temp1_8[] = "Islamabad bus stand";
	char tem_8[] = "Campervans";
	Ride_vehicle_list[7]->set_service_history(tem_8, s_temp1_8, 377.2, 15, 3, 2020, 4, 30, 30, true, 80.5, 308, 408, 108);

	set_ride_vehicle_type(tem_8);

	//*****************  Caravan *****************

	// details
	Ride_vehicle_list[8]->set_vID(109);
	Ride_vehicle_list[8]->set_registration_no(1841);
	Ride_vehicle_list[8]->set_average_mileage(77.0);		//km/h
	char temp_9[] = "HTV";
	Ride_vehicle_list[8]->set_liscence_type(temp_9);
	Ride_vehicle_list[8]->set_status(false);
	char temp1_9[] = "Gas";
	Ride_vehicle_list[8]->set_fuel_type(temp1_9);
	Ride_vehicle_list[8]->set_vehicle_rank(4.5);			//for 1 ride;
	Ride_vehicle_list[8]->set_manufacturing_date(4, 8, 2013);
	char temp2_9[] = "New vehicle, comfortable sofas, Good Ride, Good brakes, Light vehicle sound, four Tyres, AC ,Comfortale Beds: ";
	Ride_vehicle_list[8]->set_flist(108, temp2_9, 17.0);        //cost 17 Rs per kilometer

			//Caravan 1st ride service history
	char s_temp1_9[] = "Azad Kashmir bus stand";
	char tem_9[] = "Caravan";
	Ride_vehicle_list[8]->set_service_history(tem_9, s_temp1_9, 513.7, 15, 8, 2020, 4, 30, 30, true, 80.5, 309, 409, 109);
	
	set_ride_vehicle_type(tem_9);

}

void TMS::get_ride_vehicle_ids(int arr[], int& size)
{
	size = Ride_vehicle_size;
	for (int i = 0; i < size; i++)
	{
		int tem = Ride_vehicle_list[i]->get_vID();
		arr[i] = tem;
	}
}

void TMS::print_ride_vehicle_details(int n)
{
	cout << "\n ----------- " << get_ride_vehicle_type(n) << " Details ------------- ";
	cout << Ride_vehicle_list[n][0];
}

void TMS::add_Transport_veh_details()
{
	//*****************  Shahzor *****************

	// details
	Transport_vehicle_list[0]->set_vID(201);
	Transport_vehicle_list[0]->set_registration_no(3011);
	Transport_vehicle_list[0]->set_average_mileage(77.0);		//km/h
	char temp_1[] = "HTV";
	Transport_vehicle_list[0]->set_liscence_type(temp_1);
	Transport_vehicle_list[0]->set_status(false);
	char temp1_1[] = "Gas";
	Transport_vehicle_list[0]->set_fuel_type(temp1_1);
	Transport_vehicle_list[0]->set_vehicle_rank(4.0);			//for 1 transport;
	Transport_vehicle_list[0]->set_manufacturing_date(4, 8, 2013);
	char temp2_1[] = "New vehicle, Good for transport, Good brakes, four Tyres, Used for intrecity Transportion: ";
	Transport_vehicle_list[0]->set_flist(201, temp2_1, 15.0);        //cost 15 Rs per kilometer

			//Shahzor 1st transport service history
	char s_temp1_1[] = "Lahore Defence";
	char tem_1[] = "Shahzor";
	Transport_vehicle_list[0]->set_service_history(tem_1, s_temp1_1, 40.7, 15, 8, 2020, 4, 30, 30, true, 80.5, 351, 451, 201);

	set_transport_vehicle_type(tem_1);

	//*****************  Mazda-Titan *****************

	// details
	Transport_vehicle_list[1]->set_vID(202);
	Transport_vehicle_list[1]->set_registration_no(3021);
	Transport_vehicle_list[1]->set_average_mileage(80.0);		//km/h
	char temp_2[] = "HTV";
	Transport_vehicle_list[1]->set_liscence_type(temp_2);
	Transport_vehicle_list[1]->set_status(false);
	char temp1_2[] = "Gas";
	Transport_vehicle_list[1]->set_fuel_type(temp1_2);
	Transport_vehicle_list[1]->set_vehicle_rank(4.0);			//for 1 transport;
	Transport_vehicle_list[1]->set_manufacturing_date(4, 8, 2014);
	char temp2_2[] = "New vehicle, Good for transport, Good brakes, four Tyres, Used for intrecity Transportion: ";
	Transport_vehicle_list[1]->set_flist(202, temp2_2, 15.0);        //cost 15 Rs per kilometer

			//Mazda-Titan 1st transport service history
	char s_temp1_2[] = "Lahore Minar-e-Pakistan";
	char tem_2[] = "Mazda-Titan";
	Transport_vehicle_list[1]->set_service_history(tem_2, s_temp1_2, 40.7, 15, 8, 2020, 4, 30, 30, true, 80.5, 352, 452, 202);

	set_transport_vehicle_type(tem_2);


	//*****************  Trucks  *****************

	// details
	Transport_vehicle_list[2]->set_vID(203);
	Transport_vehicle_list[2]->set_registration_no(3031);
	Transport_vehicle_list[2]->set_average_mileage(70.0);		//km/h
	char temp_3[] = "HTV";
	Transport_vehicle_list[2]->set_liscence_type(temp_3);
	Transport_vehicle_list[2]->set_status(false);
	char temp1_3[] = "Gas";
	Transport_vehicle_list[2]->set_fuel_type(temp1_3);
	Transport_vehicle_list[2]->set_vehicle_rank(4.0);			//for 1 transport;
	Transport_vehicle_list[2]->set_manufacturing_date(4, 8, 2010);
	char temp2_3[] = "New vehicle, Good for transport, Good brakes, four Tyres, Used for intrecity: ";
	Transport_vehicle_list[2]->set_flist(203, temp2_3, 15.0);        //cost 15 Rs per kilometer

			//Truck 1st transport service history
	char s_temp1_3[] = "Gujranwala";
	char tem_3[] = "Truck";
	Transport_vehicle_list[2]->set_service_history(tem_3, s_temp1_3, 95.7, 15, 4, 2020, 2, 30, 30, true, 80.5, 353, 453, 203);

	set_transport_vehicle_type(tem_3);


}

void TMS::set_transport_vehicle_type(char* veh)
{
	if (transport_vehicle_type_size == 1)
	{
		strcpy(Transport_Vehicle_type[0], veh);
		transport_vehicle_type_size++;
	}
	else
	{
		char** temp = new char* [transport_vehicle_type_size];				//copying of address to increase array size
		for (int i = 0; i < transport_vehicle_type_size; i++)
		{
			temp[i] = new char;
		}
		for (int i = 0; i < transport_vehicle_type_size - 1; i++)
		{
			temp[i] = Transport_Vehicle_type[i];
		}
		strcpy(temp[transport_vehicle_type_size - 1], veh);

		//Vehicle_type = NULL;
		delete[]Transport_Vehicle_type;

		Transport_Vehicle_type = new char* [transport_vehicle_type_size];
		for (int i = 0; i < transport_vehicle_type_size; i++)
		{
			Transport_Vehicle_type[i] = new char;
		}
		for (int i = 0; i < transport_vehicle_type_size; i++)
		{
			Transport_Vehicle_type[i] = temp[i];
		}

		//temp = NULL;
		delete[]temp;

		transport_vehicle_type_size++;
	}
}

char* TMS::get_transport_vehicle_type(int n)
{
	return Transport_Vehicle_type[n];
}
void TMS::get_transport_vehicle_ids(int arr[], int& size)
{
	size = transport_vehicle_size;
	for (int i = 0; i < size; i++)
	{
		int tem = Transport_vehicle_list[i]->get_vID();
		arr[i] = tem;
	}
}
void TMS::print_transport_vehicle_details(int n)
{
	cout << "\n ----------- " << get_transport_vehicle_type(n) << " Details ------------- ";
	cout << Transport_vehicle_list[n][0];
}

ostream& operator<<(ostream& out, TMS& t)
{
	/*out << "\n\n ************* Light Vehicle Details ************";
	out << "\n ----------- Bike Details -------------";
	out << t.Light_vehicle_list[0][0];
	out << "\n\n ----------- Scooter Details -------------";
	out << t.Light_vehicle_list[1][0];
	out << "\n\n ----------- Car Details -------------";
	out << t.Light_vehicle_list[2][0];
	out << "\n\n ----------- Rikshaw Details -------------";
	out << t.Light_vehicle_list[2][0];*/
	return out;
}

void TMS::add_Ride_Vehicle()
{
	cout << "\n ********** Enter Details ************";

	cout << "\n -- Enter Vehicle Registration # --";
	int Reg_no = 0;
	cin >> Reg_no;
	bool Reg_flag = false;
	for (int i = 0; i < Ride_vehicle_size; i++)
	{
		if (Ride_vehicle_list[i]->get_registration_no() == Reg_no)		//check in ride vehicles if already exists or not
		{
			cout << "\n ********** This Vehicle already exists ************";
			Reg_flag = true;
		}
	}
	for (int i = 0; i < transport_vehicle_size; i++)			//check in transpot vehicles if already exist or not
	{
		if (Transport_vehicle_list[i]->get_registration_no() == Reg_no)
		{
			cout << "\n ********** This Vehicle already exists ************";
			Reg_flag = true;
		}
	}
	if (Reg_flag == false)
	{
		Ride_vehicle_size++;
		Vehicle** temp = new Vehicle * [Ride_vehicle_size];
		for (int i = 0; i < Ride_vehicle_size; i++)
		{
			temp[i] = new Vehicle;
		}
		for (int i = 0; i < Ride_vehicle_size - 1; i++)
		{
			temp[i] = Ride_vehicle_list[i];
		}
		delete[]Ride_vehicle_list;				//deallocate original array

											//enter and setting of details
		temp[Ride_vehicle_size - 1]->set_vID(temp[Ride_vehicle_size - 2]->get_vID() + 1);
		temp[Ride_vehicle_size - 1]->set_registration_no(Reg_no);
		cout << "\n-- Enter Vehicle Type --";					//vehicle type
		char v_typ[50] = "\0";
		cin >> v_typ;
		set_ride_vehicle_type(v_typ);

		cout << "\n-- Enter Average Mileage --";				//set mileage
		float Avg_mil = 0;
		cin >> Avg_mil;
		temp[Ride_vehicle_size - 1]->set_average_mileage(Avg_mil);

		cout << "\n-- Enter liscnce Type (Bike,LTV,HTV etc)--";		//liscence type
		char l_typ[50] = "\n";
		cin >> l_typ;
		cin.ignore();
		temp[Ride_vehicle_size - 1]->set_liscence_type(l_typ);

		temp[Ride_vehicle_size - 1]->set_status(false);			//status false (free) because vehicle is a freshie

		cout << "\n-- Enter Fuel Type --";					//fuel type
		char f_typ[50] = "\n";
		cin.get(f_typ, 50);
		cin.ignore();
		temp[Ride_vehicle_size - 1]->set_fuel_type(f_typ);

		temp[Ride_vehicle_size - 1]->set_vehicle_rank(0);		//because of freshie

		cout << "\n-- Enter manufacturing date --";				//manufacturing date
		cout << "\nEnter Day: ";
		int m_d = 0, m_m = 0, m_y = 0;
		cin >> m_d;
		cout << "\nEnter Month: ";
		cin >> m_m;
		cout << "\nEnter year: ";
		cin >> m_y;
		temp[Ride_vehicle_size - 1]->set_manufacturing_date(m_d, m_m, m_y);

		cin.ignore();
		cout << "\n-- Enter Vehicle Features --";				//vehicle features
		char v_fea[100] = "\n";
		cin.get(v_fea, 100);
		cin.ignore();

		cout << "\n-- Enter cost per kilometer --";
		float co_st = 0;
		cin >> co_st;

		temp[Ride_vehicle_size - 1]->set_flist(temp[Ride_vehicle_size - 2]->get_vID() + 1, v_fea, co_st);
		
		// copy data back to original
		Ride_vehicle_list = new Vehicle * [Ride_vehicle_size];
		for (int i = 0; i < Ride_vehicle_size; i++)
		{
			Ride_vehicle_list[i] = new Vehicle;
			Ride_vehicle_list[i] = temp[i];
		}
		delete[]temp;

		cout << "\n++++++++++++++ Vehicle Added successfully +++++++++++++++";
	}

}

void TMS::add_Transport_Vehicle()
{
	cout << "\n ********** Enter Details ************";

	cout << "\n -- Enter Vehicle Registration # --";
	int Reg_no = 0;
	cin >> Reg_no;
	bool Reg_flag = false;
	for (int i = 0; i < transport_vehicle_size; i++)			//check in transpot vehicles if already exist or not
	{
		if (Transport_vehicle_list[i]->get_registration_no() == Reg_no)
		{
			cout << "\n ********** This Vehicle already exists ************";
			Reg_flag = true;
		}
	}
	for (int i = 0; i < Ride_vehicle_size; i++)					//check in ride vehicles if already exists or not
	{
		if (Ride_vehicle_list[i]->get_registration_no() == Reg_no)
		{
			cout << "\n ********** This Vehicle already exists ************";
			Reg_flag = true;
		}
	}
	if (Reg_flag == false)
	{
		transport_vehicle_size++;
		Vehicle** temp = new Vehicle * [transport_vehicle_size];
		for (int i = 0; i < transport_vehicle_size; i++)
		{
			temp[i] = new Vehicle;
		}
		for (int i = 0; i < transport_vehicle_size - 1; i++)
		{
			temp[i] = Transport_vehicle_list[i];
		}
		delete[]Transport_vehicle_list;				//deallocate original array

											//enter and setting of details
		temp[transport_vehicle_size - 1]->set_vID(temp[transport_vehicle_size - 2]->get_vID() + 1);
		temp[transport_vehicle_size - 1]->set_registration_no(Reg_no);
		cout << "\n-- Enter Vehicle Type --";					//vehicle type
		char v_typ[50] = "\0";
		cin >> v_typ;
		set_transport_vehicle_type(v_typ);

		cout << "\n-- Enter Average Mileage --";				//set mileage
		float Avg_mil = 0;
		cin >> Avg_mil;
		temp[transport_vehicle_size - 1]->set_average_mileage(Avg_mil);

		cout << "\n-- Enter liscnce Type (LTV,HTV etc)--";		//liscence type
		char l_typ[50] = "\n";
		cin >> l_typ;
		cin.ignore();
		temp[transport_vehicle_size - 1]->set_liscence_type(l_typ);

		temp[transport_vehicle_size - 1]->set_status(false);			//status false (free) because vehicle is a freshie

		cout << "\n-- Enter Fuel Type --";					//fuel type
		char f_typ[50] = "\n";
		cin.get(f_typ, 50);
		cin.ignore();
		temp[transport_vehicle_size - 1]->set_fuel_type(f_typ);

		temp[transport_vehicle_size - 1]->set_vehicle_rank(0);		//because of freshie

		cout << "\n-- Enter manufacturing date --";				//manufacturing date
		cout << "\nEnter Day: ";
		int m_d = 0, m_m = 0, m_y = 0;
		cin >> m_d;
		cout << "\nEnter Month: ";
		cin >> m_m;
		cout << "\nEnter year: ";
		cin >> m_y;
		temp[transport_vehicle_size - 1]->set_manufacturing_date(m_d, m_m, m_y);

		cin.ignore();
		cout << "\n-- Enter Vehicle Features --";				//vehicle features
		char v_fea[100] = "\n";
		cin.get(v_fea, 100);
		cin.ignore();

		cout << "\n-- Enter cost per kilometer --";
		float co_st = 0;
		cin >> co_st;

		temp[transport_vehicle_size - 1]->set_flist(temp[transport_vehicle_size - 2]->get_vID() + 1, v_fea, co_st);

		// copy data back to original
		Transport_vehicle_list = new Vehicle * [transport_vehicle_size];
		for (int i = 0; i < transport_vehicle_size; i++)
		{
			Transport_vehicle_list[i] = new Vehicle;
			Transport_vehicle_list[i] = temp[i];
		}
		delete[]temp;

		cout << "\n++++++++++++++ Vehicle Added successfully +++++++++++++++";
	}

}

void TMS::remove_ride_Vehicle(int n)						//removing of ride vehicle
{
	for (int i = 0; i < Ride_vehicle_size; i++)
	{
		if (n == Ride_vehicle_list[i]->get_vID())
		{
			delete Ride_vehicle_list[i];					//delete particular vehicle
			//delete Ride_Vehicle_type[i];

			for (int j = i; j < Ride_vehicle_size - 1; j++)
			{
				Ride_vehicle_list[j] = Ride_vehicle_list[j + 1];		//copy addresses
				Ride_Vehicle_type[j] = Ride_Vehicle_type[j + 1];
			}
			Ride_vehicle_list[Ride_vehicle_size - 1] = NULL;
			Ride_Vehicle_type[Ride_vehicle_size - 1] = NULL;

			Ride_vehicle_size--;					//creating new temp array for reducing size of original array
			Vehicle** temp = new Vehicle * [Ride_vehicle_size];
			char** temp2 = new char* [Ride_vehicle_size];
			for (int i = 0; i < Ride_vehicle_size; i++)
			{
				temp[i] = new Vehicle;
				temp2[i] = new char;
				temp[i] = Ride_vehicle_list[i];
				temp2[i] = Ride_Vehicle_type[i];
			}
			delete[]Ride_vehicle_list;				//deallocate original array
			delete[]Ride_Vehicle_type;

							//Reallocation of original array
			Ride_vehicle_list = new Vehicle * [Ride_vehicle_size];
			Ride_Vehicle_type = new char* [Ride_vehicle_size];
			for (int i = 0; i < Ride_vehicle_size; i++)
			{
				Ride_vehicle_list[i] = new Vehicle;
				Ride_vehicle_list[i] = temp[i];
				Ride_Vehicle_type[i] = new char;
				Ride_Vehicle_type[i] = temp2[i];
			}
			delete[]temp;
			delete[]temp2;

			cout << "\nVehicle Removed Successfully: ";
		}
	}
}

void TMS::remove_transport_vehicle(int n)
{
	for (int i = 0; i < transport_vehicle_size; i++)
	{
		if (n == Transport_vehicle_list[i]->get_vID())
		{
			delete Transport_vehicle_list[i];					//delete particular vehicle
			//delete Ride_Vehicle_type[i];

			for (int j = i; j < transport_vehicle_size - 1; j++)
			{
				Transport_vehicle_list[j] = Transport_vehicle_list[j + 1];		//copy addresses
				Transport_Vehicle_type[j] = Transport_Vehicle_type[j + 1];
			}
			Transport_vehicle_list[transport_vehicle_size - 1] = NULL;
			Transport_Vehicle_type[transport_vehicle_size - 1] = NULL;

			transport_vehicle_size--;					//creating new temp array for reducing size of original array
			Vehicle** temp = new Vehicle * [transport_vehicle_size];
			char** temp2 = new char* [transport_vehicle_size];
			for (int i = 0; i < transport_vehicle_size; i++)
			{
				temp[i] = new Vehicle;
				temp2[i] = new char;
				temp[i] = Transport_vehicle_list[i];
				temp2[i] = Transport_Vehicle_type[i];
			}
			delete[]Transport_vehicle_list;				//deallocate original array
			delete[]Transport_Vehicle_type;

			//Reallocation of original array
			Transport_vehicle_list = new Vehicle * [transport_vehicle_size];
			Transport_Vehicle_type = new char* [transport_vehicle_size];
			for (int i = 0; i < transport_vehicle_size; i++)
			{
				Transport_vehicle_list[i] = new Vehicle;
				Transport_vehicle_list[i] = temp[i];
				Transport_Vehicle_type[i] = new char;
				Transport_Vehicle_type[i] = temp2[i];
			}
			delete[]temp;
			delete[]temp2;

			cout << "\nVehicle Removed Successfully: ";
		}
	}
}


void TMS::read_customer_data()
{
	ifstream fin;
	fin.open("Customer.txt");
	if (!fin)
	{
		cout << "\n ******* File Not Exists ********";
	}
	else
	{
		fin >> custom_size;
		for (int i = 0; i < custom_size; i++)
		{
			if (customer_list == NULL)
			{
				customer_list = new Customer * [custom_size];
				for (int j = 0; j < custom_size; j++)
				{
					customer_list[j] = new Customer;
				}
			}
			fin >> customer_list[i][0];
			
		}
	}
	fin.close();
	custom_size++;
}

void TMS::dravers()
{
	cout << "\nAmir,Qasim,farooq,umer,talha,hamza,saad,waseem,dani";
}

void TMS::serive_request_for_customer(int cho)
{
	
	if (service_size == 0)
	{
		service_size++;
		service_list = new Service * [service_size];
		for (int i = 0; i < service_size; i++)
		{
			service_list[i] = new  Service;
		}
	}
	else
	{
		service_size++;
		Service** temp = new Service*[service_size];
		for (int i = 0; i < service_size - 1; i++)
		{
			temp[i] = new Service;
			temp[i] = service_list[i];
		}
		temp[service_size - 1] = new Service;
		delete[]service_list;
		service_list = new Service * [service_size];
		for (int i = 0; i < service_size; i++)
		{
			service_list[i] = new Service;
			service_list[i] = temp[i];
		}
		delete[]temp;
	}
	cin.ignore();
	cout << "\nEnter Source: ";
	char arr1[10];
	cin >> arr1;
	cin.ignore();
	
	cout << "\nEnter Destination: ";		
	char arr2[50];
	cin.get(arr2, 50);
	cin.ignore();
	
	cout << "\nEnter Distance: ";
	float dis;
	cin >> dis;
	cin.ignore();
	
	cout << "\nEnter DATE: ";
	int d, m, y;
	cout << "\nEnter day: ";
	cin >> d;
	cout << "\nEnter month: ";
	cin >> m;
	cout << "\nEnter year: ";
	cin >> y;
	
	cout << "\nEnter TIME ";
	cout << "\nEnter sec: ";
	int ss, mm, hh;
	cin >> ss;
	cout << "\nEnter min: ";
	cin >> mm;
	cout << "\nEnter hour: ";
	cin >> hh;
	cout << "\n\n******* Your Service is in progress **** Are u want to continue to complete or cancel it ***";
	cout << "\n1: continue";
	cout << "\n2: cancel";
	cout << "\nEnter: ";
	int iii;
	bool flag = false;
	cin >> iii;
	if (iii == 1)
	{
		cout << "\nYour service Completed Successfully: ";
		service_list[service_size - 1]->set_source(arr1);			//setting source
		service_list[service_size - 1]->set_destination(arr2);		//setting destination
		service_list[service_size - 1]->set_distance(dis);			//setting distance
		service_list[service_size - 1]->set_booking_date(d, m, y);		//setting date
		service_list[service_size - 1]->set_booking_time(ss, mm, hh);		//setting  time
		service_list[service_size - 1]->set_status(true);
		service_list[service_size - 1]->set_fuel_rate(100);
		service_list[service_size - 1]->set_c_id(cho);
		service_list[service_size - 1]->set_d_id(cho + 100);
		service_list[service_size - 1]->set_v_id(cho + 200);
	}
	else
	{
		cout << "\nYou canceled the service: ";
		cout << "\nYou have charged 50Rs: ";
		flag = true;
	}

	if (flag == false)
	{
		ofstream fout;
		fout.open("Service.txt");
		fout << service_size;
		fout << endl;
		for (int i = 0; i < service_size; i++)
		{
			fout << service_list[i][0];
		}
	}

}

void TMS::service_complete()
{
	cout << "\nService completed: ";
	cout << "\nEnter Ranking for driver: ";
	int rank;
	cin >> rank;
	cout << "\nEnter Ranking for vehicle: ";
	int veh;
	cin >> veh;
	cout << "\nThanks for Feedback: ";

}

//ifstream& operator>>(ifstream& fin, TMS& t)
//{
//	fin >> t.custom_size;
//	for (int i = 0; i < t.custom_size; i++)
//	{
//		if (t.service_list != NULL)
//		{
//
//		}
//	}
//}

TMS::~TMS()									// destructor
{
	if (Ride_vehicle_list != NULL)					//deallocation of ride vehicle list
	{
		for (int i = 0; i < Ride_vehicle_size; i++)
		{
			delete Ride_vehicle_list[i];
		}
		delete[]Ride_vehicle_list;
	}
	if (Ride_Vehicle_type != NULL)					//deallocation of ride vehicle type
	{
		for (int i = 0; i < vehicle_type_size; i++)
		{
			delete[]Ride_Vehicle_type[i];
		}
		delete[]Ride_Vehicle_type;
	}
	if (Transport_vehicle_list != NULL)				//deallocation of transport vehicle list
	{
		for (int i = 0; i < transport_vehicle_size; i++)
		{
			delete Transport_vehicle_list[i];
		}
		delete[]Transport_vehicle_list;
	}
	if (Transport_Vehicle_type != NULL)				//deallocation of transport vehicle type
	{
		for (int i = 0; i < transport_vehicle_type_size; i++)
		{
			delete[]Transport_Vehicle_type[i];
		}
		delete[]Transport_Vehicle_type;
	}
	if (customer_list != NULL)						//deallocation of customer list
	{
		for (int i = 0; i < custom_size - 1; i++)
		{
			if (customer_list[i] != NULL)
			{
				delete customer_list[i];
			}
		}
		delete[]customer_list;
	}
	if (driver_list != NULL)						//deallocating driver list
	{
		for (int i = 0; i < driver_size - 1; i++)
		{
			if (driver_list[i] != NULL)
			{
				delete driver_list[i];
			}
		}
		delete[]driver_list;
	}
	if (service_list != NULL)						//deallocating service list
	{
		for (int i = 0; i < service_size; i++)
		{
			if (service_list[i] != NULL)
			{
				delete service_list[i];
			}
		}
		delete[]service_list;
	}
}							