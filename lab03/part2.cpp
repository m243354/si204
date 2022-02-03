#include <iostream>
#include <string>
using namespace std;

int main() {
  //take input currency and currency type
  double c, p;
  string currTyp, currTyp2, goalTyp, goalTyp2, t;
  //sometimes we will have convert c currTyp US/Canadian t goalTyp US/Canadian
  cin >> t >> c >> currTyp;
  if (currTyp == "Dollars") {
    cin >> currTyp2 >> t >> goalTyp;
    currTyp = currTyp+" "+currTyp2;
    if (goalTyp == "Dollars") {
      cin >> goalTyp2;
      goalTyp = goalTyp+" "+goalTyp2;
    }
  } else {
    cin >> t >> goalTyp;
    if(goalTyp == "Dollars") {
      cin >> goalTyp2;
      goalTyp = goalTyp+" "+goalTyp2;
    }
  }
  //makes it so if type is same, no reassignment occurs
  p = c;
  
  //conversion steps
  if(currTyp == "Euros") {
    if(goalTyp == "Dollars US") {
      //euro to usd
      p = (1/0.9018)*c;
    }
     
    if(goalTyp == "Pounds") {
      //goal type has to be pounds. euros to dollars then to pounds
      p = c*(1/0.9018)*0.7614;
    } 
    if(goalTyp == "Dollars Canadian") {
      //euro to usd to canadian
      p = (1/0.9018)*1.3156*c;
    }
    
  } 
  if(currTyp == "Dollars US") {
    if(goalTyp == "Euros") {
      //dollars to euros
      p = 0.9018*c;
    } 
    if(goalTyp == "Pounds") {
      //dollars to pounds
      p = c*0.7614;
    } 
    if(goalTyp == "Dollars Canadian") {
      p = c*1.3156;
    }

  }
  if (currTyp == "Pounds") {
    if(goalTyp == "Dollars US") {
      p = (1/0.7614)*c;
    } 
    if (goalTyp == "Euros") {
      p = (1/0.7614)*0.9018*c;
    } 
    if (goalTyp == "Dollars Canadian") {
      p = (1/0.7614)*1.3156*c;
    }
  } 
  if(currTyp == "Dollars Canadian") {
    if(goalTyp=="Euros") {
      //canadian to usd to euros
      p=(1/1.3156)*c*0.9018;
    }
    if(goalTyp =="Dollars US") {
      p=(1/1.3156)*c;
    }
    if(goalTyp == "Pounds") {
      p=(1/1.3156)*c*0.7614;
    }
  }

  cout << p;
  return 0;
}

