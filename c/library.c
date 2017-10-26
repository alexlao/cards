#include "library.h"

Deck *genDeck(int size){
	int i;/*
	Node *ptr;
	Node *head, *newNode;
	head = (Node*)malloc(sizeof(Node));
	head->cardValue = 0;
	head->next = NULL;
	ptr = head;
	for(i=1;i<size;i++){
		newNode = malloc(sizeof(Node));
		newNode->cardValue = i;
		newNode->next = NULL;
		ptr->next = newNode;
		ptr=ptr->next;
	}
	return head;*/
	Node *newNode;
	Deck *newDeck = (Deck*)malloc(sizeof(Deck));
	newDeck->deckSize = size;
	newDeck->head = (Node*)malloc(sizeof(Node));
	newDeck->head->cardValue =0;
	newDeck->tail = newDeck->head;
	for(i=1;i<size;i++){
		newNode = (Node*)malloc(sizeof(Node));
		newNode->cardValue = i;
		newNode->next=NULL;
		newDeck->tail->next=newNode;
		newDeck->tail = newNode;
	}
	return newDeck;
}

void freeDeck(Deck *list){
	Node *temp, *temp2;
	temp = list->head;
	while(temp!=NULL){
		temp2 = temp;
		temp = temp2->next;
		free(temp2);
	}
	free(list);
}