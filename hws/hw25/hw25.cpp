#include <iostream>
using namespace std;

void tri(int n, int level);
void rep(char c, int k);
void repsep(char c, int k);
//Dwight Kinney
//m243354

int main()
{
  tri(8,8);
  return 0;
}

//create a triangle
void tri(int n, int level)
{
  if (level == 0)
    return;
  tri(n,level-1);
  rep(' ',level);
  repsep('*',1 + n - level);
  cout << endl;
}

//print out the space characters
void rep(char c, int k) {
  if (k > 0)
  {
    cout << c;
    rep(c,k-1);
  }
  //base case is k = 0
}

//print out the dashes and stars for each row
void repsep(char c, int k) {
  if(k == 1) {
    //print out the final star without a dash
    cout << c;
    return;
  }
  //print out a star with a dash and keep going
  cout << c << '-';
  repsep(c, k-1);
}
