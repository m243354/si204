#include <iostream>
using namespace std;

int toSeconds(int hours, int minutes, int seconds) {
  int e =(hours*60 + minutes)*60 + seconds; 
  return e;
}

int main()
{
  cout << "Enter first time: ";
  int t1;
  int h1, m1, s1;
  char c1;
  cin >> h1 >> c1 >> m1 >> c1 >> s1;
  t1 = toSeconds(h1,m1,s1); 

  cout << "Enter second time: ";
  int t2;
  int h2, m2, s2;
  char c2;
  cin >> h2 >> c2 >> m2 >> c2 >> s2;
  t2 = toSeconds(h2,m2,s2);

  int ellapsed = t2 - t1;
  cout << "Ellapsed time is " << ellapsed << " seconds" << endl;

  return 0;
}
