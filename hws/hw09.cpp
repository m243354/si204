#include <iostream>

using namespace std;

int gcd(int a, int b) {
  while(b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main() {
  //var declar. q is for plus sign and slash
  int numer1, denom1, numer2, denom2, result0, result1;
  char q;

  cout << "Enter a fraction addition problem: " ;
  cin >> numer1>>q>>denom1>>q>>numer2>>q>>denom2;
  result0 = numer1*denom2+numer2*denom1;
  result1 = denom2*denom1;
  int ans = gcd(result1, result0);
  cout << numer1<<'/'<<denom1<< " + "<<numer2<<'/'<<denom2;
  cout <<" = "<<result0/ans<<'/'<<result1/ans;


}
