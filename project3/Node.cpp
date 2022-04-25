#include "Node.h"
#include <iostream>

using namespace std;

int getLinkListLen(Node* firstNode) {
  int count = 0;
  for(Node *curr = firstNode; curr != NULL; curr = curr->next)  {
     // record that we've visited the node pointed to by curr
     count++;
  }
  return count;
}

void printLinkListRev(Node* firstNode) {
  if(firstNode == NULL) {
    return;
  }
  printLinkListRev(firstNode->next);
  if(firstNode->data != 'Z') {
    cout << firstNode->data;
  } else {
    cout << ' ';
  }
}

void printLinkList(Node* firstNode) {
  //ignore printing the Zs
  for(Node *p = firstNode; p != NULL; p = p->next) {
    cout << p->data;
  }
  cout << '\n';
}

void addNode(Node* &lastNode, char data) {
  Node* n = new Node;
  n->data = data;
  n->next = lastNode;
  lastNode = n;
}

//from course notes
void deleteFirstNode(Node* &L) {
  Node *T = L;
  L = L->next;
  delete T;
}
//from course notes
void deleteList(Node* L) {
  while(L != NULL) {
    deleteFirstNode(L);
  }
}
