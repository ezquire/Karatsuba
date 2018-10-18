#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>

using namespace std;

// Function Prototypes
void split(int, vector<int>&);

int main () {

	int a = 0;
	int b = 0;
	int choice = 0;
	vector<int> parseA;
	vector<int> parseB;

	cout << "Input an integer less than or equal to 1000 for A: ";
	cin >> a;
	while(a > 1000) {
		cout << "Error: input should be less than or equal to 1000\n";
		cout << "Enter another value for A: ";
		cin >> a;
	}

	cout << "Input an integer less than or equal to 1000 for B: ";
	cin >> b;
	while(b > 1000) {
		cout << "Error: input should be less than or equal to 1000\n";
		cout << "Enter another value for B: ";
		cin >> b;
	}

	split(a, parseA);
	split(b, parseB);

	while(choice < 3) {
		cout << "\nEnter 1, 2, or 3\n1) Run Task 1\n2) Run Task 2\n3) Quit\n";
		cin >> choice;
		if(choice == 1) {
			cout << "Running Task 1 with input: " << a << ", " << b << endl;;
			for(unsigned int i = 0; i < parseA.size(); ++i)
				cout << parseA[i] << " ";
			cout << endl;
			for(unsigned int i = 0; i < parseB.size(); ++i)
				cout << parseA[i] << " ";
			cout << endl;
		}
		else if(choice == 2) {
			cout << "Running Task 2 with input: " << a << ", " << b << endl;;
			cout << endl;
		}
	}
	
	return 0;
}

void split(int in, vector<int>& parse) {
	if(in == 1000) { // This handles the special case when A or B are 1000
		parse.push_back(10);
		parse.push_back(00);
	}
	int digits = ceil(log10((double) in));
	switch(digits) {
	case 0: // This handles the case when the input is 1
		parse.push_back(in);
		break;
	case 1: // This handles all single digit numbers
		parse.push_back(in);
		break;
	default: // This handles all 2 and 3 digit numbers
		parse.push_back(in/10);
		parse.push_back(in%10);
		break;
	}
}
