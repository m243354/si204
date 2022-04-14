#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/* Prints out an array arr with elements separated by a space starting at index i and ending at index n*/
void printspaced(string* arr, int i, int n) {
  if(n-1==i) {
    //base case where we reach the end of the array. n-1 is last index so we stop there
    cout << arr[i];
  } else {
    cout << arr[i] << " ";
    printspaced(arr, i+1, n);
  }
}

//compares key values by doing some modifications. Takes in a int char value of the key name and a char for a flat or sharp symbol. If it isnt a
//flat or sharp symbol it is ignored and has no effect on the output
int keyToComp(int keyChar, char hS) {
  //returns an int value for the key to make comparison easier
  int halfStep = 0;
  if(hS == 'b') {
      halfStep = -1;
  } else if (hS == '#') {
      halfStep = 1;
  }

  switch(keyChar) {
    //c
    case 67:
      if(halfStep > 0) {
        keyChar+=halfStep;
      }
      break;
    //d
    case 68:
      keyChar++;
      if(halfStep != 0) {
        keyChar += halfStep;
      }
      break;
    //e
    case 69:
      keyChar = 71;
      if(halfStep != 0) {
        keyChar += halfStep;
      }
      break;
    case 70:
      keyChar = 72;
      if(halfStep != 0) {
        keyChar += halfStep;
      }
      break;
    case 71:
      keyChar = 74;
      if(halfStep != 0) {
        keyChar += halfStep;
      }
      break;
    case 65:
      keyChar = 76;
      if(halfStep != 0) {
        keyChar += halfStep;
      }
      break;
    case 66:
      keyChar = 78;
      if(halfStep != 0) {
        keyChar += halfStep;
      }
      break;
  }

  return keyChar;
}

/* returns true if string k comes before string s and false otherwise
comparison is done using the second index of k first then the first index or
if there is a sharp or flat it is done differently*/
bool before(string k, string s) {
  //int keyChr = k[0];
  int kVal = keyToComp(k[0], k[1]);
  int sVal = keyToComp(s[0], s[1]);
  //int keyChr = keytoComp(keyChr, halfStep);


  //COMPARING NUMBERS IS FIRST
  // k[k.lenght]
  int kLen = k.length(), sLen = s.length();
  if(k[kLen-1] != s[sLen-1]) {
    //if the numbers in the second index are not the same, then return the result of the comparison of the numbers
    return k[kLen-1] < s[sLen-1];
  } else {
    return kVal < sVal;
  }

}

//sorts an array of strings alphebetically of length n. uses selectionsort
void sort(string* arr, int n) {
  for(int k=n; k > 1; k--) {
    int imax = 0, i;
    for(i=1; i<k; i++) {
      if(before(arr[imax], arr[i])) {
        imax = i;
      }
    }
    swap(arr[imax], arr[k-1]);
  }
}

//searches an array of length n starting at index i, for a string and returns true if it is found and false if not
int search(string* arr, string find, int i, int n) {
  int findVal = keyToComp(find[0], find[1]);
  int fLen = find.length();
  for(int k=i; k<n; k++) {
    if(keyToComp(arr[k][0], arr[k][1]) == findVal) {
      if(arr[k][arr[k].length()-1] == find[fLen-1] )
      //also add a check for if the numbers are the same!!
        return k;
    }
  }
  return -1;
}


int main() {
  //variable setup
  string cmd, key;
  bool play = true;
  //max index to print to
  int keyLen = 0;
  //we assume there is never more than 12 keys on at the same time
  string* keyArr = new string[12];

  while (play) {
    cin >> cmd;
    if(cmd != "quit") {
      cin >> key;
    }

    int k = search(keyArr, key, 0, keyLen);
    if(cmd == "on") {
      //we will add the keys to our array. Keylen is the max index to print to so we increase it to see the results
      //this if prevents the same key from being added twice
      if(k == -1) {
        keyArr[keyLen++] = key;
      }

    } else if(cmd == "off"){
      //k is index of the key to turn off

      //if the array is greater than length 0 and  k is not negative 1,
      if(k > -1) {
        swap(keyArr[k], keyArr[keyLen-1]);
        keyLen--;
      }
      //cmd is off and array is greater than zero. else we do nothing

    } else if(cmd == "quit"){
      //quit command
      play = false;
      break;
    }
    sort(keyArr, keyLen);
    //we print out our array after every run
    cout << "[";
    if(keyLen > 0) {
      printspaced(keyArr, 0, keyLen);
    }
    cout << "]\n";
  }

  delete [] keyArr;

  return 0;
}
