#include <iostream>
#include <cstdlib>

using namespace std;

int rolldice() {
  //Uses rand function like lab instructions state to return an integer between
  //1 and 6
  int roll = 7;
  while(roll > 6) {
    roll = rand() % 8;
  }
  return roll+1;
}

int main() {
  for(int r=0; r<5; r++) {
    int r1 = rolldice();
    int r2 = rolldice();
    cout << "Player rolled " << r1 << " + " << r2 << " = " << r1+r2 << '\n'; 
  }


  return 0;
}
