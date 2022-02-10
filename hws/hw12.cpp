#include <iostream>

using namespace std;

int main() {
  //height and width and offset
  int hei, wid, offset;
  cout << "Enter height (greater than 2): ";
  cin >> hei;
  cout << "Enter width  (greater than 2): ";
  cin >> wid;
  cout << "Enter offset: ";
  cin >> offset;

  //this took me longer than I thought it would. I started with loops at 0 then
  //realized 1 is better for my checks later on so I switched. I run a check for
  //the cout based on 4 conditions. If it is the first row, cout *. If it is the
  //last row, cout aterisk. For the others, if it is the first column or last
  //column, cout atersik. For evertyhing else add a space. Then it worked.
  for(int r=1; r<=hei; r++) {
    for (int s=0; s<offset; s++) {
      cout << " ";
    }
    for(int c=1; c<=wid; c++) {
      //print out aterisk when r==1, r==hei, when c==1 when c == wid
      if(r==1 || r==hei || c == 1 || c == wid) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << "\n";
  }
  
    

  return 0;
}
