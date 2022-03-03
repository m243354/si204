/************************************************
 ** This program reads in two temperatures, both
 ** greater than 0C/32F and less than 360C/680F,
 ** and it outputs the change in energy (in
 ** kilo joules) of 1kg of water going from the
 ** initial temp to final.
 ** NOTE: this program needs the file enth.txt.
 ************************************************/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  // Read initial temperature
  cout << "Initial temperature: ";
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
  
  // Read final temperature
  cout << "Final temperature: ";
  double Tf, tf;
  char uf;
  cin >> tf >> uf;
  if (uf == 'C')
    Tf = tf;
  else if (uf == 'F')
    Tf = (tf - 32.0)*5.0/9.0;
  else {
    cout << "Bad unit '" << uf << "'!" << endl;
    exit(1); // exits program from anywhere!
  }

  // Get enthalpy difference
  if (Tf < Ti)
  {
    // swap high and low so Tf > Ti
    double Tforig = Tf;
    Tf = Ti;
    Ti = Tforig;

    // find enthalpy delta
    ifstream fin("enth.txt");
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

    // output delta (account for swapping with minus sign!)
    cout << "change in energy of 1 kg water is " << -delta << "kj" << endl;
  }
  else
  {
    // find enthalpy delta
    ifstream fin("enth.txt");
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
    cout << "change in energy of 1 kg water is " << delta << "kj" << endl;
  }
  
  
  return 0;
}

