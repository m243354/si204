#include <iostream>
#include <fstream>

//Dwight Kinney
//m243354

using namespace std;

int main() {
  double bal = 0, exp, payCheck = 550, intibal = 700, saverate = 4, loanrate = 14, eodBal = 0;
  int maxWeek, maxDay;
  
  string r, file;
  
  //checks if the format for the command is correct
  if(!(cin >> r >> maxWeek >> file) || r != "run") {
    cout << "Expected : run N file\n";
    return 1;
  }

  //now check if the file is valid
  fstream f(file);
  if(!f) {
    cout << "File \"" << file << "\" not found!\n";
    return 2;
  }
  //days of expenses from the file
  int expDay;
  //read in N, char equal sign, and n days.
  f >> r >> r >> expDay;
  
  if(expDay < maxWeek*7) {
    cout << "Insufficient values in \"" << file << "\"\n";
    return 3;
  }   
   
  
  
  
  bal = intibal;
  maxDay = maxWeek*7.0;
  //reuse expDay for the loop
  for(int d=1;d<=maxDay;d++) {
    if(d%14==13) {
      //pay day is every 13th day. should be 12 but the plus one for starting at
      //1 fixes it.
      bal += payCheck;
    }
    f >> exp;
    bal -= exp;
    //calculate end of day balance for each day
    eodBal += bal;
  }
  

  cout<<"Ending balance = "<<bal;
  cout<<"\nAverage end-of-day balance = "<< (eodBal/maxDay) << '\n';


  return 0;


}
