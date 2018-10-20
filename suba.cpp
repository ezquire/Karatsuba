//commit shit
#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

// Function Prototypes
string product(string, string);
string expo(string, string);
string multiply_str(string, string);
string add_str(string, string);
string string_cat(string, string, string);

int main () {

	string a = "999";
	string b = "999";
	//int choice = 0;

	cout << product(a, b) << endl;

	/*cout << "Input an integer less than or equal to 1000 for A: ";
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

		// Multiplier
		int n = x.length();
		
		// Creates strings of trailing 0s that will pad c2 and c1 
		string pad2 = to_string((int)pow(10, n));
		string pad1 = to_string((int)pow(10, n/2));
		pad2 = pad2.substr(1);
		pad1 = pad1.substr(1);

		// W

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
		c1 = add_str( product(x1, y0), product(x0, y1));

		// Pad c2 and c1 with 0s
		c2 += pad2;
		c1 += pad1;
		
		cout << "c0: " << c0 << " | c1: " << c1 << " | c2: " << c2 << endl;
	}
	result = string_cat(c0, c1, c2);
	return result;
}

string string_cat(string c0, string c1, string c2) {
 	//if(c1 == "")
	//	c1 = "0";

	string result;
	string right;
	string middle;
	int addition = 0;

	int c0size = c0.length();
	int c1size = c1.length();
	int c2size = c2.length();

	int minSize = min({c0size, c1size, c2size});

	cout << "smallest string: " << minSize << endl;

	string z1 = c0;
	string z2 = c1.substr(c1.length() - minSize);
	string z3 = c2.substr(c2.length() - minSize);

	//if(c2 == "1000000")
	//	return c2;

	addition = stoi(z1, NULL) + stoi(z2, NULL) + stoi(z3, NULL);
	right = to_string(addition);

	c1.resize(c1.length() - c0.length());
	c2.resize(c2.length() - c0.length());

	z1 = c1;
	z2 = c2.substr(c2.length() - c1.length());

	addition = stoi(z1, NULL) + stoi(z2, NULL);
	middle = to_string(addition);

	c2.resize(c2.length() - c1.length());
			  
	result = c2 + middle + right;
	
	return result;
}

string expo(string a, string b) {
	string v;
	return v;
}
