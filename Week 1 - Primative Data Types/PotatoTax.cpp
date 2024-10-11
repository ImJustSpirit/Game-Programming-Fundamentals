#include <iostream>

using namespace std;

int main() {
	float price = 0.0f;
	float kgs;
	float tax;
	float total;

	cout << "Enter the price of one kilogram of potatoes before tax: ";
	cin >> price;

	cout << "Enter how many kilograms you wish to buy: ";
	cin >> kgs;

	cout << "Enter the tax percentage: ";
	cin >> tax;

	total = price * kgs;
	total += (total / 100) * tax;

	cout << "You would need to pay " << total << " for " << kgs << "KGs of potatoes.";
}