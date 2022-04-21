#include <iostream>
#include <fstream>

using namespace std;

struct Node {
  string data;
  Node* next;
};

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
    cout << p->data << " ";
  }
  cout << '\n';
}

Node* newNode(Node* lastNode, string data) {
  Node* n = new Node;
  n->data = data;
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



int main() {
  //get our filename and read in the data
  cout << "Input file is: ";
  string fname, dat;
  cin >> fname;
  ifstream f(fname);
  if(!f) {
    cout << "Error! File '" << fname << "' not found!";
    return 1;
  }

  //last node
  Node* P = NULL;

  //reading and storing the data
  while(f >> dat) {
    P = newNode(P, dat);
  }

  int datCount = getLinkListLen(P);
  cout << "Count is " << datCount << '\n';
  printLinkList(P);
  deleteList(P);

  return 0;
}
