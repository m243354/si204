#include <iostream>
#include <fstream>

using namespace std;

//car struct
struct car {
  char tag;
  double location;
  double vel;
};


car* read(ifstream& f, int n) {
  char c;
  string foo;
  double pos, vel;
  car* carsArr = new car[n];

  //more variables to hold data to give to each car object
  for(int i=0; i<n; i++) {
    //read in each line of the file and give each car object the correct data
    f >> c >> foo >> pos >> foo >> vel;
    carsArr[i].tag = c;
    carsArr[i].location = pos;
    carsArr[i].vel = vel;
  }

  //return the filled array of car data
  return carsArr;
}

//prints out car data of n length across time hours.
void printCarDat(car* carArr, int time, int n) {
  for(int t=0; t<time; t++) {
    //counts hours
    cout << "hour " << t;
    for(int i=0; i<n; i++) {
      //print out the tag and position in a nice formatted position for each car in the array.
      double posOffset = carArr[i].vel*t;
      cout << "[" << carArr[i].tag << ":" << carArr[i].location+posOffset << "]";
    }
    cout << '\n';
  }
}


int main() {
  string fname;
  cin >> fname;
  ifstream f(fname);
  //variables for reading in data
  int n;
  char c;
  f >> c >> c >> n;

  car* myCars = read(f, n);
  printCarDat(myCars, 9, n);

  return 0;
}
