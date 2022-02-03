//Dwight Kinney
//m243354
#include <iostream>

using namespace std;

int main() {
  //since we don't know how many things the user will enter, the tally will run
  //until the user stops putting input. B is toggle for equal sign to exit loop.
  //i is a temporary value and n is the number of inputs. q is char throwaway
  int tally,i,n;
  bool b = true;
  //q given starting value so it doesnt give weird errors.
  char q='a';
  tally=1;
  n=0;
  //
  while(b) {
    cin >> i >> q;
    //multiplies
    tally*=i;
    n++;
    if(q=='='){
      b=false;
    }

  }
  cout <<"The product of the "<<n<<" numbers entered is "<<tally;


}
