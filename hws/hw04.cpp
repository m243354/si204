#include <iostream>

using namespace std;

int main() {
  int feet1, inches1, feet2, inches2;
  char q;
  //read input from user
  cout << "Enter two lengths in feet and inches (larger first!)" << "\n";
  cin >> feet1 >> q >> inches1 >> q>>q;
  cin >> feet2 >> q >> inches2 >> q>>q;
  //cout difference
  int diff = feet1*12+inches1-feet2*12-inches2;
  cout << "Difference is "<<diff/12<<"' "<<diff%12<<"'\'" "\n";

  return 0;
}
