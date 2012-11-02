#include <iostream>
#include <sys/time.h>
#include <math.h>

using namespace std;

bool isPrime(long long input) {

	//If the number is divisible by 2 or 3 (and isn't 2 or 3) then it isn't a prime
	if((input % 2 == 0 || input % 3 == 0) && (input != 2 && input != 3)) {
		return false;
	}

	int x = 1;

	//If it's not divisible by 2 or 3, but isn't a prime
	//then it is divisible by (6x +- 1) for some x < sqrt(input)
	while((6 * x + 1) < sqrt(input)) {
		if(input % (6 * x + 1) == 0) {
			return false;
		}
		if(input % (6 * x - 1) == 0) {
			return false;
		}
		x++;
	}

	//If it's not composite, then it must be prime!
	return true;
}

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
	//Check if the input is a prime before factoring?
	//Currently disabled because it increases the length of time
	//to compute the factors
	bool checkPrime = false;

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
	timeval st, et;
	gettimeofday(&st, NULL);
	long long start = (st.tv_usec/1000) + (st.tv_sec * 1000);
	
	//Checks if the number is prime.
	if(checkPrime && isPrime(input)) {
		cout << "The input number is prime!" << endl;
		gettimeofday(&et, NULL);
	  long long end = (et.tv_usec/1000) + (et.tv_sec * 1000);
		cout << "Completed in: " << (end - start) << " milliseconds." << endl;
		cin.get();
		return 1;
	}

	//If 2 integer factors are found, then output them and indicate how long it took to complete
	//Otherwise, inform them that it is a prime number, and exit
	if(factor(input, factor1, factor2) == 0) {
		cout << "Factor 1: " << factor1 << endl;
		cout << "Factor 2: " << factor2 << endl;
		gettimeofday(&et, NULL);
	  long long end = (et.tv_usec/1000) + (et.tv_sec * 1000);
		cout << "Completed in: " << (end - start) << " milliseconds." << endl;
		cin.get();
		return 0;
	} else {
		cout << "No integer factor greater than 1 or equal to itself exists for this input." << endl;
		cin.get();
		return 1;
	}
}
