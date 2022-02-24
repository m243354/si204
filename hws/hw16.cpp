#include <iostream>

//Dwight Kinney
//m243354

using namespace std;

int gcd(int a, int b) {
//use gcd algorithm we learned in class
  while(a%b != 0) {
    int r = a%b;
    a = b;
    b = r;
  }
  return b;
}

int main() {
  //variables to hold our input
  int num, den;
  char q;
  //read input from user
  while(cin >> num >> q >> den >> q) {
    //result of gcd in int res
    int res = gcd(den, num);
    //cout << num << '/' << den;
    //gcd returns 1 for those in lowest terms. 
    if(res != 1) {
      cout << num << '/' << den;
      cout << " is not in lowest terms!\n";
    }
    //temp debug
    //else {
      //cout << " is in lowest terms!\n";
    //}
    //loop exit condition
    if(q == ';') {
      break;
    }

  }
  return 0;
}
