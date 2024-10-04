#include <iostream>

using namespace std;

int main() {
	int health;
	int bullets;
	bool visible;
	int distance = 0.0f;

	cout << "Enter the health of the guard (0-100): ";
	cin >> health;

	cout << "Enter the amount of remaining bullets of the guard (0-100): ";
	cin >> bullets;

	cout << "Enter if the enemy is visible (0 for no, 1 for yes): ";
	cin >> visible;

	cout << "Enter the distance to the enemy: ";
	cin >>  distance;

	if (!visible) {
		if (!bullets) { cout << "Searching for ammo"; }
		else { cout << "Patrolling"; }
	}
	else {
		if (health > 10) {
			cout << "Attack" << endl;
			if (distance > 20 && bullets) { cout << "Firing"; }
			else { cout << "Unarmed Fighting"; }
		}
		else { cout << "Retreating"; }
	}
}