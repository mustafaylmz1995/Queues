#include <stdio.h>
#include <stdlib.h>

#define QUEUESIZE 5

int queue[QUEUESIZE];
int rear = -1;
int front = -1;
const int max = QUEUESIZE;

//enqueue_circular

//Enqueue
void enqueue(int num) {

	if (rear == (max - 1)) {
		if (front == 0) {
			printf("Overflow!\n");
			return;
		}
		else {
			rear = 0;
		}
	}
	else if ((front == -1) || (rear == -1)) {
		front = 0;
		rear = 0;
	}
	else {
		rear = rear + 1;
	}

	queue[rear] = num;
	
}


//dequeue_circular

//Dequeue
void dequeue() {

	if ((front == -1) || (rear == -1)) {
		printf("Underflow!\n");
		return;
	}
	else {
		if (front == rear) {
			queue[front] = 0;
			front = -1;
			rear = -1;
		}
		else if (front == (max - 1)) {
			queue[front] = 0;
			front = 0;
		}
		else {
			queue[front] = 0;
			front++;
		}

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
	int front_temp = front;
	int rear_temp = rear;
	int i = 0;
	for (; front_temp != rear_temp; front_temp++) {
		if (front_temp == max) {
			front_temp = 0;
		}

		printf("[front=%d] [rear=%d] queue[%d] : %d\n", front_temp, rear_temp, i, queue[front_temp]);
		i++;

	}
	printf("[front=%d] [rear=%d] queue[%d] : %d\n", front_temp, rear_temp, i, queue[front_temp]);

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
	for (int a = 1; a < 6; a++) {
		enqueue(a);
	}
	display();
	for (int a = 0; a < 4; a++) {
		dequeue();
	}
	display();
	for (int a = -1; a > -5; a--) {
		enqueue(a);
	}
	display();


	//Dequeue
	printf("Dequeue\n");

	for (int a = 0; a < 6; a++) {
		dequeue();
	}
	display();


	//peek
	printf("Peek\n");
	peek();
	dequeue();

	//Overflow
	for (int a = 0; a < 7; a++) {
		enqueue(a);
	}
	display();

	return 0;
}
