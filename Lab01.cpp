/*Lab01.cpp
Andrew Watts
COSC 2030 lab01
September 17, 2018*/

#include<iostream>
using std::cout;
using std::endl;
using std::cin;


#include<string>
using std::string;

#include<fstream>
using std::ifstream;

int main()
{
	string filename;
	double first(0), second(0), last(0), beforelast(0);
	int lengthcounter(0);

	cout << "Please enter a filename:" << endl;
	cin >> filename;

	ifstream infile;

	infile.open(filename); //opens the file with the name given
	while (infile.fail()) {  //Kicks out filenames that can't be opened
		cout << "Could not open: " << filename << endl;
		cout << "Please enter a filename:" << endl;
		cin >> filename;
		infile.open(filename); //tries again
	}

	double temp; //holds whatever value until put somewhere or not needed
	while (infile >> temp) 
	{
		beforelast = last; //sets the second to last to whatever was previouly in last
		lengthcounter++;
		if (lengthcounter == 1) 
		{
			first = temp; //sets the first number
		}
		else if (lengthcounter == 2)
		{
			second = temp; //sets the second number
		};
		last = temp; //stores every number that comes along and will contain the last number when the end is reached

	};

	if (lengthcounter==0) //this is self explanitory
	{
		cout << "This file is empty" << endl;
	}
	else
	{
		cout << "This file contains " << lengthcounter << " values." << endl;
		cout << "The first value is: " << first << endl;
		cout << "The second value is: " << second << endl;
		cout << "The second to last value is: " << beforelast << endl;
		cout << "The last value is: " << last << endl;
	};

	infile.close();
	system("pause"); //just here to stop the console from closing instantly
	return(0);
};

