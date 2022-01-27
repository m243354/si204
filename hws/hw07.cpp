#include <iostream>
#include <string>
using namespace std;

int main() {
  //vars
  string name, list = "NQ (not qualified)";
  double sqpr;
  int flag;
  char cond, mp, pe, prt, p;
  //read
  cin >> p >> name >> sqpr >> flag >> cond >> mp >> pe >> prt >> p;
  //checks for list
  
  if(sqpr>=3.4 && cond>='B' && mp>='B'){
    if((pe>='C') && (prt>='C')) {
      list = "Dean's List";
      //so many checks :-U... just gonna and them
      if((cond=='A') && (mp == 'A') && (pe>='B') && (prt >='B')) {
          list = "Superintendent's List";
      }
    }
  }
    

  cout << "Midshipman " << name <<": " << list;
}
