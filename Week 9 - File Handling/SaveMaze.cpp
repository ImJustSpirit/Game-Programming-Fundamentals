/*
	GPF Week 6 - Maze Start Code
*/

#include <iostream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include "Framework.h"
using namespace std;

// Delay to slow things down
int gTimeDelayMS{ 100 };

// Maze size as constants
constexpr int kMazeColumnsX{ 20 };
constexpr int kMazeRowsY{ 20 };

// How big the rectangles are
const int gridSizing{ 20 };

// Screen dimensions
int gScreenWidth{ kMazeColumnsX * gridSizing };
int gScreenHeight{ kMazeRowsY * gridSizing };

int playerLocation[2]{ 18, 1 };
int goalLocation[2]{ 1, 16 };

float laps = 0.0f;

/*
	2 Dimensional Arrays
	You can think of these as being an array of arrays

	The maze has kMazeColumnsX columns across (20 by default) represented by an array
	We then have kMazeRowsY (20) of these arrays, one for each row

	Columns and rows can be confusing so you can prefer working with x and y
	where x is the horizontal axis (columns) across and y is the vertical axis (rows) down.

	Each single array entry is called a cell.

	E.g. to output the value of the cell at 16 X (column 16) and 1 Y (row 1) we would write:
	cout << map[1][16] << endl; // outputs G
*/

char map[kMazeRowsY][kMazeColumnsX] = {
	// 20 columns across (x axis) by 20 rows down (y axis)
	// X0   X1   X2   X3   X4   X5   X6   X7   X8   X9   X10  X11  X12  X13  X14  X15  X16  X17  X18  X19 
	{ 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W' },	//Y0
	{ 'W', '.', '.', '.', '.', 'W', '.', '.', '.', 'W', 'W', '.', '.', '.', '.', 'W', '.', '.', '.', 'W' },	//Y1
	{ 'W', '.', 'W', 'W', 'W', 'W', 'W', 'W', '.', 'W', '.', '.', 'W', 'W', 'W', 'W', 'W', 'W', '.', 'W' },	//Y2
	{ 'W', '.', 'W', '.', '.', '.', 'W', '.', '.', 'W', '.', 'W', 'W', '.', 'W', '.', '.', '.', '.', 'W' },	//Y3
	{ 'W', '.', 'W', '.', 'W', '.', 'W', '.', 'W', 'W', '.', 'W', 'W', '.', 'W', 'W', 'W', '.', 'W', 'W' },	//Y4
	{ 'W', '.', 'W', '.', 'W', '.', '.', '.', '.', '.', '.', '.', 'W', '.', 'W', '.', '.', '.', '.', 'W' },	//Y5
	{ 'W', '.', 'W', '.', 'W', 'W', 'W', '.', '.', 'W', 'W', '.', 'W', '.', 'W', '.', 'W', '.', '.', 'W' },	//Y6
	{ 'W', '.', 'W', '.', 'W', '.', 'W', 'W', 'W', 'W', 'W', '.', 'W', '.', 'W', '.', 'W', 'W', 'W', 'W' },	//Y7
	{ 'W', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'W', '.', '.', '.', 'W', '.', '.', '.', '.', 'W' },	//Y8
	{ 'W', '.', 'W', '.', 'W', '.', 'W', 'W', '.', 'W', 'W', 'W', '.', 'W', 'W', 'W', 'W', '.', 'W', 'W' },	//Y9
	{ 'W', '.', 'W', 'W', 'W', 'W', 'W', 'W', '.', 'W', 'W', 'W', '.', 'W', '.', 'W', 'W', '.', 'W', 'W' },	//Y10
	{ 'W', '.', '.', '.', '.', 'W', '.', '.', '.', 'W', 'W', '.', '.', '.', '.', 'W', '.', '.', '.', 'W' },	//Y11
	{ 'W', '.', 'W', 'W', 'W', 'W', 'W', 'W', '.', '.', '.', '.', 'W', '.', 'W', 'W', 'W', 'W', '.', 'W' },	//Y12
	{ 'W', '.', 'W', '.', '.', '.', 'W', '.', '.', 'W', 'W', '.', 'W', '.', 'W', '.', '.', '.', '.', 'W' },	//Y13
	{ 'W', '.', 'W', '.', 'W', '.', 'W', '.', 'W', 'W', 'W', '.', 'W', '.', 'W', '.', 'W', 'W', 'W', 'W' },	//Y14
	{ 'W', '.', 'W', '.', 'W', '.', '.', '.', '.', '.', 'W', '.', 'W', '.', 'W', '.', '.', '.', 'W', 'W' },	//Y15
	{ 'W', '.', 'W', '.', 'W', 'W', 'W', '.', '.', 'W', 'W', '.', 'W', '.', '.', '.', 'W', '.', '.', 'W' },	//Y16
	{ 'W', '.', 'W', '.', 'W', '.', 'W', 'W', 'W', 'W', '.', '.', 'W', 'W', 'W', '.', 'W', 'W', '.', 'W' },	//Y17
	{ 'W', '.', '.', '.', '.', '.', '.', '.', '.', 'W', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'W' },	//Y18
	{ 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W' },	//Y19
};

void DrawMaze() {
	for (int y = 0; y < kMazeRowsY; y++) {
		for (int x = 0; x < kMazeColumnsX; x++) {
			switch (map[y][x]) {
			case '.':
				ChangeColour(255, 255, 255);
				DrawRectangle(x * gridSizing, y * gridSizing, gridSizing, gridSizing);
				break;
			case 'W':
				ChangeColour(0, 0, 0);
				DrawRectangle(x * gridSizing, y * gridSizing, gridSizing, gridSizing);
				break;
			}
		}
	}
	// Draw Goal
	ChangeColour(255, 0, 0);
	DrawRectangle(goalLocation[1] * gridSizing, goalLocation[0] * gridSizing, gridSizing, gridSizing);

	// Draw Player
	ChangeColour(0, 0, 255);
	DrawRectangle(playerLocation[1] * gridSizing, playerLocation[0] * gridSizing, gridSizing, gridSizing);

}

void ReachExit() {
	srand(time(NULL));

	cout << "You reached the exit in " << GetElapsedTime() - laps << endl;
	laps = GetElapsedTime();

	while (true) {
		int tempValueA = rand() % 20;
		int tempValueB = rand() % 20;
		if (map[tempValueA][tempValueB] == '.') {
			goalLocation[0] = tempValueA;
			goalLocation[1] = tempValueB;
			cout << "Goal Moved" << endl;
			break;
		}
	}
}

void saveMaze() {
	string fileName;
	cout << "Enter maze name: ";
	cin >> fileName;
	ofstream saveMaze(fileName);
	for (int y = 0; y < kMazeRowsY; y++) {
		for (int x = 0; x < kMazeColumnsX; x++) {
			saveMaze << map[y][x] << " ";
		}
		saveMaze << "\n";
	}
	saveMaze.close();
}

int main()
{
	ofstream saveFile("SaveGame.txt"); saveFile.close();
	ifstream loadFile("SaveGame.txt"); loadFile.close();
	StartClock();
	while (UpdateFramework())
	{
		DrawMaze();
		switch (GetLastKeyPressed()) {
		case EKeyPressed::eUp:
			if (playerLocation[0] - 1 == goalLocation[0] && playerLocation[1] == goalLocation[1]) { playerLocation[0]--; ReachExit(); }
			else if (map[playerLocation[0] - 1][playerLocation[1]] == '.') { playerLocation[0]--; }
			break;
		case EKeyPressed::eDown:
			if (playerLocation[0] + 1 == goalLocation[0] && playerLocation[1] == goalLocation[1]) { playerLocation[0]++; ReachExit(); }
			else if (map[playerLocation[0] + 1][playerLocation[1]] == '.') { playerLocation[0]++; }
			break;
		case EKeyPressed::eLeft:
			if (playerLocation[0] == goalLocation[0] && playerLocation[1] - 1 == goalLocation[1]) { playerLocation[1]--; ReachExit(); }
			else if (map[playerLocation[0]][playerLocation[1] - 1] == '.') { playerLocation[1]--; }
			break;
		case EKeyPressed::eRight:
			if (playerLocation[0] == goalLocation[0] && playerLocation[1] + 1 == goalLocation[1]) { playerLocation[1]++; ReachExit(); }
			else if (map[playerLocation[0]][playerLocation[1] + 1] == '.') { playerLocation[1]++; }
			break;
		case EKeyPressed::eSave:
			saveFile.open("SaveGame.txt");
			saveFile << playerLocation[0] << " " << playerLocation[1];
			saveFile.close();
			saveMaze();
			break;
		case EKeyPressed::eLoad:
			loadFile.open("SaveGame.txt");
			loadFile >> playerLocation[0] >> playerLocation[1];
			loadFile.close();
			break;
		}
	}

	saveFile.close();
	return 0;
}