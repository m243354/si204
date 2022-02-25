#include <iostream>
#include <fstream>

//Dwight Kinney
//m243354

using namespace std;

int main() {
  //variables schmariables
  double val, intr, bal = 0, exp, payCheck = 550, intibal = 700, saverate = 4, loanrate = 14, eodBal = 0;
  int maxWeek, maxDay;
  char q;

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
          cout << "Unknown command \"" << r << "\"\n";
          return 4;
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
  
  //checks if file has enough stuff
  if(expDay < maxWeek*7) {
    cout << "Insufficient values in \"" << file << "\"\n";
    return 3;
  }   
   
   //couts yayuz
  cout << "initibal = " << intibal << '\n';
  cout << "paycheck = " << payCheck << '\n';
  cout << "saverate = " << saverate << '\n';
  cout << "loanrate = " << loanrate; 
 
  
  bal = intibal;
  maxDay = maxWeek*7.0;
  //reuse expDay for the loop
  for(int d=1;d<=maxDay;d++) {
    //transfer interest and reset
    if(d-1 > 0) {
      if((d-1) % 30 == 0) {
        //black magic for every 31st day but not really. I did 31, 61, 91 but I
        //was getting 31, 62, 93... and I needed the difference between d and
        //last intrest day to be 30. This change to mod worked.
        bal += intr;
        intr = 0;
        //debug statement
        //cout << "\nInterest reset and desposited \n";
      }
    }  
    
    if(d%14==13) {
      //pay day is every 13th day. should be 12 but the plus one for starting at
      //1 fixes it.
      bal += payCheck;
    }
    
    //read expenses from file and subtract from bal 
    f >> exp; 
    bal -= exp;
    
    //calculate interest and add it to itself. loanrate is used for negative
    //balances and saverate for positive balances
    if(bal>0) {
      intr += bal * saverate/100 / 365;
    } else {
      intr += bal * loanrate/100 / 365; 
    }
    
      
    //calculate end of day balance for each day
    eodBal += bal;
    //debug
    //cout << "\nEnd of day "<<d<<": balance = "<<bal<<", interest = "<<intr;
  }
  
  cout<<"\nEnding interest = "<<intr;
  cout<<"\nEnding balance = "<<bal;
  cout<<"\nAverage end-of-day balance = "<< (eodBal/maxDay) << '\n';


  return 0;


}
