#include "easycurses.h"
#include "Pos.h"
#include "Point.h"
#include "Board.h"
#include <unistd.h>
#include "Node.h"

using namespace std;

int main() {
  sNode* n = NULL;
  cout << "Enter script filename: ";
  string filen, boardName, numStar, numKill, trash, score;
  cin >> filen;
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
  return 0;
}
