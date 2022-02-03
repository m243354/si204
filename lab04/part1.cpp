#include <iostream>
#include <fstream>

using namespace std;

int main() {

  string filename, foo;
  cin >> filename;
  ifstream fin(filename);
  if(!fin) {
    cout<<"Could not open file '"<<filename<<"'\n";
    return 1;
  }

  //calculate avg temp in fahrenheit
  double t, sum = 0;
  int r, count = 0;
  char q;     

  fin>>foo>>foo;
  //r and q are throwaways. T is temp and sum is temp sum that will divide by
  //times this ran.
  while(fin >> r >> q >> r >> q >> r >> r >> q >> r >> q >> r >> t) {
    //convert t to fahrenheit
    t = (9*t)/5+32;
    sum += t;
    count++;
  }

  cout << "file: " << filename;
  cout << "\nave: " << (sum/count);



  return 0;
}
