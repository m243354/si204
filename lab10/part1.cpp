#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// prints the elements of array A (that has N elements) from index i to the end
// should be space separated, and there should be a newline at the end.
void printspaced(int* A, int i, int N);

int main(int argc, char** argv) {
  // if run with a command-line argument x, seed with x (else use current time)
  srand(argc < 2 ? time(0) : atoi(argv[1]));

  // Create a randomish array to use as input to printspaced
  int N = 10 + rand() % 20, K = N / (2 + rand() % 5);
  int *A = new int[N];
  for(int i = 0; i < N; i++)
    A[i] = i % K;

  // Call printspaced (and cross fingers!)
  printspaced(A,0,N);

  return 0;
}

/* Prints out an array arr with elements separated by a space starting at index i and ending at index n*/

void printspaced(int* arr, int i, int n) {
  if(n-1==i) {
    //base case where we reach the end of the array. n-1 is last index so we stop there
    cout << arr[i];
  } else {
    cout << arr[i] << " ";
    printspaced(arr, i+1, n);
  }
}
