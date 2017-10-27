#include "library.h"
static int deckSizeSpec;
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
	deckSizeSpec = size;
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
	}/*
	for(z=0;z<16;z++){
		printf("Inside Array: %d\n", cleanArr[z]);
	}*/
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

void createCycles(int *completedArr, int *result){
	int i, index;
	
	for(i=0;i<deckSizeSpec;i++){
		index = i;
		while(completedArr[index]!=i){
			index = completedArr[index];
			result[i] = result[i]+1;
		}
	}
}
int lcm(int *factors){
	int product, i;
	product = 1;
	for(i=0;i<deckSizeSpec;i++){
		product = product *(factors[i]/ gcd(product,factors[i]));
	}
	return product;
}
int gcd(int n1, int n2){
	int z, gcd;
	for(z=1;z<=n1 && z<=n2 ;z++){
		if(n1%z==0 && n2%z==0){
			gcd = z;
			printf("gcd updated: %d", gcd);
		}
	}
	printf("GCD BETWEEN %d and %d: %d\n", n1,n2,gcd);
	return gcd;
}
