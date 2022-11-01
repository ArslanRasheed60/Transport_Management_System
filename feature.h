#pragma once

#include <iostream>
#include <fstream>
using namespace std;

class Feature
{
	int fID;
	char* description;
	float cost;
public:
			//constructors 
	Feature();
	Feature(int id, char* descrip, float cost);
	Feature(const Feature& f);

	//setters
	void set_fID(int id);
	void set_description(char* descrip);
	void set_cost(float cost);

	//getters
	int get_fID();
	char* get_description();
	float get_cost();

	//output
	friend ostream& operator<<(ostream& out, const Feature& f);
	friend ofstream& operator<<(ofstream& fout, Feature& f);

	//destructors
	~Feature();
};