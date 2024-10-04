#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
	string name;
	int age;
	string country;

	cout << "Enter your name: ";
	cin >> name;

	cout << "Enter your age: ";
	cin >> age;

	cout << "Enter your country of citizenship (e.g. UK or Britain): ";
	cin >> country;
	transform(country.begin(), country.end(), country.begin(), [](unsigned char c) { return std::tolower(c); });

	if (age < 18) { cout << "Sorry " << name << ", but you are too young to vote."; }
	else if (country == "uk" || country == "britain") { cout << "You are entitled to vote " << name << "."; }
	else { cout << "Sorry " << name << ", but you do not have the citizenship to vote."; }
}