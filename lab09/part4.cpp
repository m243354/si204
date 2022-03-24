#include <iostream>
#include <fstream>

using namespace std;

void printNice(int** pgmArr) {
  int h = pgmArr[0][1], w = pgmArr[0][0];
  for(int y=1; y<h; y++) {
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

  for(int y=1; y<h; y++) {
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
  for(int y=h-1; y>=1; y--) {
    xPos = 0;
    result[y] = new int[w];
    for(int x=w-1; x>=0; x--) {
      int val = pgmArr[yPos][xPos];
      result[y][x] = val;
      xPos++;
    }
    yPos++;
  }
  return result;
}

void test(int h, int w) {
  int xPos = 0, yPos = 1;
  for(int y=1; y<w; y++) {
    yPos = 0;
    for(int x=0; x<h; x++) {
      cout << "goal x: "<< x << " goal y: " << y << " current x: "<< xPos << " current y: " << yPos << '\n';
      yPos++;
    }
    xPos++;
  }
}

int** merge(int** pgmArr, int** pgmArr2) {
  int w = pgmArr[0][0], h = pgmArr[0][1];
  int** result = new int*[h+1];
  //assign header
  result[0] = new int[2];
  result[0][0] = w;
  result[0][1] = h;

  for(int y=1; y<h; y++) {
    result[y] = new int[w];
    for(int x=0; x<w; x++) {
      int val = (pgmArr[y][x] + pgmArr2[y][x])/2;
      //set avg value
      result[y][x] = val;
    }
  }
  return result;
}

int** stripes(int** pgmArr, int** pgmArr2, int sCount) {
  int w = pgmArr[0][0], h = pgmArr[0][1];
  int** result = new int*[h+1];
  //assign header
  result[0] = new int[2];
  result[0][0] = w;
  result[0][1] = h;

  int strLen = w/sCount;
  cout << strLen;
  cout << " strlen % 2 = " << strLen % 2;
  int strCount = 0;
  int val;
  for(int y=1; y<h; y++) {
    result[y] = new int[w];
    for(int x=0; x<w; x++) {
      if(strCount < strLen) {
        int val = pgmArr[y][x];
        strCount++;
      } else {
        int val = pgmArr2[y][x];
        strCount++;
        if(strCount > strLen*2) {
          strCount = 0;
        }
      }
      result[y][x] = val;
    }
  }
  return result;
}

int** rotate(int** pgmArr) {
  int w = pgmArr[0][0], h = pgmArr[0][1];
  int** result = new int*[h+1];
  //assign header
  result[0] = new int[2];
  //swap h and w for this
  result[0][0] = h;
  result[0][1] = w;
  int xPos = 0, yPos = 1;
  for(int y=1; y<w; y++) {
    result[y] = new int[h];
    yPos = 0;
    for(int x=0; x<h; x++) {
      result[y][x] = pgmArr[yPos][xPos];
      yPos++;
    }
    xPos++;
  }
  return result;
}


void savePGM(int** pgmArr, string name) {
  ofstream f(name);
  int h = pgmArr[0][1], w = pgmArr[0][0];
  f << "P2\n";
  f << w << " " << h << '\n' << 255 << '\n';
  for(int y=1; y<h; y++) {
    for(int x=0; x<w; x++) {
      f << pgmArr[y][x] << "\t";
    }
    f << '\n';
  }
}

int main() {
  /* code */
  string fn, of;
  cout << "filename: ";
  cin >> fn;
  cout << "output filename: ";
  cin >> of;

  int** pgm = pgmToArr(fn);
  int** rot = rotate(pgm);

  //printNice(pgm);
  //printNice(poster);
  //test(10, 10);

  savePGM(rot, of);

  return 0;
}
