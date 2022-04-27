#include <fstream>
#include <iostream>
#include "Point.h"
#include "Board.h"

using namespace std;

Board readFile(ifstream& f) {
  //throwaway
  char c;
  //our board
  Board b;
  //read in header of file
  f >> b.height >> c >> b.width >> b.maxSpawn;
  f.get(c); // skip newline
  b.width++;
  //incremented to account for the newlines at the end of the thing
  //sp is spawn counter
  int spCount = 0;
  //initialitzing point arrays based on the data we read from the file
  b.spawnList = new point[b.maxSpawn];
  b.bArr = new point*[b.height];

  for(int r=0; r<b.height; r++) {
    b.bArr[r] = new point[b.width];
    for(int col=0; col<b.width; col++) {
      f.get(c);
      //if c is a hashtag count it as a wall
      if(c==35) {
        b.wallCount++;
      }
      point k;
      k.cVal = c;
      k.y = col;
      k.x = r;
      //add each point to bArr
      b.bArr[r][col] = k;
      if(c == 'Z') {
        //correct positions
        cout << "spawn added at: (" << r << ',' << col << ")\n";
        b.spawnList[spCount].y = col;
        b.spawnList[spCount].x = r;
        spCount++;
        //add x and y dadat
      }
      if(c == 'X') {
        b.goalSpawn.y = col;
        b.goalSpawn.x = r;
        //add x and y dadat
      }
      if(c == 'Y') {
        b.playerSpawn.y = col;
        b.playerSpawn.x = r;
        //add x and y dadat
      }
    }
  }
  return b;
}

void printBoard(Board b) {
  for(int r=0; r<b.height; r++) {
    drawPoints(b.bArr[r], b.width, true);
  }
}

bool isGoal(Board b, point p) {
  if(dist(p, b.goalSpawn) == 1) {
    return true;
  }
  return false;
}

void destroyBoard(Board b){
 for(int r=0; r<b.height; r++) {
   delete [] b.bArr[r];
 }
 delete [] b.bArr;
 delete [] b.spawnList;
}
