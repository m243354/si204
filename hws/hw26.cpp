#include <iostream>

using namespace std;

int* readInts(int n) {
  int* intList = new int[n];
  for(int i=0; i<n; i++) {
    cin >> intList[i];
  }
  return intList;
}

int indexOfMax(int *A, int N)
{
  int imax = 0;
  for(int i = 1; i < N; i++) {
    if (A[imax] < A[i]) {
      imax = i;
    }
  }
  return imax;
}

void selectionsort(int *A, int N) {
  for(int length = N; length > 1; length--) {
    int k = indexOfMax(A,length);
    if(A[k] % 2 != 0) {
      //if A[k] is largest odd number, then move it to this position
      swap(A[k],A[(length/2)-1]);
      //need to go from n/2 to 0.
    } else {
      //if a [k] is largest even number, then move it to this position
      swap(A[k],A[length-1]);
      //need to go from
    }
  }
}

int* selectionsort2(int *A, int n) {
  int* newL = new int[n];
  int oddPos = n/2-1;
  int evenPos = n-1;
  cout << "odd: " << oddPos << " e: " << evenPos << '\n';
  while((evenPos > n/2) && oddPos > 0) {
    int k = indexOfMax(A,n);
    cout << "A[k] = " << A[k];
    if(A[k] % 2 != 0) {
      //if A[k] is largest odd number, then move it to the last position of odd numbers
      newL[oddPos] = A[k];
      oddPos--;
      //need to go from n/2-1 to 0.
    } else {
      //if a [k] is largest even number, then move it to this position
      newL[evenPos] = A[k];
      evenPos--;
      //need to go from n-1 to n/2.
    }

  }
  return newL;
}

void print(int *list, int n) {
  for(int i=0; i<n; i++) {
    cout << list[i];
    if(i < n-1) {
      cout << " ";
    }
  }
}

int main() {
  //read in ints
  int n = 10;
  int* sortThis = readInts(n);
  int* sorted = selectionsort2(sortThis, n);
  print(sorted, n);
  //if A
  return 0;
}
