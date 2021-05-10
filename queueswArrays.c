#include <stdio.h>
#include <stdlib.h>

#define QUEUESIZE 50

int queue[QUEUESIZE];
int rear = -1;
int front = -1;
const int max = QUEUESIZE;

//Enqueue
void enqueue(int num) {
	if ((front == -1) || (rear == -1)) {
		front = 0;
		rear = 0;
	}
	else if (rear == (max - 1)) {
		printf("Overflow!\n");
		return;
	}
	else {
		rear = rear + 1;
		
	}
	queue[rear] = num;
}


//Dequeue
void dequeue() {

	if ((front == -1) || (rear == -1) ) {
		printf("Underflow!\n");
		return;
	}
	else {
		queue[front] = 0;
		front = front + 1;
	}


}


//Peek
void peek() {

	if ((front == -1) || (rear == -1)) {
		printf("Queue is empty!\n");
	}
	else {
		printf("Peek value : %d\n", queue[front]);
	}
	
	return;
	
}



//Display
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
