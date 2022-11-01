#include <iostream>
#include "date.h";
#include "mtime.h";
#include "name.h";
#include "service.h";
#include "ride.h";
#include "customer.h";
#include "person.h";
#include "tms.h";

static int arr_size = 0;
static int arrarr[10] = {0};

using namespace std;
int main()
{
	TMS transport_1;

	transport_1.read_customer_data();
	transport_1.read_driver_data();
	transport_1.add_Ride_veh_details();
	transport_1.add_Transport_veh_details();
	cout << "--------------------------------------------TRANSPORT MANAGEMENT SYSTEM----------------------------------------------\n";
	cout << "1-ADD A NEW CUSTOMER\n2-ADD OR REMOVE A DRIVER\n3-ADD OR REMOVE A VEHICLE\n4-PRINT LIST OF ALL CUSTOMERS\n"
		<< "5-PRINT LIST OF ALL DRIVERS\n6-PRINT COMPLETE LIST OF VEHICLES\n"
		<< "7-PRINT COMPLETE DETAILS AND SERVICE HISTORY OF A PARTICULAR VEHICLE\n" <<
		"8-PRINT COMPLETE HISTORY OF A PARTICULAR CUSTOMER\n" <<
		"9-PRINT COMPLETE HISTORY OF A DRIVER INCLUDING SERVICES\n10-PRINT LIST OF ALL DRIVERS WHO HAVE RANKING ABOVE 4.5\n"
		<< "11-PRINT LIST OF ALL DRIVERS WHO HAVE MULTIPLE LICENSES\n12-PRINT UPDATED SALARY OF ALL DRIVERS BASED ON THEIR UPDATED RANKING\n"
		<< "13-ADD A SERVICE REQUEST(RIDE OR DELIVERY) OR CANCEL A BOOKING\n" <<
		"14-COMPLETE A SERVICE\n15-PRINT DETAILS OF ALL CUSTOMERS\n" <<
		"16-PRINT THE LIST OF ALL DRIVERS\n17-PRINT DETAILS OF ALL PENDING SERVICES\n" <<
		"18-PRINT DETAILS OF ALL PENDING SERVICES OF A PARTICULAR DRIVER\n19-PRINT DETAILS OF ALL CANCELED SERVICES BY A CUSTOMER\n20-EXIT THE TMS PROGRAMME\n";
	int choice = 0;
	cout << "\nENTER YOUR CHOICE : ";
	cin >> choice;
	int customer_counter = 0;
	while (true)
	{
		if (choice == 1)
		{							//add new customers
			transport_1.add_customer();	
		}
		else if (choice == 2)
		{
			int cho_1 = 0;
			cout << "\n1: Add a driver: ";
			cout << "\n2: Remove a driver: ";
			cout << "\nEnter choice: ";
			cin >> cho_1;
			while (cho_1 != 1 && cho_1 != 2)
			{
				cout << "\n ******__________ INVALID CHOICE: ENTER AGAIN _________ *******: ";
				cin >> cho_1;
			}			
			if (cho_1 == 1)					//adding a driver:
			{
				transport_1.add_a_driver();
			}
			else
			{
				transport_1.remove_a_driver();
			}
		}
		else if (choice == 3)
		{
			int cho_1 = 0;
			cout << "\n1: Add a vehicle: ";
			cout << "\n2: Remove a vehicle: ";
			cout << "\nEnter choice: ";
			cin >> cho_1;
			while (cho_1 != 1 && cho_1 != 2 )
			{
				cout << "\n ******__________ INVALID CHOICE: ENTER AGAIN _________ *******: ";
				cin >> cho_1;
			}
			if (cho_1 == 1)			//add a vehicle
			{
				int cho_1_1 = 0;
				cout << "\n1: Add Ride Vehicle: ";
				cout << "\n2: Add transport Vehicle: ";
				cout << "\n3: Add Both (Ride and transport): ";
				cout << "\nEnter choice: ";
				cin >> cho_1_1;
				while (cho_1_1 != 1 && cho_1_1 != 2 && cho_1_1 != 3)
				{
					cout << "\n ******__________ INVALID CHOICE: ENTER AGAIN _________ *******: ";
					cin >> cho_1_1;
				}
				if (cho_1_1 == 1)		// add Ride vehicle
				{
					transport_1.add_Ride_Vehicle();
				}
				else if (cho_1_1 == 2)		//add transport vehicle
				{
					transport_1.add_Transport_Vehicle();
				}
				else        //add both type vehicles
				{
					transport_1.add_Ride_Vehicle();
				}

			}
			else              // for removing a vehicle
			{
				int v_size = 0;
				int v_arr[100] = { 0 };
				int cho_1_2 = 0;
				cout << "\n1: Remove Ride Vehicle: ";
				cout << "\n2: Remove transport Vehicle: ";
				cout << "\n3: Remove Both (Ride and transport): ";
				cout << "\nEnter choice: ";
				cin >> cho_1_2;
				while (cho_1_2 != 1 && cho_1_2 != 2 && cho_1_2 != 3)
				{
					cout << "\n ******__________ INVALID CHOICE: ENTER AGAIN _________ *******: ";
					cin >> cho_1_2;
				}
				if (cho_1_2 == 1)			// remove ride vehicle
				{
					transport_1.get_ride_vehicle_ids(v_arr, v_size);
					cout << "\nChoose ID for removing of vehicle: ";
					for (int i = 0; i < v_size; i++)
					{
						cout << endl << i + 1 << ": -( " << transport_1.get_ride_vehicle_type(i) << " )- . ID: " << v_arr[i];
					}
					cout << endl;
					cout << "\nEnter : ";
					int cho_1_1;
					cin >> cho_1_1;
					while (cho_1_1 < 1 || cho_1_1 > v_size)
					{
						cout << "\n ******__________ INVALID CHOICE: ENTER AGAIN _________ *******: ";
						cin >> cho_1_1;
					}
					cho_1_1--;
					transport_1.remove_ride_Vehicle(v_arr[cho_1_1]);
				}
				else if(cho_1_2 == 2)				//remove transport vehicle
				{
					transport_1.get_transport_vehicle_ids(v_arr, v_size);
					cout << "\nChoose ID for removing of vehicle: ";
					for (int i = 0; i < v_size; i++)
					{
						cout << endl << i + 1 << ": -( " << transport_1.get_transport_vehicle_type(i) << " )- . ID: " << v_arr[i];
					}
					cout << endl;
					cout << "\nEnter : "; 
					int cho_1_1;
					cin >> cho_1_1;
					while (cho_1_1 < 1 || cho_1_1 > v_size)
					{
						cout << "\n ******__________ INVALID CHOICE: ENTER AGAIN _________ *******: ";
						cin >> cho_1_1;
					}
					cho_1_1--;
					transport_1.remove_transport_vehicle(v_arr[cho_1_1]);
				}
				else                            // remove both (ride and transport) vehicle
				{
					transport_1.get_ride_vehicle_ids(v_arr, v_size);
					int temp[10] = { 0 };
					int cnt = 0;
					cout << "\nChoose ID for vehicle details and service history: ";
					for (int i = 0; i < v_size; i++)
					{																//it is supposed that only two bike and Rikshaws are used for both categories
						if (strcmp(transport_1.get_ride_vehicle_type(i), "Bike") == 0 || strcmp(transport_1.get_ride_vehicle_type(i), "Rikshaw") == 0)
						{
							cout << endl << i + 1 << ": -( " << transport_1.get_ride_vehicle_type(i) << " )- . ID: " << v_arr[i];
							temp[cnt] = i;
							cnt++;
						}
					}
					cout << endl;
					cout << "\nEnter : ";
					int cho_1_1;
					cin >> cho_1_1;
					bool flag = false;
					cho_1_1--;
					for (int i = 0; i < cnt; i++)
					{
						if (cho_1_1 == temp[i])
						{
							transport_1.remove_ride_Vehicle(v_arr[cho_1_1]);
							flag = true;
						}
					}
					if (flag == false)
					{
						cout << "\n*********** Invalid id: Vehicle not exist **********";
					}
				}

			}

		}
		else if (choice == 4)
		{
			transport_1.Print_Customer();
		}
		else if (choice == 5)
		{
			transport_1.print_driver();
		}
		else if (choice == 6)
		{
			int v_size1 = 0;
			int v_size2 = 0;
			int v_size3 = 0;
			int v_arr1[100] = { 0 };
			int v_arr2[100] = { 0 };
			int v_arr3[100] = { 0 };

			cout << "\n ******** In Ride Vehicles.. We Have ***********";
			transport_1.get_ride_vehicle_ids(v_arr1, v_size1);								//printing ride vehicles
			for (int i = 0; i < v_size1; i++)
			{
				cout << endl << i + 1 << ": -( " << transport_1.get_ride_vehicle_type(i) << " )- . ID: " << v_arr1[i];
			}

			cout << "\n ******** In Transport Vehicles.. We Have ***********";
			transport_1.get_transport_vehicle_ids(v_arr2, v_size2);							//printing transport vehicles
			for (int i = 0; i < v_size2; i++)
			{
				cout << endl << i + 1 << ": -( " << transport_1.get_transport_vehicle_type(i) << " )- . ID: " << v_arr2[i];
			}

			cout << "\n ******** In Both(Ride and Transport) Vehicles.. We Have ***********";
			transport_1.get_ride_vehicle_ids(v_arr3, v_size3);								//print vehicles of both categories
			for (int i = 0; i < v_size3; i++)
			{
				if (strcmp(transport_1.get_ride_vehicle_type(i), "Bike") == 0 || strcmp(transport_1.get_ride_vehicle_type(i), "Rikshaw") == 0)
				{
					cout << endl << i + 1 << ": -( " << transport_1.get_ride_vehicle_type(i) << " )- . ID: " << v_arr3[i];
				}
			}
		}
		else if (choice == 7)
		{
			int v_size = 0;
			int v_arr[100] = { 0 };
			int cho_1 = 0;
			cout << "\n1: *** Check Ride Vehicles ***";
			cout << "\n2: *** Check Transport Vehicles ***";
			cout << "\n3: *** Check Both Ride and Transport Vehicles ***";
			cout << "\nEnter choice:   ";
			cin >> cho_1;
			while (cho_1!= 1 && cho_1!= 2 && cho_1!= 3)
			{
				cout << "\n ******__________ INVALID CHOICE: ENTER AGAIN _________ *******: ";
				cin >> cho_1;
			}
			if (cho_1 == 1)
			{
				transport_1.get_ride_vehicle_ids(v_arr, v_size);
				cout << "\nChoose ID for vehicle details and service history: ";
				for (int i = 0; i < v_size; i++)
				{
					cout << endl << i+1 <<": -( " << transport_1.get_ride_vehicle_type(i) << " )- . ID: " << v_arr[i];
				}
				cout << endl;
				cout << "\nEnter : ";
				int cho_1_1;
				cin >> cho_1_1;
				while (cho_1_1 < 1 || cho_1_1 > v_size)
				{
					cout << "\n ******__________ INVALID CHOICE: ENTER AGAIN _________ *******: ";
					cin >> cho_1_1;
				}
				cho_1_1--;
				transport_1.print_ride_vehicle_details(cho_1_1);
			}
			else if (cho_1 == 2)
			{
				transport_1.get_transport_vehicle_ids(v_arr, v_size);
				cout << "\nChoose ID for vehicle details and service history: ";
				for (int i = 0; i < v_size; i++)
				{
					cout << endl << i + 1 << ": -( " << transport_1.get_transport_vehicle_type(i) << " )- . ID: " << v_arr[i];
				}
				cout << endl;
				cout << "\nEnter : ";
				int cho_1_1;
				cin >> cho_1_1;
				while (cho_1_1 < 1 || cho_1_1 > v_size)
				{
					cout << "\n ******__________ INVALID CHOICE: ENTER AGAIN _________ *******: ";
					cin >> cho_1_1;
				}
				cho_1_1--;
				transport_1.print_transport_vehicle_details(cho_1_1);
			}
			else
			{
				transport_1.get_ride_vehicle_ids(v_arr, v_size);
				int temp[10] = { 0 };
				int cnt = 0;
				cout << "\nChoose ID for vehicle details and service history: ";
				for (int i = 0; i < v_size; i++)
				{
					if (strcmp(transport_1.get_ride_vehicle_type(i),"Bike") == 0 || strcmp(transport_1.get_ride_vehicle_type(i),"Rikshaw") == 0)
					{
						cout << endl << i + 1 << ": -( " << transport_1.get_ride_vehicle_type(i) << " )- . ID: " << v_arr[i];
						temp[cnt] = i;
						cnt++;
					}
				}
				cout << endl;
				cout << "\nEnter : ";
				int cho_1_1;
				cin >> cho_1_1;
				bool flag = false;
				cho_1_1--;
				for (int i = 0; i < cnt; i++)
				{
					if (cho_1_1 == temp[i])
					{
						transport_1.print_ride_vehicle_details(cho_1_1);
						flag = true;
					}
				}
				if (flag == false)
				{
					cout << "\n*********** Invalid id: Vehicle not exist **********";
				}
				
			}

		}
		else if (choice == 8)
		{
			transport_1.print_history_of_customer();
		}
		else if (choice == 9)
		{
			transport_1.print_history_of_driver();
		}
		else if (choice == 10)
		{
			transport_1.print_list_drivers_ranking();
		}
		else if (choice == 11)
		{
			transport_1.print_list_drivers_liscences();
		}
		else if (choice == 12)
		{
			transport_1.print_list_drivers_salary();
		}
		else if (choice == 13)
		{
			cout << "\n**************** Service Request **************";
			cout << "\n1: Want to ride??";
			cout << "\n2: Want to deliver??";
			cout << "\nEnter : ";
			int cho_1;
			int v_size = 0;
			int v_arr[100] = { 0 };
			cin >> cho_1;
			while (cho_1 != 1 && cho_1 != 2)
			{
				cout << "\n ******__________ INVALID CHOICE: ENTER AGAIN _________ *******: ";
				cin >> cho_1;
			}
			if (cho_1 == 1 || cho_1 == 2)
			{
				transport_1.get_ride_vehicle_ids(v_arr, v_size);
				cout << "\nChoose ID for vehicle: ";
				for (int i = 0; i < v_size; i++)
				{
					cout << endl << i + 1 << ": -( " << transport_1.get_ride_vehicle_type(i) << " )- . ID: " << v_arr[i];
				}
				cout << "\nDrivers: ";
				transport_1.dravers();
				cout << endl;
				cout << "\nEnter : ";
				int cho_1_1;
				cin >> cho_1_1;
				while (cho_1_1 < 1 || cho_1_1 > v_size)
				{
					cout << "\n ******__________ INVALID CHOICE: ENTER AGAIN _________ *******: ";
					cin >> cho_1_1;
				}
				arrarr[arr_size] = cho_1_1;
				arr_size++;
				transport_1.serive_request_for_customer(cho_1_1);
			}
			
		}
		else if (choice == 14)
		{
			transport_1.service_complete();
		}
		else if (choice == 15)
		{
			transport_1.list_of_cust_dri();
		}
		else if (choice == 16)
		{
			transport_1.print_driver();
		}
		else if (choice == 17)
		{
			transport_1.list_of_pending_services_date();
		}
		else if (choice == 18)
		{
			transport_1.list_of_pending_services_driver();
		}
		else if (choice == 19)
		{
			transport_1.list_of_canceled_services();
		}
		else if (choice == 20)
			exit(0);
		else
			cout << "INVALID CHOICE\n";

		cout << "\n\nENTER YOUR CHOICE AGAIN : ";
		cin >> choice;

	}
	system("pause");

	return 0;
}