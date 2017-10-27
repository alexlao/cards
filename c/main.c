#include "library.h"

int main(int argc, char *argv[]){
	/*Node *deck,*ptr;
	deck = genDeck(5);
	ptr = deck;
	while(ptr!=NULL){
		printf("Card value %d\n", ptr->cardValue);
		ptr = ptr->next;
	}
	freeDeck(deck);*/
	int i;
	Node *ptr;
	Deck *myDeck;
	int arr[16];
	int clean[16];
	myDeck = genDeck(16);/*
	addCardHead(myDeck, 100);
	addCardHead(myDeck, 1000);
	addCardTail(myDeck, 100000);*/
	ptr = myDeck->head;
	while(ptr!=NULL){
		printf("Card Value %d\n", ptr->cardValue);
		ptr = ptr->next;
	}

	printf("New deck\n");
	oneRound(myDeck,arr);
	for(i=0;i<16;i++){
		printf("New value: %d\n", arr[i]);
	}
	for(i=0;i<16;i++){
		clean[i] = 1;
	}
	createCycles(arr,clean);
	for(i=0;i<16;i++){
		printf("count: %d\n", clean[i]);
	}
	freeDeck(myDeck);
	return 0;
}
