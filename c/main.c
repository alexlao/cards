#include "library.h"

int main(int argc, char *argv[]){
	Node *deck,*ptr;
	deck = genDeck(5);
	ptr = deck;
	while(ptr!=NULL){
		printf("Card value %d\n", ptr->cardValue);
		ptr = ptr->next;
	}
	freeDeck(deck);
}