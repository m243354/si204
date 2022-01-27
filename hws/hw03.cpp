#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double x,y,z;
  cout << "Enter length x: ";
  cin >> x;
  cout << "Enter length y (<"<<x<<"): ";
  cin >> y;
  double sideAC = sqrt(x*x-y*y);
  cout << "Enter length z (<"<<sideAC<<"): ";
  cin >> z;
  double BD = sqrt(y*y+(sideAC-z)*(sideAC-z));
  cout << "Length of BD is "<<BD<<endl;

  return 0;
};
