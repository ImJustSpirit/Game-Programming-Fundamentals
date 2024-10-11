#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main() {
	srand(time(NULL));
	string wipe = "\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A";

	char wall = '#';
	char unknown = '?';
	char path = '|';
	char player = '@';

	char masterMaze[16][32]; // Entire Maze
	char playerMaze[16][32]; // Viewed Maze
	int playerLocation[2];   // Stores Player Location
	int currentLocation[2];  // Stores Current Location of Maze Generator

	bool exit = false;

	// Set master maze to walls on first boot
	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 32; x++) {
			masterMaze[y][x] = wall;
		}
	}

	// Set player maze to unknown on first boot
	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 32; x++) {
			playerMaze[y][x] = unknown;
		}
	}

	// Set initial player location
	playerLocation[0] = 8;
	playerLocation[1] = 16;
	currentLocation[0] = playerLocation[0];
	currentLocation[1] = playerLocation[1];

	// Make paths
	while ((currentLocation[0] > -1) && (currentLocation[0] < 16) && (currentLocation[1] > -1) && (currentLocation[1] < 32)) {
		masterMaze[currentLocation[0]][currentLocation[1]] = path;
		switch (rand() % 4) {
		case 0: // North
			currentLocation[0]--;
			break;
		case 1: // East
			currentLocation[1]++;
			break;
		case 2: // South
			currentLocation[0]++;
			break;
		case 3: // West
			currentLocation[1]--;
			break;
		}
	}
	
	while (true) {
		// Reveal maze
		playerMaze[playerLocation[0] - 1][playerLocation[1]] = masterMaze[playerLocation[0] - 1][playerLocation[1]];
		playerMaze[playerLocation[0]][playerLocation[1] - 1] = masterMaze[playerLocation[0]][playerLocation[1] - 1];
		playerMaze[playerLocation[0]][playerLocation[1]] = masterMaze[playerLocation[0]][playerLocation[1]];
		playerMaze[playerLocation[0] + 1][playerLocation[1]] = masterMaze[playerLocation[0] + 1][playerLocation[1]];
		playerMaze[playerLocation[0]][playerLocation[1] + 1] = masterMaze[playerLocation[0]][playerLocation[1] + 1];

		cout << wipe;

		// Print print maze
		for (int y = 0; y < 16; y++) {
			for (int x = 0; x < 32; x++) {
				if ((y == playerLocation[0]) && (x == playerLocation[1])) { cout << player; }
				else { cout << playerMaze[y][x]; }
			}
			cout << endl;
		}

		cout << "  W\nA   S\n  D" << endl;

		char direction = _getch();

		switch (direction) {
		case 'w': // North
			if (playerLocation[0] - 1 == -1) { exit = true; }
			else if (!(masterMaze[playerLocation[0] - 1][playerLocation[1]] == '#')) { playerLocation[0]--; }
			break;
		case 'd': // East
			if (playerLocation[1] + 1 == 32) { exit = true; }
			else if (!(masterMaze[playerLocation[0]][playerLocation[1] + 1] == '#')) { playerLocation[1]++; }
			break;
		case 's': // South
			if (playerLocation[0] + 1 == 16) { exit = true; }
			else if (!(masterMaze[playerLocation[0] + 1][playerLocation[1]] == '#')) { playerLocation[0]++; }
			break;
		case 'a': // West
			if (playerLocation[1] - 1 == -1) { exit = true; }
			else if (!(masterMaze[playerLocation[0]][playerLocation[1] - 1] == '#')) { playerLocation[1]--; }
			break;
		}

	if (exit) { break; }

	}
}