#include <iostream>
#include <fstream>

using namespace std;

/**************************************************************************************
 Input: pat - a string representing a meeting time, e.g. "MWF2,R34" or "TR9" or "MF5,T65"
        day - a char, one of M,T,W,R,F
        per - an int, one of the regular periods, i.e. 1,2,3,4,5,6
 Output:true if the meeting time in pattern pat overlaps with period day,per, false otherwise
        Ex1 - overlaps("MWF2,R12",'M',8) -> true     overlaps("TR10",'T',4) -> false
**************************************************************************************/
bool overlaps(string pat, char day, int per)
{
  bool dflag = false; // day match flag
  for(int i = 0; i < pat.length(); i++)
  {
    if (pat[i] == ',')
      dflag = false;
    else if ('A' <= pat[i] && pat[i] <= 'Z')
      dflag = dflag || pat[i] == day;
    else
    {
      int q = pat[i] == '1' && i+1 < pat.length() && pat[i+1] == '0' ? 10 : (pat[i] - '0');
      if (dflag && (per == q || (per-1)/2 + 8 == q))
	return true;
    }
  }
  return false;
}




int main() {
  string input = "", class;
  while(input != "quit") {
    cin >> input >> class;
    
  }


  return 0;
}
