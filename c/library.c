#include "library.h"

Deck *genDeck(int size){
	int i;
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
	free(list);
}

void oneRound(Deck *original, int *cleanArr){
	/*return the array of ints
	int deckArr[original->size];*/
	int i,z;
	i=original->deckSize - 1;
	while(original->head != NULL){
		int headVal = removeHead(original);
		printf("head val: %d\n", headVal);
		cleanArr[i]=headVal;
		printf("array head val: %d\n", cleanArr[i]);
		/*printf("New head Val: %d\n", original->head->cardValue);*/
		printf("deck size: %d\n", original->deckSize);
		if(original->head!=NULL){
			addCardTail(original, removeHead(original));
		}
		i--;
	}
	for(z=0;z<6;z++){
		printf("Inside Array: %d\n", cleanArr[z]);
	}
}	

int removeHead(Deck *modify){
	Node *temp;
	int returnVal = modify->head->cardValue;
	temp = modify->head->next;
	free(modify->head);
	modify->head = temp;
	modify->deckSize = modify->deckSize - 1;
	if(modify->deckSize==0){
		modify->head=NULL;
	}
	printf("Removing %d\n", returnVal);
	return returnVal;
}

void addCardTail(Deck *modify, int value){
	Node *newCard;
	if((newCard = (Node*)malloc(sizeof(Node)))==NULL){
		fprintf(stderr,"Out of memory");
		exit(-1);
	}
	newCard->cardValue = value;
	newCard->next = NULL;
	/*printf("Tail val: %d\n", modify->tail->cardValue);
	modify->tail->next = newCard;
	modify->tail = newCard;*/
	if(modify->deckSize == 0){
		modify->head=newCard;
		modify->tail=newCard;
	}
	else{
		modify->tail->next = newCard;
		modify->tail = newCard;
	}
	modify->deckSize = modify->deckSize + 1;
}

void addCardHead(Deck *modify, int value){
	Node *newCard;
	if((newCard = (Node*)malloc(sizeof(Node)))==NULL){
		fprintf(stderr,"Out of memory");
		exit(-1);
	}
	newCard->cardValue = value;
	newCard->next = NULL;

	newCard->next = modify->head;
	modify->head = newCard;
}
