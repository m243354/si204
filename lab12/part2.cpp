#include <iostream>
#include <fstream>
#include "lab12.h"
using namespace std;




int main() {
  //get our filename and read in the data
  cout << "Input file is: ";
  string fname, dat;
  int num;
  cin >> fname;
  ifstream f(fname);
  if(!f) {
    cout << "Error! File '" << fname << "' not found!";
    return 1;
  }

  //last node
  Node* P = NULL;

  //reading and storing the data
  char c;
  while(f >> c >> dat >> num >> c) {
    P = newNode(P, num, dat);
  }

  int datCount = getLinkListLen(P);
  cout << "count is " << datCount << '\n';
  printLinkList(P);
  deleteList(P);

  return 0;
}
