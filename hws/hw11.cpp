#include <iostream>
#include <fstream>

using namespace std;

int main() {
  //throwaway and data string. num for data and name for filename
  string foo, dat;
  double avg;
  int hw, quiz, exam;
  
  ifstream f("input.txt");
  //skip header
  f >> foo >> foo >> foo >> foo;
  //read important numbers and cout avg and name of person
  while(f >> dat >> hw >> quiz >> exam) {
    avg = (hw*.2+quiz*.2+exam*.6); 
    cout << dat << " " << avg << '\n';
  }
    

  return 0;
}
