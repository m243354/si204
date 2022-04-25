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

bool canMove(point p, bool forward, int dist, int wid, int hei) {
  int neg = 1;
  if(forward) {
    neg = 1;
  } else {
    neg = -1;
  }
  switch(p.dir) {
    case 0:
    //north
      p.x -= dist*neg;
      if(p.x < 0) {
        return false;
      }
      break;
    case 1:
    //east (right)
      p.y += dist*neg;
      if(p.y >= hei) {
        return false;
      }
      break;
    case 2:
    //south
      p.x += dist*neg;
      if(p.x >= wid) {
        return false;
      }
      break;
    case 3:
    //west (left)
      p.y -= dist*neg;
      if(p.y < 0) {
        return false;
      }
      break;
  }
  return true;
}

void movePlayer(point &p, bool forward, int dist) {
  int neg = 1;
  if(forward) {
    neg = 1;
  } else {
    neg = -1;
  }
  switch(p.dir) {
    case 0:
    //north
      p.x -= dist*neg;
      break;
    case 1:
    //east (right)
      p.y += dist*neg;
      break;
    case 2:
    //south
      p.x += dist*neg;
      break;
    case 3:
    //west (left)
      p.y -= dist*neg;
      break;
  }
}

bool collision(point p, point* Players, int n) {
  for(int i=1; i<n; i++) {
    if(p.x == Players[i].x && p.y == Players[i].y) {
      return true;
    }
  }
  return false;
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
  //setup the game from file
  string fname;
  cin >> fname;
  ifstream f(fname);
  if(!f) {
    cout << "Error! File not found.";
    return 1;
  }
  Board t;
  //load in the board
  t= readFile(f);
  int wid = 0, hei = 0;

  //printBoard(t);

  //count of "player" entities in the game
  int pCount = 1;
  //player point object
  point Player;
  Player.cVal = 'P';
  Player.x = t.playerSpawn.y;
  Player.y = t.playerSpawn.x;

  point* objs = new point[pCount];
  objs[0] = Player;

  startCurses();
  getWindowDimensions(wid, hei);
  //game loop
  do {
    char key = inputChar();


    //mv logic
    delPoints(objs, pCount);
    for(int i=0; i<pCount; i++) {
      if(i != 0) {
        int rando = rand() % 10 + 1;
        if(rando == 1) {
          int turnRand = rand() % 2 + 1;
          if(turnRand == 1) {
            if(objs[i].dir > 0) {
              objs[i].dir -= 1;
            } else {
              objs[i].dir = 3;
            }
          } else {
            if(objs[i].dir < 3) {
              objs[i].dir += 1;
            } else {
              objs[i].dir = 0;
            }
          }
        }
      } else {
        if(key == 'w') {
          objs[0].dir = 0;
        }
        if(key == 's') {
          objs[0].dir = 2;
        }
        if(key == 'a') {
          objs[0].dir = 3;
        }
        if(key == 'd') {
          objs[0].dir = 1;
        }
        if(collision(objs[0], objs, pCount)) {
          //end game
          key = 'q';

        }
      }
      if(canMove(objs[i], true, 1, wid, hei)) {
        movePlayer(objs[i], true, 1);
      } else {
        if(objs[i].dir > 1) {
          objs[i].dir -= 2;
        } else {
          objs[i].dir = 3;
        }
        movePlayer(objs[i], true, 1);
      }
    }

    drawPoints(objs, pCount);
    usleep(150000);

    if (key == 'y') {  // game exits with a 'y'
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
