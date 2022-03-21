#include <iostream>
//Dwight Kinney
//m243354 sus among us

using namespace std;

//reads in from user into param and returns an int array pointer for array of
//size param with each value filled by the user
int* read(int param) {
  int *temp = new int[param];
  
  for(int i=0; i<param; i++) {
    cin >> temp[i];
  }


  return temp;
}

//takes in int array pointer and size and couts entire array
void print(int* arr, int sz) {
  for(int i=0; i<sz; i++) {
    cout << " " << arr[i];
  }
  cout << " \n";
  for(int i=0; i<sz*2; i++) {
    cout << "-";
  }
  cout << "-\n";
  for(int i=65; i<(sz+65); i++) {
    cout << " " << char(i);
  }
  cout << " \n";
}

//returns true or false. Takes in array pointer and size and returns true if it
//is in order
bool isInOrder(int *arr, int sz) {
  bool order = true;
  int lastSub = arr[0];
  for(int i=1; i<sz; i++) {
    if(arr[i] < lastSub) {
      order = false;
      i=sz;
      //quit loop because it is not in order.
    }
    lastSub= arr[i];
  }
  return order;
}

int main() {
  //take in N and create my array
  int n;
  char c;
  cin >> c >> c >> n >> c;
  int *a = read(n);

  //cout the array
  print(a,n);
  
  //check if it is in order and delete it  
  if(isInOrder(a,n)) {
    cout << "Is in order!\n";
  } else {
    cout << "Is not in order!\n";
  }
  delete [] a;

  return 0;
}
