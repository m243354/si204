#ifndef GEORGENODE
#define GEORGENODE
#include <iostream>

using namespace std;

struct NodeDat {
  int num;
  string txt;
};

struct Node {
  NodeDat data;
  Node* next;
};

int getLinkListLen(Node* firstNode);

void printLinkList(Node* firstNode);

Node* newNode(Node* lastNode, int number, string txt);

//from course notes
void deleteFirstNode(Node* &L);
//from course notes
void deleteList(Node* L);

void nodeStats(Node* P, int numToEnd, int numToStart);

#endif
