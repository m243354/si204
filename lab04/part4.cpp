#include <iostream>
#include <fstream>

using namespace std;

int main() {

  string filename, outname, foo, date, time, maxDate, minDate, checkDay;
  cin >> filename >> outname;
  ifstream fin(filename);
  ofstream out(outname);
  
  if(!fin) {
    cout<< "Could not open file '" << filename << "'\n";
    return 1;
  }
  

  //calculate avg temp in fahrenheit
  double t, min = 1000, max = 0, sum = 0;
  int count = 0, days = 0;
  
  fin>>foo>>foo;
  //r and q are throwaways. T is temp and sum is temp sum that will divide by
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
    
    //output data
    //outputs data to same row unless checkday has changed.
    if(date != checkDay) {
      checkDay = date;
      //start a new row and output the first t with a tab at the end.
      //this check prevents first line from having a newline
      if(days == 0) {
        out << date << '\t' << t;
      } else {
        out << '\n' << date << '\t' << t;
      }
      
      days++;
    
    } else {
      //continue outputting ts on the row
      out << '\t' << t;
    }

    count++;
  }
  


  cout << "file: " << filename;
  cout << "\nave: " << (sum/count);
  cout << "\nmin: " << min << " on "<< minDate;
  cout << "\nmax: " << max << " on " << maxDate;
  cout << "\noutput in: " << outname;

  return 0;
}
