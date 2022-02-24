#include <iostream>
#include <fstream>

//Dwight Kinney
//m243354

using namespace std;

int main() {
  //read a file name, dat is holder, j is temp, and 2 numbers in range 1 to 26.
  string file, dat, j;
  int row, col;

  cin >> file >> row >> col;


  ifstream f(file);
  //file checker
  if(!f) {
    cout << "File '" << file << "' not found!";
    return 1;
  }

  //row and col are always valid
  //Every file is a 26 by 26 table. cout the entry at the index given
  for(int r=1; r<=26; r++) {
    for(int c=1; c<=26; c++) {
      f >> j;
      if(r==row && col == c) {
        dat = j;
      }
    }
  }

  cout << dat;

  return 0;
}

