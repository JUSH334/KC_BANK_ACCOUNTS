#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Customer.h"

using namespace std;

int main()
{
	//constant row value
	int const rows = 10;

	//reading from file
	string data[rows][5];

	ifstream customerData;

	//code for checking for successful opening
	/*if (customerData.fail()) {
		cout << -1;
	}
	else {
		cout << "successful opening";
	}*/

	customerData.open("input.txt");
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 5; ++j)
		{
			customerData >> data[i][j];
		}
	}
	customerData.close();

	bool run = true;
	while (run == true) {

		cout << endl;
		int choice = Menu();
		switch (choice) {
		case 1:
			printCustomersData(data);
			break;
		case 2:
			//prevent alteration of orignial information
			printNames();
			break;
		case 3:
			printBankTotal(data);
			break;
		case 33:
		case 65:
			cout << "\nThanks for using my program. Goodbye!!" << endl;
			run = false;
			break;
		default:
			cout << endl;
			cout << "Invalid entry. Please try again.";
			cout << endl;
		}
	}

   return 0;
}
