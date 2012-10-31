#include <iostream>
#include <windows.h>

using namespace std;

int factor(long long input, long long& factor1, long long& factor2) {
	
	//If a number is factorable by an even number, it is factorable by 2,
	//so no need to waste cycles checking for even factors > 2.
	if(input % 2 == 0) {
		factor1 = 2;
		factor2 = input / 2;
		return 0;
	}
	
	//Only checks if odd numbers factor it
	int x = 3;
	do {
		if(input % x == 0) {
			factor1 = x;
			factor2 = input / x;
			return 0;
		}
		x+= 2;
	}
	while(x <= input / 2);
	return 1;
}

int main() {
	//Using long long allows for 64 bit integers
	long long input, factor1, factor2;

	//Prompts the user for input
	cout << "Please enter the positive integer you wish to factor: ";
	cin >> input;

	//Verifies that the input is valid.
	if(input <= 0) {
		cout << "Only positive integers are valid. (Or your value is too high)" << endl;
		return 0;
	}

	//Gets the System Time on Windows computers.
	//Used to time how long it takes to complete.
	SYSTEMTIME st, et;
	GetSystemTime(&st);
	long long start = st.wMilliseconds + st.wSecond * 1000 + st.wMinute * 60000 + st.wHour * 3600000;

	//If 2 integer factors are found, then output them and indicate how long it took to complete
	//Otherwise, inform them that it is a prime number, and exit
	if(factor(input, factor1, factor2) == 0) {
		cout << "Factor 1: " << factor1 << endl;
		cout << "Factor 2: " << factor2 << endl;
		GetSystemTime(&et);
		long long end = et.wMilliseconds + et.wSecond * 1000 + et.wMinute * 60000 + et.wHour * 3600000;
		cout << "Completed in: " << (end - start) << " milliseconds." << endl;
		cin.get();
		return 0;
	} else {
		cout << "No integer factor greater than 1 or equal to itself exists for this input." << endl;
		cin.get();
		return 1;
	}
}
