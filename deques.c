#include <stdio.h>

#define QUEUE_SIZE 10
int left  = -1;
int right = -1;

int deq[QUEUE_SIZE];

typedef enum TURN{
  LEFT = 0,
  RIGHT = 1
}turn;

void insert(turn t, int val);
void dequeue(turn t);
void display(void);

int main(){

  //input restricted deque
  turn t=LEFT;
  for(int i = 0; i<11; i++){
    insert(t, i);
  }
  t=RIGHT;
  for(int i = 0; i<11; i++){
    dequeue(t);
  }

  t=LEFT;
  for(int i = 0; i<11; i++){
    insert(t, i);
  }
  t=LEFT;
  for(int i = 0; i<11; i++){
    dequeue(t);
  }


  t=RIGHT;
  for(int i = 0; i<11; i++){
    insert(t, i);
  }
  t=RIGHT;
  for(int i = 0; i<11; i++){
    dequeue(t);
  }

  t=RIGHT;
  for(int i = 0; i<11; i++){
    insert(t, i);
  }
  t=LEFT;
  for(int i = 0; i<11; i++){
    dequeue(t);
  }

/*
  insert(LEFT, 99);
  insert(t, 55);
  insert(0, 21);
*/
  display();

  return 0;
}

void insert(turn t, int val){
	//queue sıralı sekilde dolu veya sol pointer sag pointer'in sagına kadar geldi
	if (  ( (left == 0) && (right == QUEUE_SIZE - 1) ) || (left == right +1) ) {
		printf("OVERFLOW\n");
		return;
	}

  // t = 0 left
  // t = 1 right 

  if(t == LEFT){
    if(left == -1){
      left = QUEUE_SIZE - 1;
      right = 0;
    }
    else if(left == 0){
      left = QUEUE_SIZE - 1;
    }else{
      left = left - 1;
    }
  }else{
    if(right == -1){
      left = QUEUE_SIZE - 1;
      right = 0;
    }
    else if(right == QUEUE_SIZE - 1){
      right = 0;
    }else{
      right = right + 1;
    }
  }

  if(t)
    deq[right] = val;
  else
    deq[left] = val;

}

void dequeue(turn t){
  if(left == -1){ //eleman bittiğinde -1 olarak ayarlanıyorlar right=left=-1
    printf("UNDERFLOW\n");
    return;
  }

  if(t == LEFT)
    printf("The deleted element is %d\n", deq[left]);
  else
    printf("The deleted element is %d\n", deq[right]);

  if( left == right ){  //queue sadece bir elemana sahiptir.
    left = -1;
    right = -1;
  }else{
    if(t==LEFT)
      if(left == QUEUE_SIZE-1)
        left = 0;
      else
        left = left + 1;
    else
      if(right == 0)
        right = QUEUE_SIZE -1;
      else  
        right = right - 1;
  }

}

void display(void){
  int front = left;
  int rear = right;

  if(front == -1){
    printf("Queue is empty\n");
    return;
  }

  printf("The elements of the queue are : \n");

  if(front <= rear){
    while(front <= rear){
      printf("%d\n", deq[front]);
      front++;
    }
  }else{
    while(front <= QUEUE_SIZE - 1){
      printf("%d\n", deq[front]);
      front++;
    }

    front = 0;

    while(front <= rear){
      printf("%d\n", deq[front]);
      front++;
    }
  }
}
