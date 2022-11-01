#pragma once

#include "date.h"
#include "mtime.h";
#include "service.h";
#include <iostream>
using namespace std;

class Ride :public Service
{
	int noOfpassengers;			//false for pending true for complete
	char* rideType;			//intercity, intracity
	float DriverRanking;	//0 to 5 scale (worst to best)
	float VehicleRanking;	//0 to 5 scale (worst to best)
};