/*
	Start shape drawing file
*/

#include <iostream>
#include "Framework.h"
#include <vector>

// Variables with global scope - do not rename them, feel free to change values though

// Screen dimensions
int gScreenWidth{ 800 };
int gScreenHeight{ 600 };

// Delay to slow things down
int gTimeDelayMS{ 1 };

using namespace std;

int main()
{
	srand(time(NULL));

	struct Circles {
		int x;
		int y;
		bool xDir;
		bool yDir;
		int colour[3];
	};

	vector<Circles> circlesVector;
	Circles ball;

	ball.x = rand() % gScreenWidth;
	ball.y = rand() % gScreenHeight;

	if (rand() % 2 == 1) { ball.xDir = true; }
	else { ball.xDir = false; }

	if (rand() % 2 == 1) { ball.yDir = true; }
	else { ball.yDir = false; }

	circlesVector.push_back(ball);

	while (UpdateFramework())
	{
		for (int i = 0; i < circlesVector.size(); i++) {
			DrawCircle(circlesVector[i].x, circlesVector[i].y, 20);

			if (!circlesVector[i].xDir) {
				circlesVector[i].x++;
				if (circlesVector[i].x >= gScreenWidth - 40) { 
					circlesVector[i].xDir = true;

					Circles ball;
					ball.x = rand() % gScreenWidth;
					ball.y = rand() % gScreenHeight;
					if (rand() % 2 == 1) { ball.xDir = true; }
					else { ball.xDir = false; }
					if (rand() % 2 == 1) { ball.yDir = true; }
					else { ball.yDir = false; }
					circlesVector.push_back(ball);
				}
			}
			else {
				circlesVector[i].x--;
				if (circlesVector[i].x <= 0) { 
					circlesVector[i].xDir = false;

					Circles ball;
					ball.x = rand() % gScreenWidth;
					ball.y = rand() % gScreenHeight;
					if (rand() % 2 == 1) { ball.xDir = true; }
					else { ball.xDir = false; }
					if (rand() % 2 == 1) { ball.yDir = true; }
					else { ball.yDir = false; }
					circlesVector.push_back(ball);
				}
			}

			if (!circlesVector[i].yDir) {
				circlesVector[i].y++;
				if (circlesVector[i].y >= gScreenHeight - 40) { 
					circlesVector[i].yDir = true;

					Circles ball;
					ball.x = rand() % gScreenWidth;
					ball.y = rand() % gScreenHeight;
					if (rand() % 2 == 1) { ball.xDir = true; }
					else { ball.xDir = false; }
					if (rand() % 2 == 1) { ball.yDir = true; }
					else { ball.yDir = false; }
					circlesVector.push_back(ball);
				}
			}
			else {
				circlesVector[i].y--;
				if (circlesVector[i].y <= 0) { 
					circlesVector[i].yDir = false;

					Circles ball;
					ball.x = rand() % gScreenWidth;
					ball.y = rand() % gScreenHeight;
					if (rand() % 2 == 1) { ball.xDir = true; }
					else { ball.xDir = false; }
					if (rand() % 2 == 1) { ball.yDir = true; }
					else { ball.yDir = false; }
					circlesVector.push_back(ball);
				}
			}
		}
	}
	return 0;
}
