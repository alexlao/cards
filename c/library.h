#ifndef LIBRARY_H
#define LIBRARY_H
#include <stdio.h>
#include <stdlib.h>
typedef struct nodeStruct Node;
struct nodeStruct{
	int cardValue;
	Node *next;
};
typedef struct deckStruct Deck;
struct deckStruct{
	int deckSize;
	Node *head;
	Node *tail;
};
Deck *genDeck(int size);
void freeDeck(Deck *list);
void oneRound(Deck *original, int *cleanArr);
void addCardHead(Deck *mod, int val);
void addCardTail(Deck *mod, int val);
void createCycles(int *completedArr, int *result);
int removeHead(Deck *original);

#endif
