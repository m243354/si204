#ifndef GEORGEBOARD
#define GEORGEBOARD
#include "Point.h"
#include <fstream>
#include <iostream>

using namespace std;


struct Board {
  int height, width, maxSpawn, wallCount;
  point* spawnList;
  point** bArr;
  point playerSpawn;
  point goalSpawn;
};

//reads a board file and returns a board object
Board readFile(ifstream& f);

//print the board
void printBoard(Board b);
//returns true if the point is near the goal
bool isGoal(Board b, point p);

#endif
