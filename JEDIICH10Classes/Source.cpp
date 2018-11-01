// jedii and logan 10 29 18
// a program for enhanced classes

#include <iostream>
#include <iomanip>
#include <string>
#include "clockType.h"

using namespace std;

int main() {
	// prompt the user for what time it is
	int hrs, min, sec; // create our variables for storing user input
	cout << "Hey, what time is it in military format?" << endl;
	cout << "Hours: ";
	cin >> hrs;
	cout << "Minutes: ";
	cin >> min;
	cout << "Seconds: ";
	cin >> sec;

	clockType userClock(hrs, min, sec); // create a clock type based off of the user's inputs

	// demonstrate the elapsed_time() function
	cout << "Thank you. This is how much time has been elapsed in the day in seconds: " << userClock.elapsed_time() << endl; 
	// demonstrate the remaining_time() function
	cout << "This is how much time there is left in the day: " << userClock.remaining_time() << endl;


	system("pause");
	return 0;
}
