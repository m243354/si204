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

int throw1(int r) {
  //returns -1, 0, or 1. -1 means house wins, 0 meand player wins, and 1 is no
  //winner
  int r1 = rolldice();
  int r2 = rolldice();
  int sum = r1+r2;
  cout << "Round "<< r << ": Player rolled " << r1 << " + " << r2 << " = " << sum;
  if(sum == 7 || sum == 11) {      
    return 0;
  } else if (sum == 2 || sum == 3 || sum == 12) {
    return -1;
  } else {
    return 1;
  }
}


int main() {
  //Get a new seed from the user to generate psuedorandom numbers
  //int seed;
  //cout << "Enter a seed value: ";
  //cin >> seed;
  //srand(seed);
  srand(time(0));

  for(int r=1; r<=5; r++) {
    int res = throw1(r);
    switch (res) {
      case -1:
        cout << " House wins!\n";
        r = 6;
        break;
      case 0:
        cout << " Player wins!\n";
        r = 6;
        break;

      case 1:
        cout << " ... no winner, roll again!\n";
        break;
    }
  }

  return 0;
}
