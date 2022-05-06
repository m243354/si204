#ifndef GEORGEPOINT
#define GEORGEPOINT
#include <cstdlib>

struct point {
  char cVal;
  int x, y, dir;
  int lastX, lastY, lastDir;
};

//draws a point array p of length n at their position. Ignore is a special case to not print out Zs and Ys.
void drawPoints(point* p, int n, bool ignore=false);
//takes in an array of points of n length and 'erases' them from the screen by replacing them with a space character
void delPoints(point* p, int n);
//Collision function that takes in a point, an array of entities, int n for the length of the entity array, and a starting index. The starting index defaults to 1 and assumes
//that the player is at the first index of the entity array. Override this with 0 if this is not the case.
bool collision(point p, point* Players, int n, int stIndex=1);
//Function that takes in a point and flips the direction of the point. This direction is used in the movePoint function.
void invertDir(point &p);
//rotates the point to the left if leftTurn is true or to the right if it is false
void rotateDir(point &p, bool leftTurn);

//increments the point position based on the direction and the distance specified. Used in conjunction with canMove
void movePoint(point &p, bool forward, int dist);

//returns true if the point is within the bounds specified as width and height. Forward is just if the point is moving forward or backwards.
bool canMove(point p, bool forward, int dist, int wid, int hei);
//takes in a point, a movement toggle, and the key pressed. Makes the point move in the key direction of WASD and changes mvToggle accordingly.
void handleMove(point &p, char key, bool &mvToggle);

//amogn us!
int outOfBounds(point p, bool forward, int dist, int wid, int hei);

//yoinked from the Pos.h and made to work for my point struct.
int dist(point p, point q);
//overrides the assignment operator for simplicity purposes
// void operator=(point &a);

#endif
