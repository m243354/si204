#include <iostream>

using namespace std;

// \033[1;32m is green until \033[0m
// \033[1;33m is yellow until \033[0m
// \033[1;37m is white until \033[0m
// prints a char c based on color k.
void cprintchar(char c, char k) {
  if(k == '*') {
    cout << "\033[1;32m" << c << "\033[0m";
  } else if(k == '+') {
    cout << "\033[1;33m"<< c << "\033[0m";
  } else {
    cout << "\033[1;37m"<< c << "\033[0m"; 
  }
}

//splits a string s up and prints it out based on color codes given in a string
//m of equal length. Feeds into cprintchar.
void cprintstr(string s, string m) {
  for(int i=0; i<m.length(); i++) {
    char c = s[i];
    char k = m[i];
    cprintchar(c, k);
  }
}

//takes two strings of the same length and replaces matching characters with
//atersisk in both strings
void markmatch(string &s1, string &s2) {
  for(int i=0; i<s1.length(); i++) {
    if(s1[i] == s2[i]) {
      s1[i] = '*';
      s2[i] = '*';
    }
  }

}

//returns the index of the first occurrence of c in string s. If it does not
//occur, it returns a -1.
int findfirst(char c, string s) {
  for(int i=0; i<s.length(); i++) {
    if(s[i] == c) {
      return i;
    }
  }
  return -1;
}

//two strings that have been output of markmatch are given to this. If the same
//characters are found they are marked with the plus character. position doesn't
//matter. Ignore the aterisks
void marksemimatch(int k, string &s1, string &s2) {
  //look at k index.
  char pick = s1[k];
  //cout << "searching for: " << pick << '\n';
  for(int p=0; p<s2.length(); p++) {
    //go into s2 and look for the pick. If it matches there is a plus added.
    if(pick != '*' && s2[p] == pick) {
      s2[p] = '+';
      //I make sure to update s1 with a plus at the k index if there is a match
      s1[k] = '+';
      //quit the loop because a match was found
      p = s2.length();
      //cout << "\nmatch found in s2 of index: " << p;
    }
  }
}


int main() {
  //part 1 code for cprintchar
  cout << "[";
  cprintchar('a', '*');
  cprintchar('b', '.');
  cprintchar('c', '+');
  cout << "]\n";
  
  //part 2 code for print colored string
  string w1 = "festering";
  string m1 = "l++g*ab+*";
  cout << "[";
  cprintstr(w1,m1);
  cout << "]" << endl;
  string w2 = "levelwises";
  string m2 = "**ug++b*er";
  cout << "[";
  cprintstr(w2,m2);
  cout << "]" << endl;
  
  //part 3 code
  string s1 = "livingstone";
  string s2 = "riverratses";
  cout << s1 << endl << s2 << endl;
  markmatch(s1,s2);
  cout << s1 << endl << s2 << endl;
  
  //part 4 code
  string u = "favoritism";
  cout << findfirst('f',u) << endl; // f is 1st letter (index 0)
  cout << findfirst('x',u) << endl; // x not in word
  cout << findfirst('i',u) << endl; // must find first i
  
  //part 5 code
  cout << "i = 0 ... semi-match found" << endl;
  string v1 = "react";
  string v2 = "drear";
  cprintstr(v1,"*...."); cout << " " << v2 << endl;
  marksemimatch(0,v1,v2);
  cout << v1 << " " << v2 << endl;
  cout << "i = 1 ... no semi-match found" << endl;
  string x1 = "tarry";
  string x2 = "scone";
  cprintstr(x1,".*..."); cout << " " << x2 << endl;
  marksemimatch(1,x1,x2);
  cout << x1 << " " << x2 << endl;
  cout << "i = 2 ... ignore *'s" << endl;
  string y1 = "cr*st";
  string y2 = "sc*ne";
  cprintstr(y1,"..*.."); cout << " " << y2 << endl;
  marksemimatch(2,y1,y2);
  cout << y1 << " " << y2 << endl;

  return 0;
}
