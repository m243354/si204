#include "node.h"

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
