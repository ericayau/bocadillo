// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const int MAXLAPTOPS = 5;

int main()
{

	double price[MAXLAPTOPS] = { 350.0, 750.0, 1200.0, 499.0, 999.0 };
	int serial[MAXLAPTOPS] = { 1234, 5678, 9101, 1121, 3141 };

	cout << "Serial number, Basic Price, Price after discount\n";

	for (int i = 0; i < MAXLAPTOPS; i++) { 
		// i is used as a marker for each element in the array. i=0 means it starts at first element.
		//; the loop will continue as long as i is less than MAXLAPTOPS (the array)
		//; i++, tells the loop to continue by 1 after each iteration, progressing.

		double discount = 0;
		//initializes discount variable

		if (price[i] < 500)
			discount = 50.0;
		//if the element i in the array price is less than 500,then discount is 50

		else if (price[i] > 1000)
			discount = 200.0;
		//same for here, the discount is 200 for the specific i

		else
			discount = 100.0;
		//this is because in between, the discount is 100.

		cout << serial[i] << "\t\t$" << price[i] << "\t\t$" << (price[i] - discount) << endl;
	}//prints the serial number, the price, and the price-the discount, in a row under the first cout.



	return 0;
}

