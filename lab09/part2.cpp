#include <iostream>
#include <fstream>

using namespace std;

void printNice(int** pgmArr) {
  int h = pgmArr[0][1], w = pgmArr[0][0];
  for(int y=1; y<h+1; y++) {
    for(int x=0; x<w; x++) {
      cout << pgmArr[y][x] << " ";
    }
    cout << '\n';
  }
}

int** pgmToArr(string filename) {
  ifstream f(filename);
  string t;
  //skip the p2
  f >> t;
  //width and height
  int w, h, temp;
  //get width height and 255
  f >> w >> h >> temp;
  int** pgmArr = new int*[h+1];
  pgmArr[0] = new int[2];
  pgmArr[0][0] = w;
  pgmArr[0][1] = h;
  //first row of the pgm arr will have the width and height;
  for(int y=1; y<h; y++) {
    pgmArr[y] = new int[w];
    for(int x=0; x<w; x++) {
      f >> temp;
      pgmArr[y][x] = temp;
    }
  }
  return pgmArr;
}

int** posterize(int** pgmArr) {
  int w = pgmArr[0][0], h = pgmArr[0][1];
  int** result = new int*[h+1];
  //assign header
  result[0] = new int[2];
  result[0][0] = w;
  result[0][1] = h;

  for(int y=1; y<h+1; y++) {
    result[y] = new int[w];
    for(int x=0; x<w; x++) {
      int val = pgmArr[y][x];
      if(val > 128) {
        val = 255;
      } else {
        val = 0;
      }
      result[y][x] = val;
    }
  }
  return result;
}

int** mirror(int** pgmArr) {
  int w = pgmArr[0][0], h = pgmArr[0][1];
  int** result = new int*[h+1];
  //assign header
  result[0] = new int[2];
  result[0][0] = w;
  result[0][1] = h;

  // for(int y=1; y<h; y++) {
  //   result[y] = new int[w];
  //
  // }

  int yPos = 1, xPos;
  for(int y=h; y>=1; y--) {
    xPos = 0;
    result[y] = new int[w];
    for(int x=0; x<w; x++) {
      int val = pgmArr[yPos][xPos];
      result[y][x] = val;
      xPos++;
    }
    yPos++;
  }
  return result;
}

void test(int h, int w) {
  int yPos = 1, xPos;
  for(int y=h; y>=1; y--) {
    xPos = 0;
    for(int x=w-1; x>=0; x--) {
      cout << "current X: " << xPos << " Current y: " << yPos << '\n';
      cout << "goal X: " << x << " goal Y: " << y << '\n';
      xPos++;
    }
    yPos++;
  }
}


void savePGM(int** pgmArr, string name) {
  ofstream f(name);
  int h = pgmArr[0][1], w = pgmArr[0][0];
  f << "P2\n";
  f << w << " " << h << '\n' << 255 << '\n';
  for(int y=1; y<h+1; y++) {
    for(int x=0; x<w; x++) {
      f << pgmArr[y][x] << "\t";
    }
    f << '\n';
  }
}

void delPGM(int** pgmArr) {
  int h = pgmArr[0][1], w = pgmArr[0][0];
  for(int y=0; y<h+1; y++) {
    delete [] pgmArr[y];
  }
  delete [] pgmArr;
}

int main() {
  /* code */
  string fn, of;
  cout << "filename: ";
  cin >> fn;
  cout << "output filename: ";
  cin >> of;

  int** pgm = pgmToArr(fn);
  int** poster = mirror(pgm);
  //printNice(pgm);
  //printNice(poster);
  //test(10, 10);

  savePGM(poster, of);

  return 0;
}
