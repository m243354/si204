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
  Node* K = P;

  //reading and storing the data
  char c;
  while(f >> c >> dat >> num >> c) {
      P = newNode(P, num, dat);
  }

  //now we have to do this again but allow the user to accept or reject data.
  //we will iterate through P backwards
  int datCount = getLinkListLen(P);
  //t is our temp traversal node
  Node* T = P;
  for(int i=datCount; i>0; i--) {
    nodeStats(T, i, datCount-i);
    cin >> c;
    cout << endl;
  }

  cout << "\n\n\n DEBUG: \n";
  printLinkList(P);
  deleteList(P);

  return 0;
}
