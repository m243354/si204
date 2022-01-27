//swegmaster123
//243354
#include <iostream>

using namespace std;

int main() {
  int numIn, out, dig0, dig1, dig2, dig3;

  cout << "Enter a 4 digit binary number:" << '\n';
  cin >> numIn;
  int clone = numIn;
  //get individual digits
  dig0 = numIn % 10;
  numIn /= 10;
  dig1 = numIn % 10;
  numIn /= 10;
  dig2 = numIn % 10;
  numIn /= 10;
  dig3 = numIn % 10;
  numIn /= 10;

  //find each digit by modulo and turn it into decimal then sum
  out = dig3*8 + dig2*4 + dig1*2 + dig0;
  cout << "In decimal " << clone << " = "<< out << '\n';

  return 0;
};
