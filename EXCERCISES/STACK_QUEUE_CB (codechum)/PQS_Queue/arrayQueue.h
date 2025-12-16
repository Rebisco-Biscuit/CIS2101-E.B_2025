#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"

Queue* initialize() {
    Queue *queue = malloc(sizeof(Queue));
    queue->list.count = 0;
    queue->rear = queue->front = -1;
    return queue;
}
void enqueue(Queue* q, int value) {
    if(isFull(q)) { return; }

    q->rear = (q->rear+1) % MAX;
    q->list.items[q->rear] = value;
    ++q->list.count;
    
    if(q->front == -1) {
        q->front = (q->front+1) % MAX;
    }
}

int dequeue(Queue* q) {
    if(isEmpty(q)) { return -1; }
    
    --q->list.count;
    int val = q->front;
    q->front = (q->front+1) % MAX;
    return q->list.items[val];

}

bool isFull(Queue* q) {
    return (q->list.count == MAX)? 1 : 0;
}

bool isEmpty(Queue* q) {
    return (q->list.count == 0)? 1 : 0;
}
void display(Queue* q) {
    if(isEmpty(q)) {
        printf(" Queue is empty.");
        return;
    }
    
    int i = q->front;
    while(1) {
        printf(" %d", q->list.items[i]);
        if(i == q->rear) {
            break;
        }
        i = (i+1) % MAX;
    }
}