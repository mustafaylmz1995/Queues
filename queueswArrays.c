#include <stdio.h>
#include <stdlib.h>

#define QUEUESIZE 50

int queue[QUEUESIZE];
int rear = -1;
int front = -1;
const int max = QUEUESIZE;

void enqueue(int num) {
	if (rear == (max - 1)) {
		printf("Overflow!\n");
		return;
	}
	if ((front == -1) && (rear == -1)) {
		front = 0;
		rear = 0;
	}
	else {
		rear = rear + 1;
	}
	queue[rear] = num;
}

int dequeue(void) {
	int num;
	if ((front == -1) || (front > rear)) {
		printf("Underflow!\n");
	}
	else {
		num = queue[front];
		front = front + 1;
	}
	return num;
}


void peek(void) {
	if ((front == -1) || (front > rear)) {
		printf("Queue is Empty!\n");
	}
	else {
		printf("Peek value: %d\n", queue[front]);
	}
}


void display() {

	int cnt = rear - front + 1;

	for (int i = 0; i < cnt; i++) {
		printf("[front=%d] [rear=%d] queue[%d] : %d\n", front, rear, i, queue[front + i]);
	}

}



int main(void) {

	enqueue(-15);
	display();
	printf("Clear\n");

	dequeue();
	enqueue(555);
	display();


	//Enqueue
	printf("Enqueue\n");
	for (int a = 1; a < 5; a++) {
		enqueue(a);
	}

	for (int a = -1; a > -5; a--) {
		enqueue(a);
	}
	display();


	//Dequeue
	printf("Dequeue\n");

	for (int a = 0; a < 8; a++) {
		dequeue();
	}
	display();

	
	//peek
	printf("Peek\n");
	peek();
	dequeue();
	peek();

	//Overflow
	for (int a = 0; a < 50; a++) {
		enqueue(a);
	}
	display();


	return 0;
}
