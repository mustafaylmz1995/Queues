#include <stdio.h>
#include <stdlib.h> //malloc, calloc, realloc free


typedef struct Node {
	struct Node* next;
	struct Node* prev;
	int data;
} node;


typedef struct CircularDoublyLinkedList {
	node* head;
	node* tail;
	int nofElement;

}CDLL;


node *createnode(void) {
	node *newNode = (node*)malloc(sizeof(node));
	if (newNode == NULL) {
		return NULL;
	}
	else {
		newNode->next = NULL;
		newNode->prev = NULL;
		newNode->data = 0;
		return newNode;
	}
	
}
void startCircularDoublyLinkedList(CDLL *newCDLL) {
	node* head = createnode();
	node* tail = createnode();
	
	node* newNode = createnode();
	head = newNode;
	tail = newNode;


	newCDLL->head = head;
	newCDLL->tail = tail;

	newCDLL->head->next = tail;
	newCDLL->tail->prev = head;

	newCDLL->head->prev = tail;
	newCDLL->tail->next = head;

	newCDLL->nofElement = 1;


	return newCDLL;

}

node* insert2CDLL(CDLL* newCDLL, int insert_this) {
	node* dumyNode = createnode();
	if (dumyNode == NULL) {
		return NULL;
	}
	dumyNode->data = insert_this;
	dumyNode->next = newCDLL->head;
	dumyNode->prev = newCDLL->tail;

	newCDLL->head->prev = dumyNode;
	newCDLL->tail->next = dumyNode;
	newCDLL->nofElement++;

	return dumyNode;
}


void insertFirst2CDLL(CDLL *newCDLL, int insert_this) {
	newCDLL->head = insert2CDLL(newCDLL, insert_this);
}


void insertLast2CDLL(CDLL *newCDLL, int insert_this) {
	newCDLL->tail = insert2CDLL(newCDLL, insert_this);
}



void deleteFirst2CDLL(CDLL* newCDLL) {
	if (newCDLL->nofElement == 0) {
		printf("UNDERFLOW!!!\n");
		return;
	}
	else if (newCDLL->nofElement == 1) {
		printf("Head node can not be deleted!\n");
		return;
	}
	else {
		node* dumyNode = newCDLL->head;

		newCDLL->tail->next = newCDLL->head->next;
		newCDLL->head->next->prev = newCDLL->tail;

		newCDLL->head = newCDLL->head->next;
		newCDLL->nofElement--;

		dumyNode->next = NULL;
		dumyNode->prev = NULL;
		free(dumyNode);
	}

	if (newCDLL->nofElement == 1) {
		newCDLL->head->next = NULL;
		newCDLL->tail->next = NULL;
	}

}

void deleteLast2CDLL(CDLL* newCDLL) {
	if (newCDLL->nofElement == 0) {
		printf("UNDERFLOW!!!\n");
		return;
	}
	else if (newCDLL->nofElement == 1) {
		printf("Head node can not be deleted!\n");
		return;
	}
	else {
		node* dumyNode = newCDLL->tail;

		newCDLL->head->prev = newCDLL->tail->prev;
		newCDLL->tail->prev->next = newCDLL->head;

		newCDLL->tail = newCDLL->tail->prev;
		newCDLL->nofElement--;

		dumyNode->next = NULL;
		dumyNode->prev = NULL;
		free(dumyNode);
	}

	if (newCDLL->nofElement == 1) {
		newCDLL->head->next = NULL;
		newCDLL->tail->next = NULL;
	}
}


void display(CDLL* newCDLL) {
	int i = newCDLL->nofElement;
	node* newDumy = newCDLL->head;


	for (; i > 0; i--) {
		printf("%p\t%d\n", newDumy, newDumy->data);
		newDumy = newDumy->next;
	}
	printf("\n");
}



typedef enum {
	INPUT = 0,
	OUTPUT = 1
}restriction;

typedef enum {
	LEFT = 0,
	RIGHT = 1
}side;


typedef struct DEQUE {
	CDLL CDLinkedList;
	restriction io_restriction;
	side adjusted_side; //which side must be used
	side preferred_side;//which side is preferred
}deque;

void startDeque(deque* deq, restriction io_restr, side adj_side, side pref_side) {
	deq->io_restriction = io_restr;
	deq->adjusted_side = adj_side;
	deq->preferred_side = pref_side;

	startCircularDoublyLinkedList(&(deq->CDLinkedList));
}

void enque(deque* deq, side s, int insert_this) {
	if (s == LEFT) {
		insertFirst2CDLL(&(deq->CDLinkedList), insert_this);
	}
	else {
		insertLast2CDLL(&(deq->CDLinkedList), insert_this);

	}
}


void enqueue(deque *deq, int insert_this) {
	if (deq->io_restriction == INPUT) {
		//we can insert only adjusted side
		enque(deq, deq->adjusted_side, insert_this);
	}
	else {
		//we can insert any side
		enque(deq, deq->preferred_side, insert_this);
	}
}


void remove_deq(deque* deq, side s) {
	if (deq->CDLinkedList.nofElement == 0) {
		printf("UNDERFLOW!!!\n");
		return;
	}
	else if (deq->CDLinkedList.nofElement == 1) {
		printf("Node can not be deleted!\n");
		return;
	}
	if (s == LEFT)
		printf("The deleted element is %d\n", deq->CDLinkedList.head->data);
	else
		printf("The deleted element is %d\n", deq->CDLinkedList.tail->data);

	if (s == LEFT) {
		deleteFirst2CDLL(&(deq->CDLinkedList));
	}
	else {
		deleteLast2CDLL(&(deq->CDLinkedList));
	}
}

void dequeue(deque* deq) {
	if (deq->io_restriction == INPUT) {
		//we can delete any side
		remove_deq(deq, deq->preferred_side);
	}
	else {
		//we can delete just adjusted side
		remove_deq(deq, deq->adjusted_side);
	}
}


void _display(deque *deq) {
	display(&(deq->CDLinkedList));
}

int main(void) {

	deque deq;
	startDeque(&deq, INPUT, LEFT, LEFT);

	for (int i = 0; i < 11; i++) {
		enqueue(&deq,i);
	}
	display(&deq);

	
	deq.preferred_side = RIGHT; //delete from RIGHT side
	for (int i = 0; i < 5; i++) {
		dequeue(&deq);
	}
	display(&deq);

	deq.preferred_side = LEFT;
	for (int i = 0; i < 6; i++) {
		dequeue(&deq);
	}
	display(&deq);

	deq.adjusted_side = RIGHT; // just add right side
	for (int i = 0; i < 5; i++) {
		enqueue(&deq, i);
	}
	display(&deq);

	deq.io_restriction = OUTPUT; //output restricted deque
	deq.preferred_side = LEFT; //will add LEFT side
	for (int i = 0; i < 5; i++) {
		enqueue(&deq, i);
	}
	display(&deq);

	//will delete adjusted side which is RIGHT
	for (int i = 0; i < 5; i++) {
		dequeue(&deq);
	}
	display(&deq);


	return 0;
}
