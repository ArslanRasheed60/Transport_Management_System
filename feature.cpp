#include "feature.h";
#include <iostream>
#include <cstring>

using namespace std;

//constructors 
Feature::Feature()
{
	fID = 0;
	description = NULL;
	cost = NULL;
}
Feature::Feature(int id, char* descrip, float cost)
{
	fID = id;
	description = new char[(strlen(descrip) + 1)];
	strcpy(description, descrip);
	this->cost = cost;
}
Feature::Feature(const Feature& f)
{
	fID = f.fID;
	description = new char[(strlen(f.description) + 1)];
	strcpy(description, f.description);
	cost = f.cost;
}

//setters
void Feature::set_fID(int id)
{
	fID = id;
}
void Feature::set_description(char* descrip)
{
	if (description != NULL)
	{
		delete[]description;
		description = new char[(strlen(descrip) + 1)];
		strcpy(description, descrip);
	}
	else
	{
		description = new char[(strlen(descrip) + 1)];
		strcpy(description, descrip);
	}
}
void Feature::set_cost(float cost)
{
	this->cost = cost;
}

//getters
int Feature::get_fID()
{
	return fID;
}
char* Feature::get_description()
{
	return description;
}
float Feature::get_cost()
{
	return cost;
}

//output
ostream& operator<<(ostream& out, const Feature& f)
{
	out << "\n***** Feature Id ******";
	out << "\nfID :-> " << f.fID;
	out << "\nDescription :-> " << f.description;
	out << "\ncost :-> " << f.cost << "  Rs/km";
	return out;
}

ofstream& operator<<(ofstream& fout, Feature& f)
{
	fout << f.fID;
	fout << endl;
	fout << f.description;
	fout << endl;
	fout << f.cost;
	fout << endl;
	return fout;
}

//destructors
Feature::~Feature()
{
	if (description != NULL)
	{
		delete[]description;
	}
}