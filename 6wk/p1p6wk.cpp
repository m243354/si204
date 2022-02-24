#include <iostream>

//Dwight Kinney
//m243354

using namespace std;

int main() {
  //cost for final cost, wt for package weight, q throwayway and type for
  //package type
  double cost;
  int wt;
  char q;
  string type;

  //format (x)oz type
  cin >> wt >> q >> q >> type;
  //ONLY VALid input
  if(wt<5) {
    wt = 5;
  }
  if(type == "standard") {
    cost = wt*0.03;
  } else if (type == "express+") {
    cost = wt*0.08;
  } else {
    cost = wt*0.05;
  }

  cout << "$" << cost;

  return 0;
}
