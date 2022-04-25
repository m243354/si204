#include "easycurses.h"
#include "Pos.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <unistd.h>

// submit ~/bin/submit -c=SI204 -p=proj03 Makefile part1.cpp Node.cpp Pos.cpp easycurses.cpp easycurses.h Node.h Pos.h board2Rm.txt boardCenter.txt boardMaze.txt boardTiny.txt

using namespace std;



struct point {
  char cVal;
  int x, y, dir;
};

struct Spawn {
  point p;
  string name;
};

struct Board {
  int height, width, maxSpawn;
  Node* bList;
  point* spawnList;
  point playerSpawn;
  point goalSpawn;
};


void drawPoints(point* p, int n) {
  for(int i=0; i<n; i++) {
    drawChar(p[i].cVal, p[i].x, p[i].y);
  }
}

void delPoints(point* p, int n) {
  for(int i=0; i<n; i++) {
    drawChar(' ', p[i].x, p[i].y);
  }
}

Board readFile(ifstream& f) {
  char c;
  Board b;
  b.bList = new Node;
  f >> b.height >> c >> b.width >> b.maxSpawn;
  int x = 0, y = 0, spCount = 0;
  //add 2 to spawnlist because it is the amt of Z spawns plus the goal spawns
  b.spawnList = new point[b.maxSpawn];
  while(f.get(c)) {
    addNode(b.bList, c);
    if(c == 'Z') {
      //somewhere this flip may be a problem
      b.spawnList[spCount].x = y-1;
      b.spawnList[spCount].y = x-1;
      spCount++;
      //add x and y dadat
    }
    if(c == 'X') {
      b.goalSpawn.x = y-1;
      b.goalSpawn.y = x-1;
      //add x and y dadat
    }
    if(c == 'Y') {
      b.playerSpawn.x = y-1;
      b.playerSpawn.y = x-1;
      //add x and y dadat
    }
    if(c == '\n') {
      x=0;
      y++;
    }
    x++;
  }
  return b;
}

void printBoard(Board b) {
  printLinkListRev(b.bList);
}


int main() {
  string fname;
  cin >> fname;
  ifstream f(fname);
  if(!f) {
    cout << "Error! File not found.";
    return 1;
  }
  Board t;
  t= readFile(f);
  printBoard(t);

  startCurses();
  do {
    usleep(150000);
    char c = inputChar();
    if (c == 'y') {  // game exits with a 'y'
      break;
    }
  } while(true);

  endCurses();
  //ending data
  cout << "Player start: " << '(' << t.playerSpawn.x << ',' << t.playerSpawn.y << ")\n";
  cout << "Spawn spots : ";
  for(int i=0; i<t.maxSpawn; i++) {
    cout << '(' << t.spawnList[i].x << ',' << t.spawnList[i].y << ") ";
  }
  return 0;

}
