#include <iostream>
#include <bitset>
using namespace std;

int main() {
  int x = 100;
  cout << (1<x<10)<< endl;
  cout << (1<x) << endl;
  cout << (1<false) << endl;
  cout << (1<true) <<endl;

  bitset<8> e(bool q = true);
  bitset<8> y(bool b = false);

  cout << e << y <<'\n';
  return 0;
}
