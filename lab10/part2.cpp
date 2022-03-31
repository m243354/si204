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

//searches an array of length n starting at index i, for a string and returns true if it is found and false if not
int search(string* arr, string find, int i, int n) {
  for(int k=i; k<n; k++) {
    if(arr[k] == find) {
      return k;
    }
  }
  return -1;
}

/* returns true if string k comes before string s and false otherwise
comparison is done using the second index of k first then the first index */
bool before(string k, string s) {
  if(k[1] != s[1]) {
    //if the numbers in the second index are not the same, then return the result of the comparison of the numbers
    return k[1] < s[1];
  } else {
    //if the numbers are the same, then I return the comparison of the letters
    //cout << "comparing if " << k[0] <<  " is greater than " << s[0] << (k[0] > s[0]) <<'\n';
    if((k[0] != 'A' && k[0] != 'B') && (s[0] != 'A' && s[0] != 'B')) {
      //cout << "normal case \n";
      return k[0] < s[0];
    } else {
      //A val is 72
      //I have an A or b
      if(k[0] == 'A') {
        k[0] = char(72);
      }
      if(k[0] == 'B') {
        k[0] = char(73);
      }
      if(s[0] == 'A') {
        s[0] = char(72);
      }
      if(s[0] == 'B') {
        s[0] = char(73);
      }
      //cout << "comparing if " << k[0] <<  " is greater than " << s[0] << (k[0] > s[0]) <<'\n';
      return k[0] < s[0];

    }

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
