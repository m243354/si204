#include <iostream>
#include <fstream>

using namespace std;

//finds string in a list of string called search. returns -1 if nothing is found
int findIndex(string find, string* search, int n) {
  for(int i=0; i<n; i++) {
    if(find == search[i]) {
      return i;
    }
  }
  return -1;
}

void printList(string* arr, int n) {
  for(int i=0; i<n; i++) {
    cout << arr[i] << " ";
  }
}

void printList(char* arr, int n) {
  for(int i=0; i<n; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  string file;
  cin >> file;
  ifstream f(file);

  int n;
  char c;
  char* cArr;
  string* wordArr;
  f >> c >> c >> n;
  cArr = new char[n];
  wordArr = new string[n];
  for(int i=0; i<n; i++) {
    f >> wordArr[i];
  }
  for(int i=0; i<n; i++) {
    f >> cArr[i];
  }


  //read in word sequence and store it in output
  string output = "", word;
  while(cin >> word && word != ".") {
    output += cArr[findIndex(word, wordArr, n)];
  }
  cout << output;



  return 0;
}
