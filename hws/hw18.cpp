#include <iostream>
#include <fstream>

using namespace std;


int length(int n) {
  //given length function that returns length of an int by dividing it
  int m = n, l;
  for(l=0; m != 0; l++) {
    m /= 10;
  }
  return n <= 0 ? l + 1 : l;
}

//writes to file
void rep(char c, int k, ostream& OUT) {
  for(int i=0; i<k; i++) {
    OUT << c;
  }
}
//writes to screen
void rep(char c, int k) {
  for(int i=0; i<k; i++) {
    cout << c;
  }
}

//writes to file
void writefrac(int num, int den, ostream& OUT) {
  int temp = length(den);
  int offset;
  if(length(num) != temp) {
    offset = temp/2;
  } else {
    offset = 0;
  }
  rep(' ', offset, OUT);
  OUT << num;
  rep(' ',offset, OUT);
  OUT << '\n';
  rep('-',temp, OUT);
  OUT << '\n';
  OUT << den;
}

//writes to screen
void writefrac(int num, int den) {
  int temp = length(den);
  int offset;
  if(length(num) != temp) {
    offset = temp/2;
  } else {
    offset = 0;
  }
  rep(' ', offset);
  cout << num;
  rep(' ',offset);
  cout << '\n';
  rep('-',temp);
  cout << '\n';
  cout << den;
}

int main() {
  string pp, end;
  char c;
  int num, den;
  cin >> pp >> num >> c >> den >> end;
  //if checks work
  //

  if(end != "screen") {
    //open file
    fstream file(end);
    if(file) {
      writefrac(num,den,file);
    } else {
      cout << "Invalid file.";
      return 1;
    }
  } else {
    writefrac(num, den); 
  }
  return 0;
}
