#ifndef GEORGENODE
#define GEORGENODE
#include <iostream>

using namespace std;

struct Node {
  char data;
  Node* next;
};

struct sNode {
  string* data;
  sNode* next;
};

int getLinkListLen(Node* firstNode);

void printLinkList(Node* firstNode);

void printLinkListRev(Node* firstNode);

void addNode(Node* &lastNode, char data);

//from course notes
void deleteFirstNode(Node* &L);
//from course notes
void deleteList(Node* L);


//same thing for a string* node
int getLinkListLen(sNode* firstNode);

void printLinkList(sNode* firstNode);

void printLinkListRev(sNode* firstNode);

void addNode(sNode* &lastNode, string* data);

//from course notes
void deleteFirstNode(sNode* &L);
//from course notes
void deleteList(sNode* L);

#endif
