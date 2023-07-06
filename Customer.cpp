#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int Menu() {
	char userChoice;
	int userChoiceTWO;

	
	//q = 81 - 48 (0 in ascii) = 33
	//Q = 113 - 48 (0 in ascii) = 65

	do {
		try {
			cout << "1. Print all customer's data\n";
			cout << "2. Print names and IDs\n";
			cout << "3. Print accounts total\n";
			cout << "4. Enter q/Q to quit\n";

			cout << "\nEnter your choice, or 'q' to quit: ";
			cin >> userChoice;

			//ASCII to INT
			userChoiceTWO = int(userChoice - '0');

			if (userChoiceTWO != 1 && userChoiceTWO != 2 && userChoiceTWO != 3 && userChoiceTWO != 33 && userChoiceTWO != 65) {
				throw runtime_error("\nWrong input. Try again...");
			}
		}
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl;
			cout << endl;

			//reset input
			cin.clear();
			cin.ignore();
		}
	} while (userChoiceTWO != 1 && userChoiceTWO != 2 && userChoiceTWO != 3 && userChoiceTWO != 33 && userChoiceTWO != 65);
	return userChoiceTWO;
}

void printCustomersData(string data[][5]) {

	cout << setw(20) << left << endl;
	cout << "Last" << setw(20) << left;
	cout << "First" << setw(20) << left;
	cout << "ID" << setw(20) << left;
	cout << "Savings Account" << setw(20) << left;
	cout << "Checking Account" << setw(20) << left << endl;

	for (int i = 0; i < 10; ++i) {
		cout << data[i][2] << setw(20) << left;
		cout << data[i][1] << setw(20) << left;
		cout << data[i][0] << setw(20) << left;
		cout << data[i][3] << setw(20) << left;
		cout << data[i][4] << setw(20) << left << endl;
		}
}

void printNames() {
	//reading from file
	//prevent alteration of orignial info

	string data[10][5];

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
	
	cout << setw(10) << left << endl;
	cout << "First" << setw(10) << left;
	cout << "Last" << setw(10) << left << endl;

	//BUBBLE SORT
		for (int i = 9; i > 0; --i) {
			for (int j = 0; j < i; j++) {
				if (data[j][1] > data[j + 1][1]) {
					swap(data[j][1], data[j + 1][1]);
					swap(data[j][2], data[j + 1][2]);
				}
				else if (data[j][1] == data[j + 1][1]) {
					if (data[j][2] > data[j + 1][2]) {
						swap(data[j][1], data[j + 1][1]);
						swap(data[j][2], data[j + 1][2]);
					}
				}
			}
		}

		//Printing to screen
		int countCustomers = 0;
		for (int i = 0; i < 10; ++i) {
			countCustomers += 1;
		cout << data[i][1] << setw(10) << left;
		cout << data[i][2] << setw(10) << left << endl;
	}

		//Total customers
	cout << endl;
	cout << setfill('*') << setw(32) << "*" << endl;
	cout << "Total Number of Customers is " << countCustomers << endl;
	cout << setfill('*') << setw(32) << "*" << endl;

	//reset fill to space
	cout << setfill(' ');
}

void printBankTotal(string data[][5]) {

	cout << setw(20) << left << endl;
	cout << "Last" << setw(20) << left;
	cout << "First" << setw(20) << left;
	cout << "ID" << setw(20) << left;
	cout << "Savings Account" << setw(20) << left;
	cout << "Checking Account" << setw(20) << left;
	cout << "Total" << setw(20) << left << endl;

	float sum = 0;
	for (int i = 0; i < 10; ++i) {
		float customerTotal = 0;

		//string to float
		customerTotal = stof(data[i][3]) + stof(data[i][4]);
		sum += customerTotal;

		cout << data[i][2] << setw(20) << left;
		cout << data[i][1] << setw(20) << left;
		cout << data[i][0] << setw(20) << left;
		cout << data[i][3] << setw(20) << left;
		cout << data[i][4] << setw(20) << left;
		cout << customerTotal << setw(20) << left << endl;

	}

	//Total Summation
	cout << endl;
	cout << setfill('*') << setw(35) << "*" << endl;
	cout << "Total Bank Total amount is $" << sum << endl;
	cout << setfill('*') << setw(35) << "*" << endl;

	//reset fill to space
	cout << setfill(' ');

}
