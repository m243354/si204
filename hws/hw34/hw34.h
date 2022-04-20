/******************************************
 ** This is a simple program that reads
 ** ints from the user as long as they're
 ** positive, storing them in a linked list
 ** as we go, and prints out the last two
 ** positive numbers entered.
 ******************************************/
#include <iostream>
using namespace std;

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
