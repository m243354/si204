#ifndef GEORGE
#define GEORGE
/*****************************************
 ** Class def's and function prototypes
 *****************************************/
// Defines the nodes in our linked list
struct Node
{
  int data;
  Node* next;
};

// Inserts a new node with data val at the front of LIST
void add2front(int val, Node* &LIST);

#endif
