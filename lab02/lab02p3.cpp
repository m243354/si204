//Dwight Kinney
//243354
#include <iostream>

using namespace std;

int main() {
  //vars
  int perm, dig2, dig1, dig0;
  //input
  cout << "Permissions: \n";
  cin >> perm;
  int clone = perm;
  //get individual digits
  dig0 = perm % 10;
  perm /= 10;
  dig1 = perm % 10;
  perm /= 10;
  dig2 = perm % 10;
  perm /= 10;

  //take first digit and describe it as user permissions
  int rd, wr, ex;
  ex = dig2%2;
  dig2 /= 2;
  wr = dig2%2;
  dig2 /= 2;
  rd = dig2%2;

  cout << "User:"<<"\nread    "<<rd<<"\nwrite   "<<wr<<"\nexecute "<<ex<<"\n\n";

  //same process for group bit
  ex = dig1%2;
  dig1 /= 2;
  wr = dig1%2;
  dig1 /= 2;
  rd = dig1%2;
  cout << "Group:"<<"\nread    "<<rd<<"\nwrite   "<<wr<<"\nexecute "<<ex<<"\n\n"; 
  //same for other 
  ex = dig0%2;
  dig0 /= 2;
  wr = dig0%2;
  dig0 /= 2;
  rd = dig0%2;
  cout << "Other:"<<"\nread    "<<rd<<"\nwrite   "<<wr<<"\nexecute "<<ex<<"\n";


  return 0;
};
