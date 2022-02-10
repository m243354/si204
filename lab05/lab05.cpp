#include <iostream>

using namespace std;

//Dwight Kinney
//243354
//
int main() {
  //input for n rows
  int n;
  cin >> n;

  for (int i=0; i<n; i++) {
    //for n rows
    int q = n-i;
    //since I is the amount of times that a space should be printed we iterate
    //up to i
    for(int s=0; s<i; s++) {
      cout << " ";
    }
    //q is the value to print as well as the amount of times that the value
    //should be printed
    for(int p=0; p<q; p++) {
      cout << q;
    }
    cout << '\n';
  }
  return 0;
}
