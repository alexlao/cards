#ifndef LIBRARY_H
#define LIBRARY_H
#include <stdio.h>
#include <stdlib.h>
typedef struct nodeStruct Node;
struct nodeStruct{
	int cardValue;
	Node *next;
};
Node *genDeck(int size);
void freeDeck(Node *list);
#endif