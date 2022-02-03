#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> foo() {
  vector<int> A{2,3};
  return A;
}

int gcd(int a, int b, int &extra)
{
  
}

int main() {
  int x = 3, y = 2, z;
  int g = gcd(x,y,z);
  
  return 0;
}
