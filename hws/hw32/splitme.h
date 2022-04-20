#ifndef GEORGE
#define GEORGE
#include <iostream>

using namespace std;

// represents one data measurement
struct Datum {
  double weight;
  int day; // numbered from start of trial, i.e. day 1 is first day
};

// Represents one test subject by a single name and a number of
// data measurements.  NOTE: data measurements are not required
// to be in time-sorted order!
struct Subject {
  string name;
  Datum* data;
  int num;
};

// read a single Datum object formatted <weight>@<day>, e.g. 180.5@7
Datum readDatum(istream& in);

// read in a single Subject formatted as shon in the following example
// George 4 209@30 245@1 239@5 221@13
void read(istream& in, Subject &s);

// enforces increasing order by day only
bool before(Datum a, Datum b);

// returns the biggest per-day drop in weight for a subject, assuming
// we linearly interpolate between consecutive readings
double biggestPerDayDrop(Subject s);

// sorts an array of N Datum objects in ascending day order
void selectionSort(Datum* A, int N);

#endif
