#include <iostream>

using namespace std;

int main() {
  int feet1, inches1, feet2, inches2;
  char q;
  cout << "Enter two lenghts in feet and inches (larger first!)" << "\n";
  cin >> feet1 >> q >> inches1 >> q >> q;
  cin >> feet2 >> q >> inches2 >> q >> q;

  cout << "Difference is "<<feet1-feet2<<"' "<<inches1-inches2<<"'\'" "\n";

  return 0;
}
