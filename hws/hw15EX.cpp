/*******************************************
 ** This program reads an integer from the
 ** user and prints out its factorization
 ** into irreducibles.  Unfortunately, I've
 ** been unable to figure out how to implement
 ** the function firstfactor, which takes an
 ** integer n, where n > 1, and returns the
 ** smallest factor of n, i.e. the smallest
 ** integer greater than 1 that divides n
 ** evenly.  You need to add the definition
 ** of firstfactor.
 *******************************************/
#include <iostream>
#include <cmath>

//Dwight Kinney
//m243354

using namespace std;

/*******************************************
 ** PROTOTYPE
 *******************************************/
int firstfactor(int);

/*******************************************
 ** MAIN FUNCTION
 *******************************************/
int main()
{
  // Get integer n, n > 1, from user
  int n;
  cout << "Enter an integer larger than 1: ";
  cin >> n;

  // Print out factorization
  cout << "The factorization of " << n << " is ";
  int lastN = 2;
  int nCount = 1;
  while(n > 1)
  {
    // get & print next irreducible factor
    int f = firstfactor(n);
    
    //if next factor equals lastN then we will add to nCount and print nothing.
    //When f changes the cout statement will come out properly and nCount is 0.
    if(lastN != f) {
      cout << '(' << lastN << ")^" << nCount; 
      nCount = 1;
      cout << '(' << f << ')';
       
    } else {
      //this means there was no change in lastN
      nCount++;  
    }   
    //set lastN
    lastN = f;
    n = n / f;
  }
  cout << endl;

  return 0;
}

/*******************************************
 ** FUNCTION DEFINITION
 *******************************************/

int firstfactor(int n) {
  //return the factors by brute force
  for (int i=1; i<=n; i++) {
    if(n%i == 0 && i!=1) {
      //debug
      //cout << "\nfor n: " << n << " factors: " << i << '\n'; 
      return i;
    }
  }
  //prime, so n is factor of n
  return n;
  
}

