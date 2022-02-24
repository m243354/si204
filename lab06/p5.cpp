#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rolldice() {
  //Uses rand function like lab instructions state to return an integer between
  //1 and 6
  int roll = 7;
  while(roll >= 6) {
    roll = rand() % 8;
  }
  return roll+1;
}

int throw1(int r, int setpoint) {
  //returns -1, 0, or 1. -1 means house wins, 0 meand player wins, and a
  //positive number is the sum
  int r1 = rolldice();
  int r2 = rolldice();
  int sum = r1+r2;
  
  cout << "Round "<< r << ": Player rolled " << r1 << " + " << r2 << " = " << sum;
  if(r < 2) {
    if(sum == 7 || sum == 11) {      
      cout << " Player wins!\n"; 
      return 0;
    } else if (sum == 2 || sum == 3 || sum == 12) {
      cout << " House wins!\n";
      return -1;
    } else {
      cout << " ... no winner, setpoint is " << sum <<"!\n";
      return sum;
    }
  } else {
    if(sum == setpoint) {
      cout << " Player wins!\n";
      return 0;
    } else if(sum == 7 || sum == 2 || sum == 3 || sum == 12) {
      cout << " House wins!\n";
      return -1;
    } else {
      cout << " ... no winner, roll again!\n";
      return sum;
    }
  }
}

bool playAgainQuery(int win, int loss) {
  
  int bank = loss*-5+win*5;
  if(loss > win) {
      cout << "down $" << bank*-1 << ".\n";
    } else if (loss == win) {
      cout << "dead even.\n";
    } else {
      cout << "up $" << bank << ".\n";
    }
  cout << "Would you like to play again? (y/n)";
  string r;
  cin >> r;
  if(r == "n") {
    return false;
  } else {
    return true;
  }


}


int main() {
  //Get a new seed from the user to generate psuedorandom numbers
  //int seed;
  //cout << "Enter a seed value: ";
  //cin >> seed;
  //srand(seed);
  srand(time(0));

  int w = 0, l = 0;
  int play = 0;
  bool gamble = true;
  while(gamble) {
    int lastroll = -1;
    int setpt = 7;
    for(int r=1; r<=5; r++) {
      int res = throw1(r, setpt);
      if(res == 0) {
        r = 6;
        //win
        w++;
      } else if (r == 1 && res > 0){
        setpt = res;
      } else if (res == -1) {
        r = 6;
        //loss
        l++;
      }

    }
    play++;
    cout << "You've played " << play << " times, and are ";
    gamble = playAgainQuery(w, l);
  }

  return 0;
}
