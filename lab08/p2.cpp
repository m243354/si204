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
  cout << '\n';
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

int readCmd() {
  //tries to read a command from the user and returns an  integer based on the command
  string n;
  cout << "> ";
  cin >> n;
  int ret;
  if(n == "help") {
    return 1;
  } else if(n=="swap") {
    return 0;
  } else if(n == "reverse") {
    return 2;
  } else {
    //error case
    cout << "Unknown move '" << n << "'\n";
    return -1;
  }
}

void swap(int* arr, int p1, int p2) {
  //swap positions 1 and 2 in array arr
  int temp = arr[p1];
  arr[p1] = arr[p2];
  arr[p2] = temp;
}

int main() {
  cout << "Welcome to PutInOrder!\n";
  bool play = true;
  cout << "board> ";
  //take in N and create my array for game from gena
  int n, cmd = -1, turns= 0, score = 0;
  int *holder;
  char c;
  cin >> c >> c >> n >> c;
  int *a = read(n);
  print(a,n);
  char x,y;


  while(play){
    cmd = readCmd();
    while (cmd == -1) {
      print(a,n);
      cmd = readCmd();
    }
    //2 possibliites for cmd; 1 is help, 0 is swap, 2 is reverse
    if(cmd == 1) {
      //help
      cout << "PutInOrder!  The goal is to order from smallest to largest with the lowest score.\nThe moves are:\nswap x y    - swaps the values in column x and column y\nScoring: swap = 3pts\n";
      //print(a,n);
    } else if(cmd == 2){
      //reverse move. check if args are good
      cin >> x >> y;
      if(x<y) {
        int diff = y-x;
        holder = new int[diff+1];
        int k= 0;
        for (int i = diff; i >= 0; i--) {
          holder[k] = a[x+i-65];
          k++;
        }

        //holder is reverse then swap everything
        for(int i=0; i<(diff+1)/2; i++) {
          //a[x-65] is the first character to pick. If X is a, this yields 0.
          //swaps first a with first holder.
          swap(a, x+i-65, y-65-i);
        }
        score += 2;
        turns++;
      }

    } else {
      //swap was given so read next chars;
      cin >> x >> y;
      score += 3;
      turns++;
      swap(a, x-65, y-65);
      //print(a,n);
    }
    print(a,n);

    //check if it is in order and delete it
    if(isInOrder(a,n)) {
      cout << score << " points! (" << turns << " moves)\n";
      play = false;
    }
  }
  delete [] a;
  delete [] holder;

  return 0;
}
