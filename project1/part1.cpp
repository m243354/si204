#include <iostream>

using namespace std;

int main() {
  double bal, payCheck = 550, intibal = 700, saverate = 4, loanrate = 14;
  int maxDay;
  //r should always be 1.
  string r;
  if(!(cin >> r >> maxDay)) {
    cout << "Expected : run N file";
    return 1;
  }
  //I added 1 here to prevent any cases where 0 gets modded. I don't want that
  //to ruin the modulo checks. Sunday is 8. Friday is 6
  for(int d=1;d<(maxDay+1);d++) {
    if(d%12==0) {
      //pay day
      intibal += payCheck;
    }

  }

  cout<<"Ending balance = "<<bal;
  cout<<"\nAverage end of day balance = "<<'\n';


  return 0;


}
