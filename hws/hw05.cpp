//dwight kinney
//m243354
#include <iostream>

using namespace std;

int main() {
  // get from lowercase to cap is subtrating (97-65)
  //inpit
  char q1,q2,q3;

  cout << "Input a 3-letter word in lowercase letters: ";
  cin >> q1 >> q2 >> q3;
  cout << "With leading letter capitalized this is   : "<<char(q1-(97-65))<<q2<<q3 << endl;
 
  
};
