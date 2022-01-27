#include <iostream>
#include <string>
using namespace std;

int main() {
  //take input currency and currency type
  char t;
  double c, p;
  string currTyp, goalTyp, input;
  //this is an inefficient way of getting rid of CONVERT
  cin >> input;
  if(currTyp == "Euros") {
    if(goalTyp == "Dollars") {
      //euros to dollars
      p = 0.9018*c;
    } else {
      //goal type has to be pounds. euros to dollars then to pounds
      p = c*0.9018*0.7614;
    }    
  } 
  if(currTyp == "Dollars") {
    if(goalTyp == "Euros") {
      //dollars to euros
      
    } else {
      p = c*0.7614;
    }

  }
  
  cout << 
  return 0;
}

