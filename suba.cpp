/*
 * suba.cpp
 * Implementation of the Karatsuba algorithm for multiplication and 
 * exponentiation
 */

/*
  MIT License
  Copyright (c) 2018 Tyler Gearing, Mei Williams
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctype.h>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// Function Prototypes
string product(string, string);
string expo(const string&, const string&);
const string multiply_str(const string&, const string&);
const string string_add_large(string, string);
void get_input(string&, string&);
void run_karatsuba(int&);

int main () {
	int choice = 0;
	run_karatsuba(choice);
	return 0;
}

void run_karatsuba(int& choice) {
		string a = "";
		string b = "";
		while(choice < 3) {
		cout << "\nEnter 1, 2, or 3\n1) Multiplication\n2) Exponentiation\n3)";
		cout << " Quit\n";
		cin >> choice;
		switch(choice) {
		case 1:
			get_input(a, b);
			cout << "\nPerforming multiplication with input: " << a << ", ";
			cout << b << endl;
			cout << a << "x" << b << " = " << product(a, b) << endl;
			break;
		case 2:
			get_input(a, b);
			cout << "\nPerforming exponentiation with input: " << a << ", ";
			cout << b << endl;;
			cout << a << "^" << b << " = " << expo(a, b) << endl;
			break;
		default :
			break;
		}
	}
}

void get_input(string& a, string& b) {
	cout << "\nInput an integer less than or equal to 1000 for A: ";
	cin >> a;
	while(stoi(a, NULL) > 1000 || stoi(a, NULL) < 0) {
		cout << "Error: input should be in the range [0-1000]\n";
		cout << "Enter another value for A: ";
		cin >> a;
	}
	cout << "Input an integer less than or equal to 1000 for B: ";
	cin >> b;
	while(stoi(b, NULL) > 1000 || stoi(b, NULL) < 0) {
		cout << "Error: input should be in the range [0-1000]\n";
		cout << "Enter another value for B: ";
		cin >> b;
	}
}

const string multiply_str(const string& x, const string& y) {
	int product = ((x[0] - '0') * (y[0] - '0'));
	return to_string(product);
}

string product(string x, string y) {

	string result;
	string c2;
	string c0;
	string c1;
	
	if(x.length() < 2 && y.length() < 2) {
		result = multiply_str(x, y);
		return result;
	}
 	else {
		// Pad x and y with leading 0s to make them an even number of digits
		if(x.length()%2 != 0)
			x = '0' + x;
		if(y.length()%2 != 0)
			y = '0' + y;
		// Pad the smaller value with leading 0s to make it the same length
		if(x.length() < y.length()) {
			string a ((y.length() - x.length()), '0');
			x = a + x;
		}
		else if(y.length() < x.length()) {
			string b ((x.length() - y.length()), '0');
			y = b + y;
		}
		// Multiplier
		int n = x.length();

		// Create strings of 0s that will be appended to c2 and c1
		string pad2 (n, '0');
		string pad1 (n/2, '0');		

		// Split the padded strings x and y into to halves
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

		// Append 0s to c2 and c1
		c2 += pad2;
		c1 += pad1;
	}
	// Add the strings together for the final result
	result = string_add_large(c0, c1);
	result = string_add_large(result, c2);
	return result;
}

const string string_add_large(string x, string y) {
	string result = "";
	
	// Swap strings in memory so the larger is second
	if(x.length() > y.length())
	  x.swap(y);

	// Find the lengths of both strings
	int xLength = x.length();
	int yLength = y.length();

	// Need to reverse them so the rightmost digits are in the leftmost indices
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	int carry = 0;

	for(int i = 0; i < xLength; ++i) {
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

string expo(const string& a, const string& n) {
	long nInt = stol(n, NULL);
	string nOdd = to_string((nInt - 1)/2);
	string nEven = to_string(nInt/2);
	if(nInt< 0) {
		cout << "Error: n must be positive";
		exit(1);
	}
	else {
		// Base cases
		if(nInt == 0)
			return "1";
		if(nInt == 1)
			return a;		
		// n is odd
		if(nInt%2 != 0)
			return product(a, product(expo(a, nOdd), expo(a, nOdd))); 
		// n is even
		else
			return product(expo(a, nEven), expo(a, nEven)); 
	}
}
