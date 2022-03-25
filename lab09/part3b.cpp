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
  //width and heightg
  int w, h, temp;
  //get width height and 255
  f >> w >> h >> temp;
  int** pgmArr = new int*[h+1];
  pgmArr[0] = new int[2];
  pgmArr[0][0] = w;
  pgmArr[0][1] = h;
  //first row of the pgm arr will have the width and height;
  for(int y=1; y<h+1; y++) {
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

  //ypos counts up and the y counts down. x remains the same
  int yPos = 1;
  for(int y=h; y>0; y--) {
    result[y] = new int[w];
    for(int x=0; x<w; x++) {
      int val = pgmArr[yPos][x];
      result[y][x] = val;
    }
    yPos++;
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
  int totalStr = 0;
  //cout << strLen;
  //cout << " strlen % 2 = " << strLen % 2;
  int strCount = 0;
  int val = 0;
  for(int y=1; y<h+1; y++) {
    result[y] = new int[w];
    cout << "attempting read at result[" << y << "][n]\n";
    for(int x=0; x<w; x++) {
      if(strCount < strLen) {
        int val = pgmArr[y][x];
        strCount++;
        //cout << "this is the first picture " << strCount << " times \n";
      } else {
        int val = pgmArr2[y][x];
        //cout << "this is the second picture " << strCount << " times \n";
        strCount++;
        if(strCount > strLen*2) {
          strCount = 0;
          totalStr += 2;
        }
      }

      result[y][x] = val;
    }
  }
  cout << totalStr;
  return result;
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
  int h = pgmArr[0][1]+1;
  for(int y=0; y<h; y++) {
    delete [] pgmArr[y];
  }
  delete [] pgmArr;
}

int main() {
  /* code */
  string fn, fn2, of;
  int sco;
  cout << "file 1: ";
  cin >> fn;
  cout << "file 2: ";
  cin >> fn2;
  cout << "Number of strips: ";
  cin >> sco;
  cout << "output filename: ";
  cin >> of;
  //fn = "dog.pgm"; fn2 = "cat.pgm"; sco = 25; of = "scog.pgm";
  int** pgm = pgmToArr(fn);
  int** pgm2 = pgmToArr(fn2);
  int** merged = stripes(pgm, pgm2, sco);
  //printNice(pgm);
  //printNice(poster);
  //test(10, 10);

  savePGM(merged, of);

  delPGM(pgm);
  delPGM(pgm2);
  delPGM(merged);

  return 0;
}
