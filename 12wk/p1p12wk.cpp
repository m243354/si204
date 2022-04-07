#include <iostream>
#include <fstream>

using namespace std;

int main() {
  //n is number of ints to read in and t is comparison value value, c temp
  int n, t;
  char c;
  cin >> n >> c;
  //fill the list
  int* intList = new int[n];
  for(int i=0; i<n; i++) {
    cin >> intList[i];
  }
  //read in cthe commparison char
  cin >> c >> t;


  //now print out the numbers from the file in an order that satisfies the condition

  int comp = t, index = 0;
  int* sol = new int[n];
  for(int i=0; i<n; i++) {
    if(c == '<') {
      //adds lower
      if(intList[i] < comp) {
        sol[index++] = intList[i];
      }
    } else {
      //adds higher
      if(intList[i] > comp) {
        sol[index++] = intList[i];
      }
    }

  }

  cout << "[ ";
  for(int i=0; i<index; i++) {
    cout << sol[i] << " ";
  }
  cout << "]";

  delete [] intList;

  return 0;
}
