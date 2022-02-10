#include <iostream>
#include <fstream>

using namespace std;

int main() {
  double bal = 0, payCheck = 550, intibal = 700, saverate = 4, loanrate = 14, eodBal = 0;
  int maxWeek, maxDay;
  
  string r, file;
  
  if(!(cin >> r >> maxWeek >> file) || r != "run") {
    cout << "Expected : run N file\n";
    return 1;
  }
  
  
  
  bal = intibal;
  maxDay = maxWeek*7.0;
 
  for(int d=1;d<=maxDay;d++) {
    if(d%14==13) {
      //pay day is every 13th day. should be 12 but the plus one for starting at
      //1 fixes it.
      bal += payCheck;
    }
    //calculate end of day balance for each day
    eodBal += bal;
  }
  

  cout<<"Ending balance = "<<bal;
  cout<<"\nAverage end-of-day balance = "<< (eodBal/maxDay) << '\n';


  return 0;


}
