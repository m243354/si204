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

void drawPoint(point p) {
  drawChar(p.cVal, p.x, p.y);
}

void delPoint(point p) {
  drawChar(' ', p.x, p.y);
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
  point Player;
  Player.cVal = 'X';
  Player.x = 15;
  Player.y = 30;
  Player.dir = 1;
  int moveDist = 1;
  int delay = 80000;
  char key;
  srand(time(0));
  startCurses();

  do {
    // draw character
      drawPoint(Player);

    refreshWindow(); // These two lines correspond to flipping to
    usleep(delay);  // the next frame in the animation.

    // use inputChar to see if the user has pressed 'q'
    key = inputChar();
    delPoint(Player);
    int rando = rand() % 10 + 1;
    if(rando == 1) {
      int turnRand = rand() % 2 + 1;
      if(turnRand == 1) {
        if(Player.dir > 0) {
          Player.dir -= 1;
        } else {
          Player.dir = 3;
        }
      } else {
        if(Player.dir < 3) {
          Player.dir += 1;
        } else {
          Player.dir = 0;
        }
      }
    }
    movePlayer(Player, true, 1);
  }while(key != 'q');

  endCurses();
  return 0;
}
