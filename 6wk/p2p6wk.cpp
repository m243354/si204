#include <iostream>

//Dwight Kinney
//m243354

using namespace std;

int main() {
  //variables for stuff
  int floor = 1, people = 0;
  string input;
  //my loop while we do not take in done
  //this will never fail so I have to put a break in it
  while(cin >> input) {
    if(input == "done") {
      break;
    }
    if(input == "pin") {
      people++;
    } 
    if(input == "pout" && people > 0) {
      people--;
    } else if (input == "pout"){
      cout << "error!";
      people--;
      break;
    }
    if(input == "up") {
      floor++;
    }
    if(input == "down") {
      floor--;
    }
    
  }
  if(people >= 0) {
    cout << "floor: " << floor << "\npeople: " << people;
  }
  
  return 0;
}
