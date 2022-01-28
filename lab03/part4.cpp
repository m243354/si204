#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
  double a,b,c;
  //temps for math
  double asArea, s, angleA, angleB, angleC, area;
  string tri0, tri1;
  bool triangle = true;

  cout << "Enter side lengths: ";
  cin >> a >> b >> c;

  //herons formula
  //calculate semiperimeter
  s = 0.5*(a+b+c);
  area = sqrt(s*(s-a)*(s-b)*(s-c));
  asArea = 2*area/(a*b*c);
  if(isnan(area) || area<=0) {
    triangle = false;
  }

  //check if valid triangle
  angleA = asin(asArea*a);
  angleB = asin(asArea*b);
  angleC = asin(asArea*c);
  
  angleA = (angleA*180)/M_PI;
  angleB = (angleB*180)/M_PI;
  angleC = (angleC*180)/M_PI;
  
  //triangle angle classification
  if(angleA<90 && angleB<90 && angleC<90) {
    tri0 = "acute";
  } else if(angleA==90 || angleB==90 || angleC==90) {
    tri0 = "right";
  } else {
    tri0 = "obtuse";
  }

  //triangle length classification
  if(a==b && b==c) {
  //if all side lengths are equal, it must be an equilateral triangle
    tri1 = "equilateral";
  } else if (a==b || b==c || c==a) {
    tri1 = "isosceles";
  } else {
    tri1 = "scalene";
  }
  

  if(triangle) {
    cout << "This is a " << tri0 << " " << tri1 << " triangle.";
  } else {
    cout << "Error! these lengths violate the triangle inequality!";
  }
   
  return 0;
}
