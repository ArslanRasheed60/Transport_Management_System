#include "name.h";
#include <cstring>


Name::Name()					//default constructor
{
	fname = NULL;
	lname = NULL;
}

Name::Name(char* fN, char* lN)			//parametized constructor
{
	fname = new char[(strlen(fN) + 1)];
	strcpy(fname, fN);
	lname = new char[(strlen(lN) + 1)];
	strcpy(lname, lN);
}

Name::Name(const Name& n)				//copy constructor
{
	fname = new char[(strlen(n.fname) + 1)];
	strcpy(fname, n.fname);
	lname = new char[(strlen(n.lname) + 1)];
	strcpy(lname, n.lname);
}

void Name::set_fname(char* fN)
{
	if (fname != NULL)
	{
		delete[]fname;
		fname = new char[(strlen(fN) + 1)];
		strcpy(fname, fN);
	}
	else
	{
		fname = new char[(strlen(fN) + 1)];
		strcpy(fname, fN);
	}
}
void Name::set_lname(char* lN)
{
	if (lname != NULL)
	{
		delete[]lname;
		lname = new char[(strlen(lN) + 1)];
		strcpy(lname, lN);
	}
	else
	{
		lname = new char[(strlen(lN) + 1)];
		strcpy(lname, lN);
	}
}

char* Name::get_fname()					// getter fullname
{
	return fname;
}
char* Name::get_lname()					//getter full name
{
	return lname;
}

ostream& operator<<(ostream& out, const Name& n)
{
	out << n.fname << " " << n.lname;
	return out;
}

ofstream& operator<<(ofstream& fout, Name& n)
{
	fout << n.fname;
	fout << endl;
	fout << n.lname;
	fout << endl;
	return fout;
}
//ifstream& operator>>(ifstream& fin, Name& n)
//{
//	//fin.ignore();
//	if (n.fname == NULL)
//	{
//		n.fname = new char[100];
//		fin.get(n.fname, 100);
//		//cin.ignore();
//	}
//	else
//	{
//		delete[]n.fname;
//		n.fname = new char[100];
//		fin.get(n.fname, 100);
//		cin.ignore();
//	}
//	if (n.lname == NULL)
//	{
//		n.lname = new char[100];
//		fin.get(n.lname, 100);
//		cin.ignore();
//	}
//	else
//	{
//		delete[]n.lname;
//		n.lname = new char[100];
//		fin.get(n.lname, 100);
//		cin.ignore();
//	}
//	return fin;
//}

ifstream& operator>>(ifstream& fin, Name& n)
{
	//fin.ignore();
	if (n.fname == NULL)
	{
		n.fname = new char[20];
		fin >> n.fname;
		//cin.ignore();
	}
	else
	{
		delete[]n.fname;
		n.fname = new char[20];
		fin >> n.fname;
		//cin.ignore();
	}
	if (n.lname == NULL)
	{
		n.lname = new char[100];
		fin >> n.lname;
		//cin.ignore();
	}
	else
	{
		delete[]n.lname;
		n.lname = new char[20];
		fin >> n.lname;
		//cin.ignore();
	}
	return fin;
}

Name::~Name()							//destructor
{
	if (fname != NULL)
	{
		delete[]fname;
	}
	if (lname != NULL)
	{
		delete[]lname;
	}

	fname = NULL;
	lname = NULL;
}

