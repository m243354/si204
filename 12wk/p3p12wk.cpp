#include <iostream>
#include <fstream>

using namespace std;

//reads a file and produces a 2d table that can be read through later on
char** readFile(string filename) {
  ifstream f(filename);
  char** table = new char*[10];
  for(int i=0; i<10; i++) {
    table[i] = new char[10];
    for(int k=0; k<10; k++) {
      f >> table[i][k];
    }
  }
  return table;
}

void printTable(char** table) {
  cout << " ";
  for(int i=0; i<10; i++) {
    cout << " " << i;
  }
  cout << '\n';
  for(int i=0; i<10; i++) {
    cout << i << " ";
    for(int k=0; k<10; k++) {
      cout << table[i][k];
      if(k < 9) {
        cout << " ";
      }
    }
    cout << '\n';
  }
}

void printRow(char** table, int r) {
  for(int k=0; k<10; k++) {
    cout << table[r][k] << "";
  }
  cout << '\n';
}

void printCol(char** table, int c) {
  for(int k=0; k<10; k++) {
    cout << table[k][c] << "";
  }
  cout << '\n';
}

void printRevCol(char** table, int c) {
  for(int k=9; k>=0; k--) {
    cout << table[k][c] << "";
  }
  cout << '\n';
}

void printRevRow(char** table, int r) {
  for(int k=9; k>=0; k--) {
    cout << table[r][k] << "";
  }
  cout << '\n';
}


void processCmd(string cmd, char** table) {
  int param;
  cin >> param;
  if(cmd == "row") {
    printRow(table, param);
  } else if(cmd == "col") {
    printCol(table, param);
  } else if(cmd == "revcol") {
    printRevCol(table, param);
  } else if(cmd == "revrow") {
    printRevRow(table, param);
  }
}

int main() {
  string file, cmd;
  cin >> file;
  char** ref = readFile(file);
  printTable(ref);
  while(cin >> cmd && cmd != "quit") {
    processCmd(cmd, ref);
  }


  return 0;
}
