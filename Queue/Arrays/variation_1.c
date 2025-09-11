#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX 3

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
    
    int i = q->front;
    while(1) {
        printf("%d ", q->list.items[i]);
        if(i == q->rear) {
            break;
        }
        i=(i+1)%MAX;
    }
    
    dequeue(q); 
    enqueue(q, 2);
    enqueue(q, 3);    
    return 0;
}

Queue* initialize() {
    Queue *queue = malloc(sizeof(Queue));
    queue->list.count = 0;
    queue->front = queue->rear = -1;   
    return queue;
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
    int prev;
    if(isEmpty(q)) { 
        return -1; 
    } else if (q->front == MAX-1 && q->list.count == 0) {
        q->rear = q->front = -1;
    } else {
        prev = q->list.items[q->front];
        q->front = (q->front+1) % MAX;
        --q->list.count;
        return prev;
    }
}
