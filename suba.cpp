#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

// Function Prototypes
vector<char> product(vector<char>, vector<char>, int);
int numDigits(int);

int main () {

	string a;
	string b;
	int choice = 0;

	cout << "Input an integer less than or equal to 1000 for A: ";
	cin >> a;
	while(stoi(a, NULL) > 1000) {
		cout << "Error: input should be less than or equal to 1000\n";
		cout << "Enter another value for A: ";
		cin >> a;
	}

	cout << "Input an integer less than or equal to 1000 for B: ";
	cin >> b;
	while(stoi(b, NULL) > 1000) {
		cout << "Error: input should be less than or equal to 1000\n";
		cout << "Enter another value for B: ";
		cin >> b;
	}

	while(choice < 3) {
		cout << "\nEnter 1, 2, or 3\n1) Run Task 1 - Multiplication\n2) Run Task 2 - Exponentiation\n3) Quit\n";
		cin >> choice;
		if(choice == 1) {
			cout << "Running Task 1 with input: " << a << ", " << b << endl;;
			//long long prod = product(a, b, 10);
			cout << endl;
		}
		else if(choice == 2) {
			cout << "Running Task 2 with input: " << a << ", " << b << endl;;
			cout << endl;
		}
	}
	
	return 0;
}

int numDigits(int in) {
	int digits = 0;
	while (in != 0) {
		in /= 10;
		digits++;
	}
	return digits;
}

long long product(int x, int y, int base) {
	int xdigits = numDigits(x);
	int ydigits = numDigits(y);

	int n = (int)max(xdigits, ydigits);

	// Base case: One of the numbers is a single digit, in this case direct
	// multiplication is faster.
	if(n < 2)
		return x*y;

	n  = (n/2) + (n%2); // divide and round

	long long mult = pow(base, n);
	long long x1 = x/mult;
	long long x0 = x%mult;
	long long y1 = y/mult;
	long long y0 = y%mult;

	long long c2 = product(x1, y1, base);
	long long c0 = product(x0, y0, base);
	long long c1 = product((x1 + x0), (y1 + y0), base);
		
	return ((c2*pow(base, 2*n)) + ((c1 - c0 -c2)*mult) + c0);
}

