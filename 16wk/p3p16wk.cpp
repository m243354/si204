#include <iostream>


using namespace std;

struct Node{
  double data;
  Node* next;
};

void addNode(Node* &lastNode, double data) {
  Node* n = new Node;
  n->data = data;
  n->next = lastNode;
  lastNode = n;
}

void printLinkList(Node* firstNode) {
  //ignore printing the Zs
  for(Node *p = firstNode; p != NULL; p = p->next) {
    cout << p->data << ' ';
  }
  cout << '\n';
}

void printLinkListRev(Node* firstNode) {
  if(firstNode == NULL) {
    return;
  }
  printLinkListRev(firstNode->next);
  if(firstNode->data != 'Z') {
    cout << firstNode->data << ' ';
  } else {
    cout << ' ';
  }
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

double doStats(Node* L, double y) {
  double total = 0;
  for(Node *p = L; p != NULL; p = p->next) {
    total += abs(p->data - y);
  }
  return total;
}


int main(){
  char c;
  double dat;
  Node* n = NULL;
  while(cin >> dat >> c) {
    addNode(n, dat);
    if(c == ';') {
      break;
    }
  }
  cin >> c >> c >> dat;
  cout << doStats(n, dat);
  deleteList(n);
  return 0;
}
