#include <iostream>

using namespace std;

double sqr(double z) {
  return z*z;
}

bool absme(int &k) {
  if(k<0) {
    k *= -1;
    return true;
  } else {
    return false;
  }
}


int main() {
  double x = 2.25;
  int n = 2;
  string s = "hard";
  int *A = new int[3];
  A[0] = 6; A[1] = 9; A[2] = 8;
  string *B = new string[2];
  B[0] = "hi"; B[1] = "bye";
  double *X = new double[3];
  X[0]= 5.1; X[1] = 5.4; X[2] = 5.7;

  cout << X[0] << '\n';
  cout << A[1]-x << '\n';
  A[0] = X[n];
  cout << A[0] << '\n';
  cout << ++A[2] << '\n';
  cout << B[1][0] << '\n';
  cout << A[1]+X[1] << '\n';
  cout << sqr(A[0]) << '\n';
  cout << sqr(X[0]) << '\n';
  cout << absme(A[0]) << '\n';
  //cout << A[0] << '\n';
  return 0;
}
