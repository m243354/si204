#include "lab12.h"
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

void printLinkList(Node* firstNode) {
  for(Node *p = firstNode; p != NULL; p = p->next) {
    cout << "(" << p->data.txt << " " << p->data.num << ") ";
  }
  cout << '\n';
}

Node* newNode(Node* lastNode, int number, string txt) {
  Node* n = new Node;
  n->data.num = number;
  n->data.txt = txt;
  n->next = lastNode;
  return n;
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

void nodeStats(Node* P, int numToEnd, int numToStart) {
  cout << "Before is: ";
  if(P!= NULL) {
    Node* n = P;
    for(int i=0; i<numToStart; i++) {
      cout <<  "(" << n->data.txt << " " << n->data.num << ") ";
      n = n->next;
    }
  }
  cout << '\n';
  cout << "Number after is: " << numToEnd << '\n';
  if(P!=NULL) {
    cout << P->next->data.txt << endl;
    for(int i=0; i<numToEnd-1; i++) {
      cout << i;
      P = P->next;
      cout << P->data.txt << " ";
    }
  }
  cout << "Current is: " << "(" << P->data.txt << " " << P->data.num << ")\n";
  // cout << "Number after is: " << numToEnd << '\n';
  cout << "[a]ccept or [r]eject: ";
  cout << '\n';
}
