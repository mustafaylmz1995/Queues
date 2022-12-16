#include <stdio.h>
#define QUEUESIZE 10
#define MAX QUEUESIZE

// choose deque type 
	// 0-> input restricted
		// choose joint(left or right) will be inserted
			//it will be constant
		// Delete any joints 
	// 1-> output restricted
		// choose joint(left or right) will be deleted 
			//it will be constant	
		//Insert any joint

int deque[QUEUESIZE];

int left_val	= -1;
int right_val	= -1;

typedef enum {
	INPUT	= 0,
	OUTPUT	= 1
}restriction;

restriction r = INPUT;

typedef enum {
	LEFT	= 0,
	RIGHT	= 1
}side;

side adjusted_side	= LEFT; //which side must be used
side preferred_side = LEFT; //which side is preferred


void enque(side s, int insert_this) {
	if (s == LEFT) {
		if (left_val == -1) {
			left_val = 0;
			right_val = 0;
		}
		else if (left_val == 0) {
			left_val = MAX - 1;
		}
		else {
			left_val = left_val - 1;
		}
		deque[left_val] = insert_this;
	}
	else {
		if (right_val == -1) {
			left_val = 0;
			right_val = 0;
		}
		else if (right_val == MAX - 1) {
			right_val = 0;
		}
		else {
			right_val = right_val + 1;
		}
		deque[right_val] = insert_this;
	}
}

void enqueue(int insert_this) {
	//queue sirali sekilde dolu veya sol pointer sag pointer'in sagina kadar geldi
	if (((left_val == 0) && (right_val == MAX - 1)) || (left_val == right_val + 1)) {
		printf("OVERFLOW\n");
		return;
	}
	if (r == INPUT) {
		//we can insert only adjusted side
		enque(adjusted_side, insert_this);
	}
	else {
		//we can insert any side
		enque(preferred_side, insert_this);
	}
}

void remove_deq(side s) {
	if (left_val == -1) { //eleman bittiginde -1 olarak ayarlaniyorlar right_val=left_val=-1
		printf("UNDERFLOW\n");
		return;
	}

	if (s == LEFT)
		printf("The deleted element is %d\n", deque[left_val]);
	else
		printf("The deleted element is %d\n", deque[right_val]);

	if (s == LEFT) {
		if (left_val == right_val) {  //queue sadece bir elemana sahiptir.
			left_val = -1;
			right_val = -1;
		}
		else {
			if (left_val == MAX - 1)
				left_val = 0;
			else
				left_val = left_val + 1;
		}
	}
	else {
		if (left_val == right_val) {	//queue sadece bir elemana sahiptir.
			left_val = -1;
			right_val = -1;
		}
		else {
			if (right_val == 0)
				right_val = MAX - 1;
			else
				right_val = right_val - 1;
		}

	}
}

void dequeue(void) {
	if (r == INPUT) {
		//we can delete any side
		remove_deq(preferred_side);
	}
	else {
		//we can delete just adjusted side
		remove_deq(adjusted_side);
	}
}

void display(void) {
	int front = left_val;
	int rear = right_val;

	if (front == -1) {
		printf("Queue is empty\n");
		return;
	}

	printf("The elements of the queue are : \n");

	if (front <= rear) {
		while (front <= rear) {
			printf("%d   ", deque[front]);
			front++;
		}
	}
	else {
		while (front <= MAX - 1) {
			printf("%d   ", deque[front]);
			front++;
		}

		front = 0;

		while (front <= rear) {
			printf("%d   ", deque[front]);
			front++;
		}
	}

	printf("\n");
}


int main(void) {

	r = INPUT; //input restricted deque
	adjusted_side = LEFT; // just add left side

	for (int i = 0; i < 11; i++) {
		enqueue(i);
	}
	display();

	preferred_side = RIGHT; //delete from RIGHT side
	for (int i = 0; i < 5; i++) {
		dequeue();
	}
	display();

	preferred_side = LEFT;
	for (int i = 0; i < 6; i++) {
		dequeue();
	}
	display();

	adjusted_side = RIGHT; // just add right side
	for (int i = 0; i < 5; i++) {
		enqueue(i);
	}
	display();

	r = OUTPUT; //output restricted deque
	preferred_side = LEFT; //will add LEFT side
	for (int i = 0; i < 5; i++) {
		enqueue(i);
	}
	display();

	//will delete adjusted side which is RIGHT
	for (int i = 0; i < 5; i++) {
		dequeue();
	}
	display();


	return 0;
}
