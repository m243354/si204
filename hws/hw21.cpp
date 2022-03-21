#include <iostream>
#include <fstream>

using namespace std;

void assignPoints(ifstream& file, int n, double *list) {
  string t;
  file >> t;
  for(int p=0; p<n; p++) {
    file >> list[p];
  }
}

void printPoints(int n, double *xlist, double *ylist) {
  for(int p=0; p<n; p++) {
    cout << '(' << xlist[p] << ", " << ylist[p] << ") ";
  }
}

int main() {
  string filename, t;
  cin >> filename;
  ifstream f(filename);
  int n;
  f >> t >> t >> n;
  
  double *Xcord = new double[n];
  double *Ycord = new double[n];
  
  assignPoints(f, n, Xcord);
  assignPoints(f, n, Ycord);
  
  printPoints(n, Xcord, Ycord);
  return 0;
}
