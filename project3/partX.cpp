#include "easycurses.h"
#include "Point.h"
#include "Board.h"
#include <unistd.h>
#include "Node.h"
#include "curses.h"

//~/bin/submit -c=SI204 -p=proj03 Makefile part5.cpp Board.cpp Point.cpp Node.cpp Node.h easycurses.cpp easycurses.h Board.h Point.h board2Rm.txt boardCenter.txt boardMaze.txt boardTiny.txt board243354.txt

//add holes in the map that let you escape. The game calls you a coward and you recieve a points deduction.

using namespace std;

bool game(string boardName, int numStar, int numKill, int score, int &totalScore, int &roomChng);

int main() {
  sNode* n = NULL;
  cout << "Enter script filename: ";
  int roomsN;
  string filen, boardName, numStar, numKill, trash, score;
  cin >> filen;
  ifstream f(filen);
  if(!f) {
    cout << "Error! File not found.";
    return 1;
  }
  f >> boardName;

  if(boardName == "Group") {
    f >> roomsN;
    int numKillr, numStarr, scorer;
    f >> numStarr >> numKillr >> trash >> trash >> scorer;
    string* multiBoard = new string[roomsN];
    for(int i=0; i<roomsN; i++) {
      f >> multiBoard[i];
    }
    cout<<"kk";
    //now I run the game wth the new parameters.
    int level = 0, deaths = 0, totalScore = 0, levelCng = 0;
    bool goal = false;
    while(!goal) {
      bool play = game(multiBoard[level], numStarr, numKillr, scorer, totalScore, levelCng);
      if(play) {
        //if this is true, I move to another room.
        cout << flush;
        level++;
      } else {
        //I died so I stay in the same room
        deaths++;
      }
    }


  } else {
    //restart file because we aren't looking for a group level.
    ifstream f(filen);
    if(!f) {
      cout << "Error! File not found.";
      return 1;
    }
    while(f >> boardName >> numStar >> numKill >> trash >> trash >> score) {
      string* dat = new string[4];
      dat[0] = boardName;
      dat[1] = numStar;
      dat[2] = numKill;
      dat[3] = score;
      addNode(n, dat);
    }
    printLinkListRev(n);

    //traverses linked list in reverse. now get the data
    int maxLevel = getLinkListLen(n);
    int level =0;
    int totalScore = 0;
    string* a;
    for(int i=0; i<maxLevel; i++) {
      //0
      //run 0 times, then 1 times, then 2...
      for(sNode *p = n; level < maxLevel-i; p = p->next) {
        a = p->data;
        level++;
      }
      //right here amog is the string of data for starting the game.
      int loserCount = 0;
      int trash = -1;
      //play game with these parameters and store win output in a boolean
      while((!game(a[0], stoi(a[1]), stoi(a[2]), stoi(a[3]), totalScore, trash)) && loserCount < 3) {
        //while I lose keep playing until I lose three times or win.
        loserCount++;
      }
      if(loserCount == 3) {
        cout << "3 consecutive deaths. Game Over.\n";
        cout << "You scored: " << totalScore << " points. Try again!";
        return 0;
      }
      level = 0;
    }
    cout << "Victory! You cleared " << maxLevel << " maps and scored a total of " << totalScore << " points!";
  }
  return 0;
}

bool game(string boardName, int numStar, int numKill, int score, int &totalScore, int &roomChng) {
  //setup the game from file
  ifstream f(boardName);
  if(!f) {
    cout << "Error! File not found.";
    return false;
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
  int starCount = numStar;
  int pCount = 1+starCount+numKill;

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
  for(int i=0; i<numKill; i++) {
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
  start_color();
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
          if(collision(objs[i], walls, t.wallCount, 0) || !canMove(objs[i], true, 1, wid, hei)) {
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
        handleMove(objs[i], key, mvToggle);
        if(mvToggle) {
          movePoint(objs[i], true, 1);
        }

        if(collision(objs[i], objs, pCount)) {
          //end game because the player was killed
          key = 'y';
          win = false;
          usleep(SEC*2);
        }
        //check if player escaped map bounds
        switch(outOfBounds(objs[i], true, 1, wid, hei)) {
          default:
            //do nothing
            break;
          case 0:
            //went off top of map
            break;
          case 1:
          //went off east of map
            break;
          case 2:
          //wnt off bottom of map
            break;
          case 3:
          //went of left of map
            break;

        }
        //check if goalS
        if(isGoal(t, objs[i])) {
          key = 'y';
          win = true;
        }
        //wall collision check
        if(collision(objs[i], walls, t.wallCount, 0) || !canMove(objs[i], true, 1, wid, hei)) {
          invertDir(objs[i]);
          movePoint(objs[i], true, 1);
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
  cout << " Playing on: " << boardName << ", with killer count: " << numKill << ", with star per Z: " << numStar << ", for a possible " << score << " points.\n";
  if(win) {
    cout << "Victory!\n";
  } else {
    cout << "Defeat...\n";
  }
  cout << "Score: " << 500-turns << endl;
  totalScore += score+500-turns;
  destroyBoard(t);
  delete [] objs;
  delete [] walls;
  return win;
}
