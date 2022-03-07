#include <iostream>
//Dwight Kinney
//243354
using namespace std;

//not clean but it works
int main() {
  //take in word number
  int n;
  cout << "Number of words: ";
  cin >> n;
  //make string array with n size
  string* w = new string[n];
  cout << "Sentence: ";
  for(int i=0; i<n; i++) {
    cin >> w[i];
  }

  //cout the sentence in order and add question mark
  for(int i=0; i<n; i++) {
    cout << w[i];
    if(i<n-1) {
      cout << ' ';
    }
  }
  cout << "?";
  //cout the sentence in reverse and add excalamation mark
  for(int i=n; i>=0; i--) {
    cout << w[i];
    if(i>0) {
      cout << ' ';
    }
  }
  cout << "!";
  
  return 0;
}
