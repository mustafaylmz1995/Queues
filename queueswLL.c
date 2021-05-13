#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node* next;
	int val;
}node;

node* rear = NULL;
node* front = NULL;

//enqueue
node* enqueue(node* rear, int num) {

	node* newNode;
	newNode = (node*)malloc(sizeof(node));

	newNode->next = NULL;
	newNode->val = num;

	if (front == NULL) {
		rear = newNode;
		front = newNode;

	}
	else {
		rear->next = newNode;
		rear = newNode;

	}

	return rear;
}


//dequeue
node* dequeue(node* front) {
	if (front == NULL) {
		printf("Underflow!\n");
		
	}
	else {
		node* newNode;
		newNode = (node*)malloc(sizeof(node));

		newNode = front;
		front = front->next;

		free(newNode);

	}
	return front;
}


//peek
node* peek(node* front) {
	if (front == NULL) {
		printf("Queue is Empty!\n");

	}
	else {
		printf("Peek value: %d\n", front->val);
	}

	return front;
}



//display
node* display(node* front) {
	node* ptr;
	int i = 0;

	ptr = front;
	while (ptr != NULL) {
		
		printf("%d\t-->\t%d\n", i, ptr->val);
		ptr = ptr->next;
		i++;
	}

	return front;
}




int main(void) {

	rear = enqueue(rear, 555);
	rear = enqueue(rear, -15);
	rear = enqueue(rear, 25);

	front = dequeue(front);
	front = dequeue(front);

	front = peek(front);
	front = dequeue(front);
	rear = enqueue(rear, 555);
	//display
	front = display(front);

	//enqueue
	printf("enqueue\n");
	for (int a = 1; a < 5; a++) {
		rear = enqueue(rear, a);

	}

	for (int a = -1; a > -5; a--) {
		rear = enqueue(rear, a);
	}

	//display
	front = display(front);

	//dequeue
	printf("dequeue\n");

	for (int a = 0; a < 8; a++) {
		front = dequeue(front);
	}

	//peek
	printf("Peek\n");
	front = peek(front);

	free(front);

	return 0;
}
