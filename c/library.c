#include "library.h"

Node *genDeck(int size){
	int i;
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
	return head;
}

void freeDeck(Node *list){
	Node *temp;
	while(list!=NULL){
		temp = list;
		list = list->next;
		free(temp);
	}
}