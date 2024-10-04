#include <iostream>

using namespace std;

int main() {
	int num;

	cout << "Enter a number: ";
	cin >> num;

	if (!(num % 3)) { cout << "Fuzz "; }
	if (!(num % 5)) { cout << "Buzz"; }
	if ((num % 3) && (num % 5)) { cout << num; }
}