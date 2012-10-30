#include <iostream>
#include <windows.h>

using namespace std;

int factor(long long input, long long& factor1, long long& factor2) {
	int x = 2;
	while(x <= input / 2) {
		if(input % x == 0) {
			factor1 = x;
			factor2 = input / x;
			return 0;
		}
		x++;
	}
	return 1;
}

int main() {
	long long input, factor1, factor2;
	cout << "Please enter the positive integer you wish to factor: ";
	cin >> input;
	//cout << input << endl;
	if(input < 0) {
		cout << "Negative numbers are not valid." << endl;
		return 0;
	}
	SYSTEMTIME st, et;
	GetSystemTime(&st);
	long long start = st.wMilliseconds + st.wSecond * 1000 + st.wMinute * 60000 + st.wHour * 3600000;
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
