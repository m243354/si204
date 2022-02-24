#include <iostream>
#include <cstdlib>
#include <ctime>

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
  //Get a new seed from the user to generate psuedorandom numbers
  //int seed;
  //cout << "Enter a seed value: ";
  //cin >> seed;
  //srand(seed);
  srand(time(0));

  for(int r=0; r<5; r++) {
    int r1 = rolldice();
    int r2 = rolldice();
    cout << "Player rolled " << r1 << " + " << r2 << " = " << r1+r2 << '\n'; 
  }


  return 0;
}
