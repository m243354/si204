#include "Point.h"
#include "easycurses.h"

//draws a point array p of length n at their position. Ignore is a special case to not print out Zs and Ys.
void drawPoints(point* p, int n, bool ignore) {
  for(int i=0; i<n; i++) {
    //if ignore is false, cout everything
    if(!ignore) {
      drawChar(p[i].cVal, p[i].x, p[i].y);
    } else {
      //put a space in these spots to ignore the Z and Y
      if(p[i].cVal == 'Z' || p[i].cVal == 'Y') {
        drawChar(' ', p[i].x, p[i].y);
      } else {
        drawChar(p[i].cVal, p[i].x, p[i].y);
      }
    }
  }
}

//Function that takes in a point and flips the direction of the point. This direction is used in the movePoint function.
void invertDir(point &p) {
  switch(p.dir) {
    case 0:
      p.dir = 2;
      break;
    case 1:
      p.dir = 3;
      break;
    case 2:
      p.dir = 0;
      break;
    case 3:
      p.dir = 1;
      break;
  }
}

//Collision function that takes in a point, an array of entities, int n for the length of the entity array, and a starting index. The starting index defaults to 1 and assumes
//that the player is at the first index of the entity array. Override this with 0 if this is not the case.
bool collision(point p, point* entities, int n, int stIndex) {
  for(int i=stIndex; i<n; i++) {
    if(p.x == entities[i].x && p.y == entities[i].y) {
      return true;
    }
  }
  return false;
}

//takes in an array of points of n length and 'erases' them from the screen by replacing them with a space character
void delPoints(point* p, int n) {
  for(int i=0; i<n; i++) {
    drawChar(' ', p[i].x, p[i].y);
  }
}

//rotates the point :)
void rotateDir(point &p, bool leftTurn) {
  if(leftTurn) {
    //left turn
    if(p.dir > 0) {
      p.dir -= 1;
    } else {
      p.dir = 3;
    }
  } else {
    //right turn
    if(p.dir < 3) {
      p.dir += 1;
    } else {
      p.dir = 0;
    }
  }
}

//returns true if the point is within the bounds specified as width and height. Forward is just if the point is moving forward or backwards.
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

//increments the point position based on the direction and the distance specified. Used in conjunction with canMove
void movePoint(point &p, bool forward, int dist) {
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

void handleMove(point &p, char key, bool &mvToggle) {
  if(key == 'w') {
    mvToggle = true;
    p.dir = 0;
  }
  if(key == 's') {
    mvToggle = true;
    p.dir = 2;
  }
  if(key == 'a') {
    mvToggle = true;
    p.dir = 3;
  }
  if(key == 'd') {
    mvToggle = true;
    p.dir = 1;
  }
  if(key == 'r') {
    mvToggle = false;
  }
}

int dist(point p, point q) {
  return abs(p.y - q.y) + abs(p.x - q.x);
}

// //overwrites the assignment operator
// point operator=(point &a) {
//   point t;
//   t.x = a.x;
//   t.y = a.y;
//   t.dir = a.dir;
//   return t;
// }
