#include "easycurses.h"
#include "Pos.h"
#include "Point.h"
#include "Board.h"
#include <unistd.h>

// submit ~/bin/submit -c=SI204 -p=proj03 Makefile part3.cpp Board.cpp Point.cpp Pos.cpp easycurses.cpp easycurses.h Board.h Point.h Pos.h board2Rm.txt boardCenter.txt boardMaze.txt boardTiny.txt

using namespace std;

int main() {
  //setup the game from file
  string fname;
  cin >> fname;
  ifstream f(fname);
  if(!f) {
    cout << "Error! File not found.";
    return 1;
  }
  //shitty name ngl
  Board t;
  //load in the board
  t= readFile(f);
  int wid = 0, hei = 0, turns = 0;
  const int DELAY = 100000;

  //printBoard(t);

  //count of "player" entities in the game
  int pCount = 1+(t.maxSpawn*5);
  //player point object
  point Player;
  Player.cVal = 'P';
  Player.y = t.playerSpawn.y;
  Player.x = t.playerSpawn.x;
  //is the player moving?
  bool mvToggle = false;

  //setup killers/other and walls
  point* objs = new point[pCount];
  point* walls = new point[t.wallCount];
  //add objects for the player to contend with to the objects list
  objs[0] = Player;
  for(int i=1; i<pCount; i++) {
    t.spawnList.cVal = '*';
    objs[i] = t.spawnList[i];
  }

  //add all points from the board to walls for collision function
  int wc = 0;
  for(int r=0; r<t.height; r++) {
    for(int col=0; col<t.width; col++) {
      if((t.bArr[r][col]).cVal == '#') {
        walls[wc] = t.bArr[r][col];
        wc++;
      }
    }
  }
  bool win = false;
  startCurses();
  getWindowDimensions(wid, hei);
  //game loop
  do {
    //get user input
    char key = inputChar();


    //mv logic for enemies
    //delete everything to update the positions
    delPoints(objs, pCount);
    for(int i=0; i<pCount; i++) {
      if(i != 0) {
        //movement logic for the other objects
        int rando = rand() % 10 + 1;
        if(rando == 1) {
          int turnRand = rand() % 2 + 1;
          if(turnRand == 1) {
            rotateDir(objs[i], true);
          } else {
            rotateDir(objs[i], false);
          }
        }
      } else {

        //player movement logic
        handleMove(objs[0], key, mvToggle);
        if(mvToggle) {
          movePoint(objs[0], true, 1);
        }

        if(collision(objs[0], objs, pCount)) {
          //end game because the player was killed
          key = 'y';
          win = false;
        }
        //check if goalS
        if(isGoal(t, objs[0])) {
          key = 'y';
          win = true;
        }
        //wall collision check
        if(collision(objs[0], walls, t.wallCount, 0)) {
          invertDir(objs[0]);
          movePoint(objs[0], true, 1);
        }
      }
    }
    //display the updated board
    printBoard(t);
    //draw all of the entities
    drawPoints(objs, pCount);
    usleep(DELAY);
    //tick counter for score
    turns++;

    if (key == 'y') {  // game exits with a 'y'
      break;
    }
  } while(true);

  endCurses();
  //ending data'
  if(win) {
    cout << "Victory!\n";
  } else {
    cout << "Defeat...\n";
  }
  cout << "Score: " << 500-turns;
  for(int i=0; i<t.maxSpawn; i++) {
    cout << '(' << t.spawnList[i].x << ',' << t.spawnList[i].y << ')';
  }
  cout << '\n';
  return 0;

}
