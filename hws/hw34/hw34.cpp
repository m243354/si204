#include "hw34.h"

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

/*****************************************
 ** Function definitions
 *****************************************/
void add2front(int val, Node* &LIST)
{
  Node *temp = new Node;
  temp->data = val;
  temp->next = LIST;
  LIST = temp;
}
