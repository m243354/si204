#include "splitme.h"

// This program reads a single subject and reports that subject's
//  biggest per-day drop in weight
int main()
{
  Subject s;
  read(cin,s);
  cout << "Biggest per day weight drop is "
       << -(biggestPerDayDrop(s)) << endl;
  return 0;
}

Datum readDatum(istream& in)
{
  Datum d;
  char c;
  in >> d.weight >> c >> d.day;
  return d;
}

void read(istream& in, Subject &s)
{
  in >> s.name;
  in >> s.num;
  s.data = new Datum[s.num];
  char c;
  for(int i = 0; i < s.num; i++)
    s.data[i] = readDatum(in);
}
bool before(Datum a, Datum b)
{
  return a.day < b.day;
}

double aveDayDrop(Datum a, Datum b)
{
  double deltaw = b.weight - a.weight;
  double deltad = b.day - a.day;
  return deltaw/deltad;
}

double biggestPerDayDrop(Subject s)
{
  selectionSort(s.data,s.num);
  double min = aveDayDrop(s.data[0],s.data[1]);
  for(int i = 1; i < s.num - 1; i++)
  {
    double next = aveDayDrop(s.data[i],s.data[i+1]);
    if (next < min)
      min = next;
  }
  return min;
}

void selectionSort(Datum* A, int N)
{
  for(int length = N; length > 1; length--)
  {
    // Find imax, the index of the largest
    int imax = 0, i;
    for(i = 1; i < length; i++)
      if (before(A[imax],A[i]))
	imax = i;
    // Swap A[imax] & the last element
    Datum temp = A[imax];
    A[imax] = A[length - 1];
    A[length - 1] = temp;
  }
}
