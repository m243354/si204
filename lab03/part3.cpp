#include <iostream>

using namespace std;

int main() {
  //3 points and throwaway char
  double p0,p1, n0,n1, r0,r1;
  char q;
  
  //nasty
  cin >>q>>p0>>q>>p1>>q;
  cin >>q>>n0>>q>>n1>>q;
  cin >>q>>r0>>q>>r1>>q;
  // I must find the largest x values and y values
  //to draw the corners of the box.
  //left x and top y coordinates, top left x and y... continued
  double leftX, topY, rightX, bottomY;
  
  //find smallest x value 
  if(p0 < n0 && p0 < r0) {
    leftX = p0;
  } else if (n0 < p0 && n0 < r0) {
    leftX = n0;
  } else {
    leftX = r0;
  }
  //largest X value
  if(p0 > n0 && p0 > r0) {
    rightX = p0;
  } else if(n0 > p0 && n0 > r0) {
    rightX = n0;
  } else {
    rightX = r0;
  }
  //largest Y value
  if(p1 > n1 && p1 > r1) {
    topY = p1;
  } else if(n1 > p1 && n1 > r1) {
    topY = n1;
  } else {
    topY = r1;
  }
  //smallest Y value
  if(p1 < n1 && p1 < r1) {
    bottomY = p1;
  } else if(n1 < p1 && n1 < r1) {
    bottomY = n1;
  } else {
    bottomY = r1;
  }


  //drawing the box. 
  cout <<leftX<<" "<<bottomY<<'\n';
  cout <<leftX<<" "<<topY<<'\n';
  cout <<rightX<<" "<<topY<<'\n';
  cout <<rightX<<" "<<bottomY<<'\n';
  cout <<leftX<<" "<<bottomY<<"\n\n";
  
  cout<<p0<<" "<<p1<<'\n';
  cout<<n0<<" "<<n1<<'\n';
  cout<<r0<<" "<<r1<<'\n';
  cout<<p0<<" "<<p1<<'\n';
  return 0;
}
