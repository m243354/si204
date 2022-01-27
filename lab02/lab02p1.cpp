//Dwight Kinney
//243354
#include <iostream>

using namespace std;

int main() {
  int clone, dig0, dig1, dig2, dig3;
  char d0, d1, d2, d3;
  cout << "Enter a 4-bit binary number: ";
  cin >> d0 >> d1 >> d2 >> d3;
  //get individual digits
  dig0 = d0-48;
  dig1 = d1-48;
  dig2 = d2-48;
  dig3 = d3-48;
  //find each digit by modulo and turn it into decimal then sum
  clone = dig0*8+dig1*4+dig2*2+dig3;
  cout << "In decimal " << d0<<d1<<d2<<d3 << " = "<< clone << '\n';

  return 0;
};
