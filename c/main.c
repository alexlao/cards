#include "library.h"

int main(int argc, char *argv[]){
	/*int i;
	Node *ptr;
	Deck *myDeck;
	int lcmAns;
	int arr[16];
	int clean[16];
	myDeck = genDeck(16);*/
	if(argc!=2){
		fprintf(stderr,"Invalid input.\nUsage: ./calculateRounds [integer > 0]\n");
		return -1;
	}
	else{
		int size;
		int i;
   	Node *ptr;
   	Deck *myDeck;
   	int lcmAns;
   	int *arr;
   	int *clean;
		/*myDeck = genDeck(16);*/
		char *endptr = NULL;
		errno=0;
		size = strtol(argv[1], &endptr, 10);

		if(*endptr != '\0'){
			fprintf(stderr,"Invalid characters.\nUsage: ./calculateRounds [integer > 0]\n");
			return -1;
		}
		else if(errno == ERANGE){
			fprintf(stderr,"Underflow/Overflow occured.\nUsage: ./calculateRounds [integer>0]\n");
			return -1;
		}
		else if(size <= 0){
			fprintf(stderr, "Invalid number.\nUsage: ./calculateRounds [integer>0]\n");
			return -1;
		}
		printf("%d\n", size);	
		myDeck = genDeck(size);
		arr = malloc(sizeof(int)*size);
		clean = malloc(sizeof(int)*size);
		oneRound(myDeck, arr);

		for(i=0;i<size;i++){
			clean[i]=1;
		}

		createCycles(arr,clean);
		lcmAns = lcm(clean);
		freeDeck(myDeck);
		free(arr);
		free(clean);
		printf("Rounds: %d\n", lcmAns);
		return 0;
	}/*
	ptr = myDeck->head;
	while(ptr!=NULL){
		printf("Card Value %d\n", ptr->cardValue);
		ptr = ptr->next;
	}

	printf("New deck\n");*//*
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
	
	lcmAns = lcm(clean);
	freeDeck(myDeck);
	printf("LCM: %d\n", lcmAns);
	return 0;*/
}
