#include "library.h"

int main(int argc, char *argv[]){
	if(argc!=2){
		fprintf(stderr,"Invalid input.\nUsage: ./calculateRounds [integer > 0]\n");
		return -1;
	}
	else{
		int size, i,leastMultiple;
   		long inputCheck;
   		Deck *myDeck;
   		int *arr,*clean;
		char *endptr = NULL;
		errno=0;

		/*Transform input parameter and validates the input*/
		inputCheck = strtol(argv[1], &endptr, 0);
		if(*endptr != '\0'){
			fprintf(stderr,"Invalid characters.\nUsage: ./calculateRounds [integer > 0]\n");
			return -1;
		}
		else if(errno == ERANGE){
			fprintf(stderr,"Numerical input causes integer overflow/underflow.\nUsage: ./calculateRounds [integer>0]\n");
			return -1;
		}
		else if(inputCheck <= 0){
			fprintf(stderr, "Invalid number.\nUsage: ./calculateRounds [integer>0]\n");
			return -1;
		}
		else if(inputCheck >INT_MAX){
			fprintf(stderr, "Numerical input causes integer overflow/underflow.\nUsage: ./calculateRounds [integer>0]\n");
			return -1;
		}
		size = inputCheck;
		myDeck = genDeck(size);
		arr = malloc(sizeof(int)*size);
		clean = malloc(sizeof(int)*size);
		oneRound(myDeck, arr);

		for(i=0;i<size;i++){
			clean[i]=1;
		}
		/*Determine cycle groups after one round and computes the LCM, which is the answer*/
		createCycles(arr,clean);
		leastMultiple = lcm(clean);
		freeDeck(myDeck);
		free(arr);
		free(clean);
		if(leastMultiple !=-1){
			printf("Rounds: %d\n", leastMultiple);
		}
		return 0;
	}
}
