// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//inventory

int main()
{
	string list[5];
	
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter some words: ";
		cin >> list[i];

	}

	// display values of the array

	for (int i = 0; i < 5; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;



	return 0;
}