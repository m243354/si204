/******************************************
 ** This is a simple program that reads
 ** ints from the user as long as they're
 ** positive, storing them in a linked list
 ** as we go, and prints out the last two
 ** positive numbers entered.
 ******************************************/
#include <iostream>
#include "node.h"
using namespace std;


int main() {
  // Initialize LIST to the empty list
  Node *LIST = 0;

  // Read in int's and add to LIST while they're positive
  cout << "Enter a list of positive numbers, terminated by zero:" << endl;
  int x;
  while(cin >> x && x > 0)
    add2front(x,LIST);

  // Print out the last 2!
  cout << "The last number was " << LIST->data << endl;
  cout << "The next to last number was " << LIST->next->data << endl;

  return 0;
}
