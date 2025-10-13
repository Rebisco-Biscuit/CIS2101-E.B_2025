#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX 10

/* circular array - kwewe v1 */

/*

CIRCULAR ARRAY W/ COUNT
CIRCULAR ARRAY W/ COUNT
CIRCULAR ARRAY W/ COUNT

*/

typedef struct {
    int items[MAX];
    int count;
} List;

typedef struct {
    List list;
    int front;
    int rear;
} Queue;

Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);

int main() {
    Queue *q = initialize();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    dequeue(q);    
    
    dequeue(q); 
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 3123);        

    display(q);
    return 0;
}

Queue* initialize() {
    Queue *queue = malloc(sizeof(Queue));
    queue->list.count = 0;
    queue->front = queue->rear = -1;   
    return queue;
}

int front(Queue* q) {
    if(isEmpty(q)) { return -1; }
    return q->list.items[q->front];
}

bool isFull(Queue *q) {
    return (q->list.count == MAX)? 1:0;
}

bool isEmpty(Queue *q) {
    return (q->list.count == 0)? 1:0;
}

void enqueue(Queue* q, int value) {
   if(isFull(q)) { return; }
   
   if(isEmpty(q)) { 
       q->rear = ++q->front; 
   } else { 
       q->rear = (q->rear+1) % MAX;
   }

   q->list.count++;
   q->list.items[q->rear] = value;
}

int dequeue(Queue* q) {
    int dqVal;
    if(isEmpty(q)) { 
        return -1; 
    } else if (q->front == MAX-1 && q->list.count == 0) {
        q->rear = q->front = -1;
    } else {
        dqVal = q->list.items[q->front];
        q->front = (q->front+1) % MAX;
        --q->list.count;
        return dqVal;
    }
}

void display(Queue* q) {
    if(isEmpty(q)) { printf("Queue is empty."); }

    else {
        int i = q->front;
        while(i != q->rear) {
            printf("%d -> ", q->list.items[i]);
            i = (i+1)%MAX;
        }
        printf("%d -> NULL", q->list.items[q->rear]);
    }
}