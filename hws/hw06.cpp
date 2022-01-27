#include <iostream>

//243354
//Dwight Kinney

using namespace std;

int main() {
  //read in
  int yr;
  bool is = false;
  cout << "Enter year: ";
  cin >> yr;
  //check divisibility
  if(yr%4==0) {
    is=true;
    if(yr%100==0) {
      is = false;
      if(yr%400==0) {
        is=true;
      }
    }
  }

  //print result
  if(is) {
    cout << "Is Leap Year" << endl;
  } else {
    cout << "Is Not Leap Year" << endl;
  }
}
