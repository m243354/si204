#include <iostream>

using namespace std;

struct Sus {
  string name, color;
  int degree;
};

int findIndex(Sus* s, string name, int n) {
  for(int i=0; i<n; i++) {
    if(s[i].name == name) {
      return i;
    }
  }
  return -1;
}

int main() {
  int n;
  char c;
  cin >> n;
  Sus* s = new Sus[n];
  for(int i=0; i<n; i++) {
    cin >> c >> s[i].name >> s[i].color >> s[i].degree;
  }

  string cmd, name, args;
  while(cin >> cmd) {
    if(cmd == "degree") {
      cin >> name >> args;
      int ind = findIndex(s, name, n);
      if(args == "up") {
        s[ind].degree++;
      } else {
        s[ind].degree--;
      }
    } else if (cmd == "color") {
      cin >> name >> args;
      int ind = findIndex(s, name, n);
      s[ind].color = args;
    } else if(cmd == "quit") {
      break;
    }
  }
  cout << n;
  for(int i=0; i<n; i++) {
    cout << " , " << s[i].name << ' ' << s[i].color << ' ' << s[i].degree;
  }

  delete [] s;
  return 0;
}
