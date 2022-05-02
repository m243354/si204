#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
//Dwight Kinney
//243354
char** readLetter(ifstream& fin) {
  // Read A
  char** L = new char*[4];
  for(int i = 0; i < 4; i++)
    L[i] = new char[7];
  for(int i = 0; i < 4;i++)
  {
    for(int j = 0; j < 7; j++)
      L[i][j] = fin.get();
    while(fin.get() != '\n');
  }
  return L;
}

void deleteLetter(char** L) {
  for (int i = 0; i < 4; i++)
    delete [] L[i];
  delete [] L;

}
void printLetter(char** L, bool newline=true) {
  for(int i = 0; i < 4;i++)  {
    for(int j = 0; j < 7; j++)
      cout << L[i][j];
    cout << endl;
  }
  if(newline) {
    cout << endl;
  }
}

int main()
{
  ifstream fin("letters.txt");
  char** L0 = readLetter(fin);
  char** L1 = readLetter(fin);
  char** L2 = readLetter(fin);
  char** L3 = readLetter(fin);

  // Print N
  printLetter(L1);
  printLetter(L0);
  printLetter(L2);
  printLetter(L3, false);

  deleteLetter(L0);
  deleteLetter(L1);
  deleteLetter(L2);
  deleteLetter(L3);

  return 0;
}
