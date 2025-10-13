#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX 10

/* circular array - kwewe v2 */

/*

CIRCULAR ARRAY W/O COUNT
CIRCULAR ARRAY W/O COUNT
CIRCULAR ARRAY W/O COUNT

*/

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue* initialize();
bool isEmpty(Queue*);
bool isFull(Queue*);
void enqueue(Queue*, int);
int dequeue(Queue*);
int front(Queue*);
void display(Queue*);

int main() {
    Queue* q = initialize();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    dequeue(q);
    enqueue(q, 341);
    
    display(q);
}

Queue* initialize() {
    Queue *q = malloc(sizeof(Queue));
    q->front = 1;
    q->rear = 0;
    return q;
}

bool isEmpty(Queue* q) {
    return (q->front == (q->rear+1)%MAX)? 1:0;
}

bool isFull(Queue* q) {
    return (q->front == (q->rear+2)%MAX)? 1:0;
}

void enqueue(Queue* q, int value) {
    if(isFull(q)) { return; }

    q->rear = (q->rear+1)%MAX;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    if(isEmpty(q)) { return -1; }

    else {
        int dqVal = q->items[q->front];
        q->front = (q->front+1)%MAX;
        return dqVal;
    }
}

int front(Queue *q) {
    if(isEmpty(q)) { return -1; }

    return q->items[q->front];
}

void display(Queue* q) {
    if(isEmpty(q)) { printf("Queue is empty.\n"); }
    int i = q->front;
    while(i != q->rear) {
        printf("%d -> ", q->items[i]);
        i = (i+1)%MAX;
    }
    printf("%d -> NULL", q->items[q->rear]);
}