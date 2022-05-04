#include <iostream>
#include <fstream>

using namespace std;

struct dataPoint {
  string name;
  int id;
};

bool before(dataPoint a, dataPoint b) {
  return a.id > b.id;
}

//make search thingy and edit before to compare id values
void selectionsort(dataPoint *A, int N) {
  for(int length = N; length > 1; length--)
  {
    // Find imax, the index of the largest
    int imax = 0, i;
    for(i = 1; i < length; i++)
      if (before(A[imax],A[i]))
	imax = i;
    // Swap A[imax] & the last element
    dataPoint temp = A[imax];
    temp.id = A[imax].id;
    temp.name = A[imax].name;
    A[imax] = A[length - 1];
    A[length - 1] = temp;
  }
}


int main() {
  string fname;
  cin >> fname;
  ifstream f(fname);

  string dat;
  char c;
  int n;
  f >> c >> c >> n;
  dataPoint* dp = new dataPoint[n];
  for(int i=0; i<n; i++) {
    f >> dp[i].name >> dp[i].id;
  }
  selectionsort(dp, n);
  for(int i=0; i<n; i++) {
    cout << dp[i].name << " " << dp[i].id << '\n';
  }
  delete [] dp;
  return 0;
}
