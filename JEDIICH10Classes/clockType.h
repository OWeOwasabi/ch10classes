#pragma once

class clockType {
private:
	int hr;
	int min;
	int sec;

	char timeOfDay = ' ';

	bool is12hr = false;

public:
	// these are our class constructors
	// normally in c++ they go on the bottom?
	// but i like python so they'll go up top
	clockType(int, int, int); // this one gets called if we're given paramaters
	// post condition: hr = hours, min = minutes, sec = second. if a value isn't in range, it's set to 0
	clockType(); // this one gets called if we're not given parameters
	// post condition: hr = hours, min = minutes, sec = second. sets the default values for a clock

	// you need both set and get functions
	// you don't want to give names to the variables because these are classes, we need them to be generic
	void set_time(int, int, int); // sets the time
	// time is set according to parameters
	// post condition: hr = hrs, min = minutes, sec = seconds
	// checks all of those values to see if they're valid, and if not then it's set to 0
	void print_time() const; // prints the time
	// post condition: the time is printed in the form HH:mm:ss

	// our increment functions increment the time and then display the new one
	void increment_hours(); // increments hrs by 1
	// post condition: hours + 1, but doesn't go higher than 23 (inclusive) or else it resets to 0
	void increment_mins(); // increments min by 1
	// post condition: minutes + 1, but doesn't go higher than 59 (inclusive) or else it resets to 0
	void increment_secs(); // incremnets sec by 1
	// post condition: sec + 1, but doesn't go higher than 59 (inclusive) or else it resets to 0

	// this function checks to see if the clock that's passed to it is the same as it's own clock
	bool equal_time(const clockType&) const; // mark clockType as constant because it's going in by reference
	// post condition: true if they are equal, false otherwise

	int elapsed_time(); // shows how much time has already been elapsed in seconds
	// post condition: the number of seconds elapsed that day
	int remaining_time(); // shows how much time the day has left in seconds
	// post condition: the number of seconds the day has left

	void military_to_12(); // converts the current clock format to 12-hr format
	// post condition: hr cannot be greater than 12 or equal to 0, and an am-pm format is assigned
	void twelve_to_military(); // converts the current clock format to military format
	// post condition: hr can range from 0-24, and the am-pm format becomes unneccessary
};