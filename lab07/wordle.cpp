#include <iostream>
#include <fstream>
#include <ctime>
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

//check is valid word
bool validWord(string word, string filename, int fileLength) {
  fstream f(filename);
  string s;
  for(int i=0; i<fileLength; i++) {
    f >> s;
    if(s == word) {
      return true;
    }
  }
  return false;
}

void compareWord(string word, string guess) {
  string cword = word, cguess = guess;
  markmatch(cguess,cword);
  for(int i = 0; i < cguess.length(); i++)
    marksemimatch(i,cguess,cword);
  //cout << word << endl;
  cprintstr(guess,cguess);
  cout << endl;
}

string pickAnswer(string file, int fileLength) {
  fstream f(file);
  string ansWord;
  srand(time(0));
  int rando = rand() % fileLength;
  //cout << rando << '\n';
  for(int i=0; i<rando; i++) {
    f >> ansWord;
  }
  return ansWord;
}

int main() {
    
  string word, ansWord, wordleFile = "words.txt";
  int attempts, WORDSTXTLENGTH = 4594;
  bool win = false;
  
  ansWord = pickAnswer(wordleFile, WORDSTXTLENGTH);
  cout << ansWord << '\n';
  
  //now play WORDLE;
  for(int i=0; i<5; i++) {
    cout << ": ";
    cin >> word;
    if(validWord(word, wordleFile, WORDSTXTLENGTH)) {
      cout << i+1 << " ";
      compareWord(ansWord, word);
      if(word == ansWord) {
        attempts = i+1;
        i=5;
        win = true;
      }
      
    } else {
      cout << "Not a valid word!\n";
      //give guess back
      i--;
    }
  }
  if(win) {
    cout << "You got the word in: " << attempts << " guesses.";
  } else {
    cout << "> " << ansWord << endl;
  }


  return 0;
}
