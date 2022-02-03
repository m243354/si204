#include <iostream>
#include <fstream>

using namespace std;

int main() {
  //variables that i'll use later
  string filename, foo, date, time, maxDate, minDate;
  cin >> filename;
  ifstream fin(filename);
  
  //if fin is false then it failed opening. If true then it worked.
  if(!fin) {
    cout<<"Could not open file '"<<filename<<"'\n";
    return 1;
  }
  

  //vars to compare to for max and min, sum for avg, and t for temp holder.
  double t, max = 0, min = 1000, sum = 0;
  int count = 0;


  fin>>foo>>foo;
  //date and time are throwaways. T is temp and sum is temp sum that will divide by
  //times this ran.
  while(fin >> date >> time >> t) {
    //convert t to fahrenheit
    t = (9*t)/5+32;
    if(t>max) {
      max = t;
      maxDate = date;
    }
    if(t<min) {
      min = t;
      minDate = date;
    }
    sum += t;
    count++;
  }

  cout << "file: " << filename;
  cout << "\nave: " << (sum/count);
  cout << "\nmin: " << min << " on "<< minDate;
  cout << "\nmax: " << max << " on " << maxDate;


  return 0;
}
