#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "easycurses.h"
using namespace std;

struct point {
  char cVal;
  int x, y;
};


//uses the draw char function to draw all of the points to the screen and has a delay
void drawPoints(point* pArr, int n, int delay) {
  for(int i=0; i<n; i++) {
    drawChar(pArr[i].cVal, pArr[i].x, pArr[i].y);
    refreshWindow();
    usleep(delay);
  }
}

//puts a space at the point of every char in the pArr
void delPoints(point* pArr, int n, int delay) {
  for(int i=0; i<n; i++) {
    drawChar(' ', pArr[i].x, pArr[i].y);
    usleep(delay);
  }
}

int main() {
  int pointnum;
  char temp;
  point* pointArr;
  cin >> pointnum;
  pointArr = new point[pointnum];
  for(int i=0; i<pointnum; i++) {
    // cVal (x, y)
    cin >> pointArr[i].cVal >> temp >> pointArr[i].x >> temp >> pointArr[i].y >> temp;
  }

  startCurses();
  drawPoints(pointArr, pointnum, 800000);
  delPoints(pointArr, pointnum, 0);
  usleep(800000);
  refreshWindow();
  
  endCurses();
  return 0;
}
