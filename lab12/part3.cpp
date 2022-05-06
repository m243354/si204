#include <iostream>
#include <fstream>
#include "lab12.h"
using namespace std;


 //g++ -o p3 part3.cpp lab12.cpp

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
  Node* T = P;
  for(int i=datCount; i>0; i--) {
    for(int k=i; k<datCount; k++) {
      if(T!= NULL) {
        T = T->next;
      }
    }
    nodeStats(T, i, datCount-i);
    cin >> c;
    T = P;
  }

  cout << "\n\n\n DEBUG: \n";
  printLinkList(P);
  deleteList(P);

  return 0;
}
