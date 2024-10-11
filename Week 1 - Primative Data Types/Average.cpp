#include <iostream>

using namespace std;

int main() {
	int total = 0;
	int temp;

	cout << "Enter a number: ";
	cin >> temp;
	total += temp;

	cout << "Enter a number: ";
	cin >> temp;
	total += temp;

	cout << "Enter a number: ";
	cin >> temp;
	total += temp;

	cout << "Enter a number: ";
	cin >> temp;
	total += temp;

	cout << "Your average is " << total / 4;
}