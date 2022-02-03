#include <iostream>
#include <fstream>

using namespace std;

int main() {

  string filename, foo;
  cin >> filename;
  ifstream fin(filename);
  if(!fin) {
    cout << "Could not open file '" << filename << "'\n";
    return 1;
  }

  //calculate avg temp in fahrenheit
  double t, sum = 0;
  int count = 0;     

  fin>>foo>>foo;
  //count keeps track of times this added to sum. foo gets rid of stuff
  //before the temperature
  while(fin >> foo >> foo >> t) {
    //convert t to fahrenheit
    t = (9*t)/5+32;
    sum += t;
    count++;
  }
  //output stuff
  cout << "file: " << filename;
  cout << "\nave: " << (sum/count);



  return 0;
}
