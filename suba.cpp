#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// Function Prototypes
string product(string, string);
string expo(string, int);
string multiply_str(string, string);
string add_str(string, string);
string string_add_large(string, string);

int main () {

	string a1 = "10000000";
	string b1 = "10000000";
	string a = "100000000";
	string b = "100000000";

	//int choice = 0;
	//cout << expo(a, 2) << endl;

	cout << "a1: " << a << " b1: " << b << endl;
	cout << "expected output: 100000000000000" << endl;
	cout << "  actual output: " << product(a1, b1) << endl;
	//int choice = 0;
	//cout << expo(a, 2) << endl;

	cout << "a: " << a << " b: " << b << endl;
	cout << "expected output: 10000000000000000" << endl;
	cout << "  actual output: " << product(a, b) << endl;

	/*
	  User interface removed for testing purposes
	  
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
			cout << "product: " << product(a, b) << endl;
			cout << endl;
		}
		else if(choice == 2) {
			cout << "Running Task 2 with input: " << a << ", " << b << endl;;
			cout << endl;
		}
		}*/
	return 0;
}

string multiply_str(string x, string y) {
	int product = (stoi(x, NULL) * stoi(y, NULL));
	return to_string(product);
}

string add_str(string x, string y) {
	int sum = (stoi(x, NULL) + stoi(y, NULL));
	return to_string(sum);
	
}

string product(string x, string y) {

	string result;
	string c2;
	string c0;
	string c1;
	long n = 0;
	
	if(x.length() < 2 && y.length() < 2) {
		result = multiply_str(x, y);
		return result;
	}
 	else {

		// Pads x and y with leading 0s to make them an even number of digits
		// (We need to think about this more, in the case: 4 digits X 2 digits)
			
		if(x.length()%2 != 0) {
			x = "0" + x;
		}
		if(y.length()%2 != 0) {
			y = "0" + y;
		}

		if(x.length() < y.length()) {
			string a ((y.length() - x.length()), '0');
			x = a + x;
		}
		else if(y.length() < x.length()) {
			string b ((x.length() - y.length()), '0');
			y = b + y;
		}
		// Multiplier
		n = x.length();
		
		// Creates strings of trailing 0s that will pad c2 and c1 
		string pad2 = to_string((int)pow(10, n));
		string pad1 = to_string((int)pow(10, n/2));
		pad2 = pad2.substr(1);
		pad1 = pad1.substr(1);

		// Splits the padded strings x and y into to halves
		int half = x.length()/2;
		string x1 = x.substr(0, half);
		string x0 = x.substr(half);
		half = y.length()/2;
		string y1 = y.substr(0, half);
		string y0 = y.substr(half);	

		// Recursively call product to produce c2, c1, and c0
		c2 = product(x1, y1);
		c0 = product(x0, y0);
		
		c1 = string_add_large(product(x1, y0), product(x0, y1));
		//c1 = add_str(product(x1, y0), product(x0, y1));

		// Pad c2 and c1 with 0s
		c2 += pad2;
		c1 += pad1;
	}
	result = string_add_large(c0, c1);
	result = string_add_large(result, c2);
	return result;
}

string string_add_large(string x, string y) {
	
	string result = "";
	
	// Swap strings in memory so the larger is second
	if(x.length() > y.length())
	  x.swap(y);

	int xLength = x.length();
	int yLength = y.length();

	// Need to reverse them so the rightmost digits are in the leftmost indices
	// This can probably be done better
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	int carry = 0;

	for(int i = 0 ; i < xLength; ++i) {
		int sum = ((x[i] - '0') + (y[i] - '0') + carry); // Convert and add
		result.push_back(sum%10 + '0'); // Convert back to string and push
		carry = sum/10; // Carry for the next step (grade school method)
	}

	// Add carries to the remaining digits of the larger number
	for(int i = xLength; i < yLength; ++i) {
		int sum = ((y[i] - '0') + carry); // Convert and add
		result.push_back(sum%10 + '0'); // Covert back to string and push
		carry = sum/10;
	}

	// If there is a remaining carry, convert to string and push
	if(carry)
		result.push_back(carry + '0');

	// Reverse result
	reverse(result.begin(), result.end());

	// Remove leading 0s
	result.erase(0, min(result.find_first_not_of('0'), result.size()-1));

	return result;
}

string expo(string a, int n) { 
	if(n < 0) {
		cout << "Error: n must be positive";
		exit(1);
	}
	else {
		// Base cases
		if(n == 0)
			return "1";
		if(n == 1)
			return a;		
		// n is odd
		if(n%2 != 0)
			return product(a, product(expo(a, (n-1)/2), expo(a, (n-1)/2))); 
		// n is even
		else
			return product(expo(a, n/2), expo(a, n/2)); 
	}
}
