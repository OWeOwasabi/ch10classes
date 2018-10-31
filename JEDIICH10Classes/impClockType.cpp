#include <iostream>
#include <iomanip>
#include <string>
#include "clockType.h"

using namespace std;

// get around to declaring our class' functions
// we have to use the scope resolution operator so that we can successfully declare it
void clockType::set_time(int hours, int minutes, int seconds) {
	// check and set our hours
	if (0 <= hours && hours < 24) hr = hours; // if hours is between 0-23, then set it...
	else hr = 0; // ...if not, just set it to 0

				 // check and set our minutes
	if (0 <= minutes && minutes < 60) min = minutes; // if minutes is between 0-59, then set it...
	else min = minutes; // ...if not, just set it to 0

						// check and set our seconds
	if (0 <= seconds && seconds < 60) sec = seconds; // if seconds is between 0-59, then set it...
	else sec = seconds; // ...if not, just set it to 0
}

void clockType::print_time() const {
	// print the hour
	if (hr < 10) cout << '0'; // add padding if hour < 10
	cout << hr << ":";
	// print the minutes
	if (min < 10) cout << '0'; // add padding if min < 10
	cout << min << ":";
	// print the seconds
	if (sec < 10) cout << '0'; // add padding if sec < 10
	cout << sec << endl;
}

bool clockType::equal_time(const clockType& otherClock) const { // mark clockType as constant because it's going in by reference
	return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec); // return true if everything is equal
}

void clockType::increment_secs() {
	if (sec + 1 < 60) { // make sure that incrementing seconds doesn't equal 60
		sec++; // increment seconds
		print_time(); // print the new time
	}
	else { // if incrementing seconds does equal 60...
		sec = 0; // set seconds to 0
		increment_mins(); // then increment minutes
	}
}

void clockType::increment_mins() {
	if (min + 1 < 60) { // make sure that incrementing seconds doesn't equal 60
		min++; // increment seconds
		print_time(); // print the new time
	}
	else { // if incrementing seconds does equal 60...
		min = 0; // set seconds to 0
		increment_hours(); // then print the new time
	}
}

void clockType::increment_hours() {
	if (hr + 1 < 24) { // make sure that incrementing seconds doesn't equal 60
		hr++; // increment seconds
		print_time(); // print the new time
	}
	else { // if incrementing seconds does equal 60...
		hr = 0; // set seconds to 0
		print_time(); // then print the new time
	}
}

clockType::clockType(int hours, int minutes, int seconds) { // this is our class' constructor. this one gets called if we're given parameters
															// check and set our hours
	if (0 <= hours && hours < 24) hr = hours; // if hours is between 0-23, then set it...
	else hr = 0; // ...if not, just set it to 0

				 // check and set our minutes
	if (0 <= minutes && minutes < 60) min = minutes; // if minutes is between 0-59, then set it...
	else min = minutes; // ...if not, just set it to 0

						// check and set our seconds
	if (0 <= seconds && seconds < 60) sec = seconds; // if seconds is between 0-59, then set it...
	else sec = seconds; // ...if not, just set it to 0
}

clockType::clockType() { // this is another constructor of our class, but this one gets called if we're not given parameters
	hr = 12;
	min = 0;
	sec = 0;
}