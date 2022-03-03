/************************************************
 ** This program reads in two temperatures, both
 ** greater than 0C/32F and less than 360C/680F,
 ** and it outputs the change in energy (in
 ** kilo joules) of 1kg of water going from the
 ** initial temp to final.
 ** NOTE: this program needs the file enth.txt.
 ************************************************/

//Dwight Kinney
//243354

#include <iostream>
#include <fstream>
using namespace std;

double readTemp(string prompt) {
  cout << prompt;
  double Ti, ti;
  char ui;
  cin >> ti >> ui;
  if (ui == 'C')
    Ti = ti;
  else if (ui == 'F')
    Ti = (ti - 32.0)*5.0/9.0;
  else {
    cout << "Bad unit '" << ui << "'!" << endl;
    exit(1); // exits program from anywhere!
  }
  return Ti;
}

void swap(double &a, double &b) {
  double r = a;
  a = b;
  b = r;
}

void readData(string filename, double Ti, double Tf, int posNeg) {
 // find enthalpy delta
    ifstream fin(filename);
    bool foundi = false, foundf = false;
    double tlow, elow, thigh, ehigh, first, second;
    fin >> tlow >> elow;
    while(!foundf && fin >> thigh >> ehigh)
    {
      if (!foundi && tlow <= Ti && Ti < thigh)
      {
	first = (ehigh - elow)*(Ti - tlow)/(thigh - tlow) + elow;
	foundi = true;
      }
      else if (foundi && tlow <= Tf && Tf < thigh)
      {
	second = (ehigh - elow)*(Tf - tlow)/(thigh - tlow) + elow;
	foundf = true;
      }
    }
    double delta = second - first;

    // output delta
    cout << "change in energy of 1 kg water is " << posNeg*delta << "kj" << endl; 
}

int main() {
  // Read initial temperature
  double initT = readTemp("Initial temperature: ");
      
  // Read final temperature
  double finalT = readTemp("Final temperature: ");
  
  // Get enthalpy difference
  if (finalT < initT) {
    // swap high and low so Tf > Ti
    swap(finalT, initT);
    readData("enth.txt", finalT, initT, 1);
  } else {
    readData("enth.txt", finalT, initT, -1);
  }
  
 //my numbers are barely off. I think I am getting some loss of accuracy
 //somewhere but I can't find it. What is going on. Bruhhh
  

  return 0;
}

