//Dwight Kinney
//243354
#include <iostream>

using namespace std;

int main() {
  //vars
  int numIn, out, dig0, dig1, dig2, dig3;
  //input
  cout << "Enter a number between 0 and 15: ";
  cin >> numIn;
  int clone = numIn;
  //get individual digits
  dig0 = numIn % 2;
  numIn /= 2;
  dig1 = numIn % 2;
  numIn /= 2;
  dig2 = numIn % 2;
  numIn /= 2;
  dig3 = numIn % 2;
  numIn /= 2;

  //find each digit by modulo and turn it into decimal then sum
  cout << clone <<" in binary is " << dig3<<dig2<<dig1<<dig0 << '\n';

  return 0;
};
