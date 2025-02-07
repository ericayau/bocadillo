// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//first telling you to print it out

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

//2
//You must modify the code so that you use a struct for each laptop that contains its serial
//number and price.An array of these must be used instead of the separate arrays to generate the
//display as in Part 1. In addition, your code must calculate and display the highest price laptop
//(before discount) as shown.

const int MAXLAPTOPS = 5;

struct Laptop {
	int serialnumber;
	double price;
	// Laptop struct consists of serialnumber integer representing the laptop's ID
	// price is a variable representing the laptops price
};

int main() {
	Laptop laptops[MAXLAPTOPS] = {
	//This declares an array of Laptop objects called laptops.
	// initializes 5 elements below

		{1234, 350.0}, {5678, 750.0}, {9101, 1200.0}, {1121, 499.0}, {3141, 999.0} };
	
	cout << "Serial Number\tBasic Price\tPrice After Discount\n";
	// prints menu

	double maxPrice = 0.0;
	//initialises var of highest price found

	int maxPriceSerial = 0;
	//stores serial number of highest price laptop

	for (int i = 0; i < MAXLAPTOPS; i++) {
		//A loop runs from i = 0 to i = 4 (since MAXLAPTOPS = 5).
		// it processes each laptop one by one

		double discount = 0;
		//discount is initialised to 0 for each laptop

		if (laptops[i].price < 500)
			discount = 50.0;
		else if (laptops[i].price > 1000)
			discount = 200.0;
		else
			discount = 100.0;
		//same as before

		cout << laptops[i].serialNumber << "\t\t£" << laptops[i].price
			//prints as before same of the serial number price and discounted price.
			<< "\t\t£" << (laptops[i].price - discount) << endl;
		if (laptops[i].price > maxPrice) {
			//if the current laptop price is higher than maxprice:
			maxPrice = laptops[i].price;
			//update maxprice to this laptops price
			maxPriceSerial = laptops[i].serialNumber;
			//update maxpriceserial to this laptops serial number
			//This ensures that by the end of the loop, maxPrice 
			// holds the highest price and maxPriceSerial holds its serial number.
		}
	}
	cout << "\nThe highest price laptop is Serial Number " << maxPriceSerial
		<< " with a price of £" << maxPrice << ".\n";
	return 0;
		}
	}
}
//3
// ADD FUNCTION
//You will add to your code a function called CalculateDiscount that calculates the discount
//based on the rules in Part 1 and returns the discount value.The parameter to the function must be
//the base price of the laptop.
//Your code must use the function to calculate the discount for the displayed information

const int MAXLAPTOPS = 5;
struct Laptop {
	//contains the struct from part 2
	int serialNumber;
	double price;
	//and both variables here again
};
double CalculateDiscount(double price) {
	//the parameter double price receives the base price of the laptop.
	// calculatediscount uses this parameter
	if (price < 500)
		return 50.0;
	else if (price > 1000)
		return 200.0;
	else
		return 100.0;
}
int main() {
	Laptop laptops[MAXLAPTOPS] = {
		// declares an array of structs called laptops with 5 MAXLAPTOPS elements
		// each Laptop struct contains a serial number and a base price
	{1234, 350.0}, {5678, 750.0}, {9101, 1200.0}, {1121, 499.0}, {3141, 999.0} };
	
	cout << "Serial Number\tBasic Price\tPrice After Discount\n";

	double maxPrice = 0.0;
	//stores the highest laptop price found
	int maxPriceSerial = 0;
	//stores the serial number of the laptop with the highest price
	for (int i = 0; i < MAXLAPTOPS; i++) {
		//a loop runs from i = 0 to 4. (5 elements)
		//processes each laptop one by one

		double discount = CalculateDiscount(laptops[i].price);
		//calls the function CalculateDiscount
		//since laptops is an array of Laptop struct, each element in the array [i]
		//represents a single Laptop object
		//laptops[i].price accesses the price attribute of the Laptop at the point i.
		//discount returns the value.

		cout << laptops[i].serialNumber << "\t\t£" << laptops[i].price
			//prints everything here
			<< "\t\t£" << (laptops[i].price - discount) << endl;
		
		if (laptops[i].price > maxPrice) {
			//if this specific laptops price is GREATER than maxprice
			// then maxprice is created as a result
			maxPrice = laptops[i].price;
			maxPriceSerial = laptops[i].serialNumber;
			//here is where the discount is calculated
			// if the current laptop price is higher than maxprice,
			// update maxprice to this laptops price. as it iterates it will keep updating
			// updates maxpriceserial to this laptops serial number.
			//if the price of a certain i is greater than maxprice it will update to this
		}
	}
	cout << "\nThe highest price laptop is Serial Number " << maxPriceSerial
		<< " with a price of £" << maxPrice << ".\n";
	return 0;
}
