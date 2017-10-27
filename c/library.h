#ifndef LIBRARY_H
#define LIBRARY_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
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
void addCardTail(Deck *mod, int val);
void createCycles(int *completedArr, int *result);
int removeHead(Deck *original);
int lcm(int *arr);
int gcd(int n1, int n2);
#endif
