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

bool collision(point p, point* Players, int n) {
  for(int i=1; i<n; i++) {
    if(p.x == Players[i].x && p.y == Players[i].y) {
      return true;
    }
  }
  return false;
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
    Players[i].cVal = rand() % 96 + 34;
    if(i ==0) {
      //the user is always an exclamtion mark
      Players[i].cVal = 33;
    }

    Players[i].x = rand() % wid-1;
    Players[i].y = rand() % hei-1;
    Players[i].dir = rand() % 3;
  }
  int moveDist = 1;
  int delay = 80000;
  int steps = 0;
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
      if(i != 0) {
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
      } else {
        if(key == 'w') {
          Players[0].dir = 0;
        }
        if(key == 's') {
          Players[0].dir = 2;
        }
        if(key == 'a') {
          Players[0].dir = 3;
        }
        if(key == 'd') {
          Players[0].dir = 1;
        }
        if(collision(Players[0], Players, playerC)) {
          //end game
          key = 'q';

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
    steps++;
  }while(key != 'q');

  endCurses();
  cout << "You survived " << steps << " steps!\n";
  return 0;
}
