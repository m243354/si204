#include "easycurses.h"
#include "Pos.h"
#include "Node.h"
#include <iostream>
#include <fstream>

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
  int height, width, dat;
  Node* bList;
  Spawn* spawnList;
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
  f >> b.height >> c >> b.width >> b.dat;
  int x = 0, y = 0, spCount = 0;
  //add 2 to spawnlist because it is the amt of Z spawns plus the goal spawns
  b.spawnList = new Spawn[b.dat+2];
  while(f.get(c)) {
    addNode(b.bList, c);
    if(c == 'Z') {
      b.spawnList[spCount].name = "Spawn spot";
      b.spawnList[spCount].p.x = x;
      b.spawnList[spCount].p.y = y;
      //add x and y dadat
    }
    if(c == 'X') {
      b.spawnList[spCount].name = "Goal spot";
      b.spawnList[spCount].p.x = x;
      b.spawnList[spCount].p.y = y;
      //add x and y dadat
    }
    if(c == 'Y') {
      b.spawnList[spCount].name = "Player spawn";
      b.spawnList[spCount].p.x = x;
      b.spawnList[spCount].p.y = y;
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
  cout << "Player start: ";
  return 0;

}
