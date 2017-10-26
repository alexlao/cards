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
	Node *ptr;
	Deck *myDeck;
	myDeck = genDeck(5);
	ptr = myDeck->head;
	while(ptr!=NULL){
		printf("Card Value %d\n", ptr->cardValue);
		ptr = ptr->next;
	}
	freeDeck(myDeck);
}