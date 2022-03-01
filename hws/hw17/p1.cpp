#include <iostream>
using namespace std;

// lenUnitCF(fromUnit,toUnit) - this function returns
// conversion factors between different units of length
// for units it understands, and returns 0.0 for units
// it does not understand.
// It understands: feet, inches, yards, miles, millimeters,
// centimeters, meters, kilometers, nautical-miles and light-years.
double lenUnitCF(string fromUnit, string toUnit);

double tooFeet(string fromUnit); // This jsut helps with lenUnitCF

int main() {
  string inp, unitg, unit1, unit2, op;
  double v1, v2;
  double sum;
  cin >> inp >> inp >> unitg >> v1 >> unit1 >> op >> v2 >> unit2 >> inp;
  //operation is stored, goal unit, and unit1 and values twice.
  sum = lenUnitCF(unit1, unitg)*v1 + lenUnitCF(unit2, unitg)*v2;
  cout << sum << " "<<unitg;
  

  return 0;
}

double lenUnitCF(string fromUnit, string toUnit)
{
  return tooFeet(fromUnit)/tooFeet(toUnit);
}

double tooFeet(string fromUnit)
{
  if (fromUnit == "feet") return 1.0;
  else if (fromUnit == "inches") return 1.0/12.0;
  else if (fromUnit == "yards") return 3.0;
  else if (fromUnit == "miles") return 5280;
  else if (fromUnit == "millimeters") return 0.00328084;
  else if (fromUnit == "centimeters") return 0.0328084;
  else if (fromUnit == "meters") return 3.28084;
  else if (fromUnit == "kilometers") return 3280.84;
  else if (fromUnit == "nautical-miles") return 6076.12;
  else if (fromUnit == "light-years") return 3.1038479e16;
  else return 0.0;
}

