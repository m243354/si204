#include <iostream>
#include <fstream>

using namespace std;

int main() {
  //vars and file that we will write to and read from
  string filename, outname, foo, date, time, maxDate, minDate;
  cin >> filename >> outname;
  ifstream fin(filename);
  ofstream out(outname);
  
  if(!fin) {
    cout<<"Could not open file '"<<filename<<"'\n";
    return 1;
  }
  

  //calculate avg temp in fahrenheit
  double t, min = 1000, max = 0, sum = 0;
  int hr, count = 0;
  
  fin>>foo>>foo;
  out<<"day\t"<<"hour\t"<<"temp\n";
  //works the exact same as the other ones. there is now a writing component.
  //xd
  while(fin >> date >> hr >> time >> t) {
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
    hr += 1;    
    //output data
    out<<date<<'\t'<<hr<<'\t'<<t<<'\n';

    count++;
  }
  


  cout << "file: " << filename;
  cout << "\nave: " << (sum/count);
  cout << "\nmin: " << min << " on "<< minDate;
  cout << "\nmax: " << max << " on " << maxDate;
  cout << "\noutput in: " << outname;

  return 0;
}
