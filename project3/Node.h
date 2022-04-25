#ifndef GEORGENODE
#define GEORGENODE
#include <iostream>

using namespace std;

struct Node {
  char data;
  Node* next;
};

int getLinkListLen(Node* firstNode);

void printLinkList(Node* firstNode);

void printLinkListRev(Node* firstNode);

void addNode(Node* &lastNode, char data);

//from course notes
void deleteFirstNode(Node* &L);
//from course notes
void deleteList(Node* L);

#endif
