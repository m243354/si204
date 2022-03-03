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

//writes char C, K times to file
void rep(char c, int k, ostream& OUT) {
  for(int i=0; i<k; i++) {
    OUT << c;
  }
}
//writes char C, K times to screen
void rep(char c, int k) {
  for(int i=0; i<k; i++) {
    cout << c;
  }
}

//writes to file and offsets properly. copy of the one that prints to screen
void writefrac(int num, int den, ostream& OUT) {
  int temp = length(den);
  int offset;
  if(length(num) != temp) {
    offset = temp/2;
    if(num < 0) {
      offset--;
    }
  } else {
    offset = 0;
  }
  rep(' ', offset, OUT);
  OUT << num << '\n';
  rep('-',temp, OUT);
  OUT << '\n';
  OUT << den;
}

//writes to screen. 
void writefrac(int num, int den) {
  int temp = length(den);
  //cout << temp << '\n';
  int offset;
  //calculate the offset. if they are the same length the offset is zero. If
  //not, it is half of denominator length. Also account for negative sign if
  //numerator is less than zero.
  if(length(num) != temp) {
    offset = temp/2;
    if(num < 0) {
      offset--;
    }
  } else {
    offset = 0;
  }
  //cout << offset << '\n';
  rep(' ', offset);
  cout << num << '\n';
  rep('-',temp);
  cout << '\n';
  cout << den;
}

int main() {
  //pp is pp in the string and end is a filename or screen
  string pp, end;
  //char for slash and the num and denom to give to my functions
  char c;
  int num, den;
  cin >> pp >> num >> c >> den >> end;
  //if checks work

  if(end != "screen") {
    //open file
    fstream file(end);
    writefrac(num,den,file);
    //no file error checking
  } else {
    writefrac(num, den); 
  }
  return 0;
}
