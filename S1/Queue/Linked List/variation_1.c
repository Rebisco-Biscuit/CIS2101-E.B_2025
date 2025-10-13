#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* kwewe LL v1 front->first rear->last*/

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* initialize();
bool isFull(Queue* q); // arbitrary unless memory is exhausted - return false
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);

int main () {
    Queue* q = initialize();

    enqueue(q, 1);
    enqueue(q, 2);
}

Queue* initialize() {
    Queue* q = malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

bool isFull(Queue* q) {
    return 0;
}

bool isEmpty(Queue *q) {
    return(q->front == NULL && q->rear == NULL);
}

void enqueue(Queue* q, int value) {
    if(isFull(q)) { return; }

    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if(isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    int dqVal = -1;
    if(isEmpty(q)) { return dqVal; }

    else {
        dqVal = q->front->data;
        Node *temp = q->front;    
        q->front = temp->next;
        free(temp);
        
        // reset queue if last item is dequeued        
        if(q->front == NULL) { q->rear = q->front; }

        return dqVal;
    }
}

int front(Queue* q) {
    return (isEmpty(q))? -1:q->front->data;
}

void display(Queue* q) {
    if(isEmpty(q)) { printf("Queue is empty.\n"); }

    else {
        Node* temp = q->front;
        for(; temp != NULL; printf("%d -> ", temp->data), temp = temp->next){}
        printf("NULL\n");
    }
}