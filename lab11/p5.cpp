#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "easycurses.h"
using namespace std;



//Point is a char placed at a position. The direction is NESW, from 0-3. North = 0;
struct point {
  char cVal;
  int x, y, dir;
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



int main() {
  int playerC;
  int wid = 0, hei = 0;
  srand(time(0));
  cin >> playerC;
  point* Players = new point[playerC];
  startCurses();
  getWindowDimensions(wid, hei);
  for(int i=0; i<playerC; i++) {
    Players[i].cVal = rand() % 96 + 33;
    Players[i].x = rand() % wid;
    Players[i].y = rand() % hei;
    Players[i].dir = rand() % 3;
  }
  int moveDist = 1;
  int delay = 80000;
  char key;
  srand(time(0));
  do {
    // draw character
      drawPoints(Players, playerC);

    refreshWindow(); // These two lines correspond to flipping to
    usleep(delay);  // the next frame in the animation.

    // use inputChar to see if the user has pressed 'q'
    key = inputChar();
    delPoints(Players, playerC);
    for(int i=0; i<playerC; i++) {
      int rando = rand() % 10 + 1;
      if(rando == 1) {
        int turnRand = rand() % 2 + 1;
        if(turnRand == 1) {
          if(Players[i].dir > 0) {
            Players[i].dir -= 1;
          } else {
            Players[i].dir = 3;
          }
        } else {
          if(Players[i].dir < 3) {
            Players[i].dir += 1;
          } else {
            Players[i].dir = 0;
          }
        }
      }

      if(canMove(Players[i], true, 1, wid, hei)) {
        movePlayer(Players[i], true, 1);
      } else {
        if(Players[i].dir > 1) {
          Players[i].dir -= 2;
        } else {
          Players[i].dir = 3;
        }
      }
    }
  }while(key != 'q');

  endCurses();
  return 0;
}
