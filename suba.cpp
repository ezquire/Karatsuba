#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Function Prototypes
vector<int> split(int);

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

	parseA = split(a);
	parseB = split(b);

	while(choice < 3) {
		cout << "\nEnter 1, 2, or 3\n1) Run Task 1\n2) Run Task 2\n3) Quit\n";
		cin >> choice;
		if(choice == 1) {
			cout << "Running Task 1 with input: " << a << ", " << b;
			cout << endl;
		}
		else if(choice == 2) {
			cout << "Running Task 2 with input: " << a << ", " << b;
			cout << endl;
		}
	}
	
	return 0;
}

vector<int> split(int in) {
	vector<int> out;
	if(in % 2 == 0) {
		
	}
	return out;
}
