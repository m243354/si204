#include <iostream>
#include <string>
using namespace std;

int main() {
  //take input currency and currency type
  double c, p;
  string currTyp, goalTyp, input, t;
  //
  cin >> t >> c >> currTyp >> t >> goalTyp;
  
  if(currTyp == "Euros") {
    if(goalTyp == "Dollars") {
      //euros to dollars
      p = (1/0.9018)*c;
    } 
    if(goalTyp == "Pounds") {
      //goal type has to be pounds. euros to dollars then to pounds
      p = c*(1/0.9018)*0.7614;
    } 
    if(goalTyp == "Euros"){
      p = c;
    }   
  } 
  if(currTyp == "Dollars") {
    if(goalTyp == "Euros") {
      //dollars to euros
      p = 0.9018*c;
    } 
    if(goalTyp == "Pounds") {
      //dollars to pounds
      p = c*0.7614;
    } 
    if(goalTyp == "Dollars") {
       p = c;
    }

  }
  if (currTyp == "Pounds") {
    if(goalTyp == "Dollars") {
      p = (1/0.7614)*c;
    } 
    if (goalTyp == "Euros") {
      p = (1/0.7614)*0.9018*c;
    } 
    if(goalTyp == "Pounds") {
      p = c;
    }
  } 
  
  cout << p;
  return 0;
}

