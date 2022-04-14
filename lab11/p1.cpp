#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "easycurses.h"
using namespace std;

int main() {
  startCurses();

  // Draw 4 digit characters to the terminal screen.
 drawChar('A', 0, 0);
 refreshWindow();
 usleep(800000);

 drawChar('B', 20, 30);
 refreshWindow();
 usleep(800000);

 drawChar('C', 20, 31);
 refreshWindow();
 usleep(800000);

 drawChar('D', 15, 50);
 refreshWindow();
 cerr << "Printed a D!" << endl;
 // Loop forever until user enters 'q'
 char c;
 do {
   c = inputChar();
 } while ( c!= 'q' );

  endCurses();
  return 0;
}
