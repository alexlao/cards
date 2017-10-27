#include "library.h"

static int deckSizeSpec;

/*Generates a new deck filled with specified amount of cards*/
Deck *genDeck(int size){
	int i;
	Node *newNode;
	Deck *newDeck = (Deck*)malloc(sizeof(Deck));
	if(newDeck == NULL){
		fprintf(stderr, "Not enough memory to generate deck.\n");
		exit(-1);
	}
	newDeck->deckSize = size;
	newDeck->head = (Node*)malloc(sizeof(Node));
	if(newDeck->head==NULL){
		fprintf(stderr, "Not enough memory to generate deck.\n");
		exit(-1);
	}
	newDeck->head->cardValue =0;
	newDeck->tail = newDeck->head;
	for(i=1;i<size;i++){
		newNode = (Node*)malloc(sizeof(Node));
		if(newNode == NULL){
			fprintf(stderr,"Not enough memory to generate deck.\n");
			exit(-1);
		}
		newNode->cardValue = i;
		newNode->next=NULL;
		newDeck->tail->next=newNode;
		newDeck->tail = newNode;
	}
	deckSizeSpec = size;
	return newDeck;
}

/*Frees the deck*/
void freeDeck(Deck *list){
	free(list);
}

/*Stores the order of the deck in the postRound array after a round*/
void oneRound(Deck *original, int *postRound){
	int i;
	i=original->deckSize - 1;
	while(original->head != NULL){
		int headVal = removeHead(original);
		postRound[i]=headVal;
		if(original->head!=NULL){
			addCardTail(original, removeHead(original));
		}
		i--;
	}
}	

/*Removes the top card on the deck*/
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
	return returnVal;
}

/*Placing the drawn card at the end of a deck*/
void addCardTail(Deck *modify, int value){
	Node *newCard;
	if((newCard = (Node*)malloc(sizeof(Node)))==NULL){
		fprintf(stderr,"Out of memory");
		exit(-1);
	}
	newCard->cardValue = value;
	newCard->next = NULL;
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

/*Determines the rotational group sizes. 
Stores each card's size in its respective index in result*/
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

/*Computes the least common multiple of the rotational group sizes.
Returns -1 if the LCM causes overflow*/
int lcm(int *factors){
	int product, i,z;
	product = 1;
	for(i=0;i<deckSizeSpec;i++){
		int gcdValue = gcd(product,factors[i]);
		z = product * (factors[i]/ gcdValue);
		if(product!=0&&(z/product!=(factors[i]/gcdValue))){
			fprintf(stderr,"Too many rounds. Overflow occured.\n");
			return -1;
		}
		else{
			product = z;
		}
	}
	return product;
}

/*Computes the greatest common denominator. Used to find the LCM*/
int gcd(int n1, int n2){
	int z, gcd;
	for(z=1;z<=n1 && z<=n2 ;z++){
		if(n1%z==0 && n2%z==0){
			gcd = z;
		}
	}
	return gcd;
}

