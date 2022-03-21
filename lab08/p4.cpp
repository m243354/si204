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

int getMax(int* arr, int sz) {
  int max = arr[0];
  for(int i =1; i<sz; i++) {
    if(arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

//takes in int array pointer and size and couts entire array
void print(int* arr, int sz) {
  cout << '\n';
  int max = getMax(arr, sz);
  //figure out how to print proper amount of hastags
  for(int r = max; r>0; r--) {
    for(int i=0; i<sz; i++) {
      cout << " ";
      if(arr[i] >= r) {
        cout << '#';
      } else {
        cout << " ";
      }
    }
    cout << '\n';
  }
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
  } else if(n=="cycleleft") {
    return 3;
  }else if(n == "reverse") {
    return 2;
  } else {
    //error case
    cout << "Unknown move '" << n << "'\n";
    return -1;
  }
}

void swap(int* arr, char pos1, char pos2) {
  //swap positions 1 and 2 in array arr
  int p1 = pos1-65, p2 = pos2-65;
  int temp = arr[p1];
  arr[p1] = arr[p2];
  arr[p2] = temp;
}

void cycle(int* a, int n, int t) {
  for(int i=0;i<t; i++) {
    swap(a, i+65, n-1+65);
  }
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
    //2 possibliites for cmd; 1 or 0.1 is help 2 is swap
    if(cmd == 1) {
      //help
      cout << "PutInOrder!  The goal is to order from smallest to largest with the lowest score.\nThe moves are:\nswap x y    - swaps the values in column x and column y\nScoring: swap = 3pts\n";
      //print(a,n);
    } else if(cmd == 3) {
      //cycleLeft swaps first and last in the array
      int times;
      cin >> times;
      cycle(a, n, times);

      score++;
    }else if(cmd == 2){
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
        for(int i=0; i<diff+1; i++) {
          swap(a, holder[i], a[x+i-65]);
        }
        score += 2;
      }
      //print(a,n);
    } else {
      //swap was given so read next chars;
      cin >> x >> y;
      score += 3;
      turns++;
      swap(a, x, y);
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
