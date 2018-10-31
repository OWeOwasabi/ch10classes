#pragma once

class clockType {
private:
	int hr;
	int min;
	int sec;

public:
	// these are our class constructors
	// normally in c++ they go on the bottom?
	// but i like python so they'll go up top
	clockType(int, int, int); // this one gets called if we're given paramaters
	clockType();

	// you need both set and get functions
	// you don't want to give names to the variables because these are classes, we need them to be generic
	void set_time(int, int, int); // sets the time
	// time is set according to parameters
	// postcondition: hr = hrs, min = minutes, sec = seconds
	// checks all of those values to see if they're valid, and if not then it's set to 0
	void get_time(int, int, int); // gets the time
	void print_time() const; // prints the time

	// our increment functions increment the time and then display the new one
	void increment_hours();
	void increment_mins();
	void increment_secs();

	// this function checks to see if the clock that's passed to it is the same as it's own clock
	bool equal_time(const clockType&) const; // mark clockType as constant because it's going in by reference
};