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
  const int SEC = 1000000;
  //TODO: MOVE THIS TO THE BOARD H OR CPP TO SIMPLIFY

  //count of "player" entities in the game
  int starCount = t.maxSpawn*5;
  int pCount = 1+starCount+t.maxSpawn;

  //player point object
  point Player;
  Player.cVal = 'P';
  Player.y = t.playerSpawn.y;
  Player.x = t.playerSpawn.x;
  Player.lastX = t.playerSpawn.x;
  Player.lastY = t.playerSpawn.y;
  //is the player moving?
  bool mvToggle = false;

  //setup killers/other and walls
  point* objs = new point[pCount];
  point* walls = new point[t.wallCount];
  //add objects for the player to contend with to the objects list
  objs[0] = Player;
  int ind = 1;
  for(int i=0; i<starCount/5; i++) {
    //for every spawn, ther is one spawn point and 5 stars
    for(int s=0; s<5; s++) {
      t.spawnList[i].cVal = '*';
      objs[ind] = t.spawnList[i];
      objs[ind].x = t.spawnList[i].x;
      objs[ind].y = t.spawnList[i].y;
      //pick random starting direction
      objs[ind].dir = rand() % 4;
      //avoid having these being undefined in collision function
      objs[ind].lastDir = objs[ind].dir;
      objs[ind].lastX = t.spawnList[i].x;
      objs[ind].lastY = t.spawnList[i].y;
      //increment object index
      ind++;
    }
  }
  for(int i=0; i<t.maxSpawn; i++) {
    t.spawnList[i].cVal = 'K';
    objs[ind] = t.spawnList[i];
    objs[ind].x = t.spawnList[i].x;
    objs[ind].y = t.spawnList[i].y;
    //pick random starting direction
    objs[ind].dir = rand() % 4;
    //avoid having these being undefined in collision function
    objs[ind].lastDir = objs[ind].dir;
    objs[ind].lastX = t.spawnList[i].x;
    objs[ind].lastY = t.spawnList[i].y;
    //increment object index
    ind++;
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
        if(i<(pCount-t.maxSpawn)) {
          //movement logic for the stars
          int rando = rand() % 10 + 1;
          if(rando == 1) {
            int turnRand = rand() % 2 + 1;
            if(turnRand == 1) {
              //turn left
              rotateDir(objs[i], true);
            } else {
              //turn right
              rotateDir(objs[i], false);
            }
          }

          movePoint(objs[i], true, 1);
          if(collision(objs[i], walls, t.wallCount, 0)) {
            invertDir(objs[i]);
            movePoint(objs[i], true, 1);
          }
        } else {
          //killer movement logic
//           1. let dc = Player column position - Killer column position
// 2. let dr = Player row position - Killer row position
// 3. if dc < 0 let cdir = 3 else let cdir = 1
// 4. if dr < 0 let rdir = 0 else let rdir = 2
// 5. with prob 1/2 set Killer's direction to rdir, otherwise set Killer's direction to cdir
          int dc = Player.y-objs[i].y; int dr = Player.x-objs[i].x;
          int cdir = 1, rdir = 2;
          int rando = rand() % 2 + 1;

          if(dc < 0) {
            cdir = 3;
          } else {
            cdir = 1;
          }

          if(dr < 0) {
            rdir = 0;
          } else {
            rdir = 2;
          }

          if(rando == 1) {
            int turnRand = rand() % 2 + 1;
            if(turnRand == 1) {
              //set killer dir to rdir
              objs[i].dir = rdir;
            } else {
              //set killer dir to cdir
              objs[i].dir = cdir;
            }
          }

          movePoint(objs[i], true, 1);
          if(collision(objs[i], walls, t.wallCount, 0)) {
            invertDir(objs[i]);
            movePoint(objs[i], true, 1);
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
          usleep(SEC*2);
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
  destroyBoard(t);
  delete [] objs;
  delete [] walls;
  return 0;

}
