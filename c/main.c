#include "library.h"

int main(int argc, char *argv[]){
	if(argc!=2){
		fprintf(stderr,"Invalid input.\nUsage: ./calculateRounds [integer > 0]\n");
		return -1;
	}
	else{
		int size, i,lcmAns;
   	Deck *myDeck;
   	int *arr,*clean;
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
		if(lcmAns !=-1){
			printf("Rounds: %d\n", lcmAns);
		}
		return 0;
	}
}
