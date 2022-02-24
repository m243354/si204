#include <iostream>
#include <fstream>

//Dwight Kinney
//m243354

using namespace std;

int main() {
  double val, bal = 0, exp, payCheck = 550, intibal = 700, saverate = 4, loanrate = 14, eodBal = 0;
  int maxWeek, maxDay;
  char q;
  bool over = false;

  string r, file;
  //new check before to make sure we have run instead of another command
  cin >> r;
  if (r != "run") {
    //check if commands are given and then reset the variables
    //to the new conditions given
    if(!(r == "paycheck" || r == "initibal" || r== "saverate" || r == "loanrate")){
      cout << "Unknown command \"" << r << "\"\n";
      return 4;
    } else {
      //override new values
      //since the check before knows that it is one of these values, I have to
      //check and reassign before reading the next input
      cin >> q >> val;
      if(r == "initibal") {
        intibal = val;
      } 
      if(r == "loanrate") {
        loanrate = val;
      }
      if(r == "paycheck") {
        payCheck = val;
      }
      if(r == "saverate") {
        saverate = val;
      }
      while(cin >> r) {
        //read in input for the remaining values and replace them.
        if(!(r == "paycheck" || r == "initibal" || r == "saverate" || r == "loanrate")) {
          break;
        } else {
          cin >> q >> val;
        }
        if(r == "initibal") {
          intibal = val;
        } 
        if(r == "loanrate") {
          loanrate = val;
        }
        if(r == "paycheck") {
          payCheck = val;
        }
        if(r == "saverate") {
          saverate = val;
        }
        //figure out how to exit this loop
        //fixed
        
        
      }     
    }
  }   
  
 

  //old file check from earlier parts
  if(!(cin >> maxWeek >> file) || r != "run") {
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
  
  //cout
  cout << "initibal = " << intibal << '\n';
  cout << "paycheck = " << payCheck << '\n';
  cout << "saverate = " << saverate << '\n';
  cout << "loanrate = " << loanrate << '\n';
  
  
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
