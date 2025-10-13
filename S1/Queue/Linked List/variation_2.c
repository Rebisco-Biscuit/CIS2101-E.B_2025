#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* kwewe LL v2 front->last rear->first */

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

int main() {
    Queue* q = initialize();

    enqueue(q, 2);
    enqueue(q, 1);
    enqueue(q, 3);    
    dequeue(q);    
    enqueue(q, 4);

    //printf("%d", front(q));
    display(q);
    
    return 0;
}

Queue* initialize() {
    Queue* q = malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

bool isFull(Queue* q) {
    return 0;
}

bool isEmpty(Queue* q) {
    return (q->front == NULL && q->rear == NULL);
}

void enqueue(Queue* q, int value) {
    if(isFull(q)) { return; }

    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if(isEmpty(q)) {
        q->rear = q->front = newNode;
    } else {
        newNode->next = q->rear;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    int dqVal = -1;
    if(isEmpty(q)) { return dqVal; }
    
    // reset queue
    if(q->front == q->rear) { 
      dqVal = q->front->data;
      free(q->front); 
      q->front = q->rear = NULL; 
    }

    else {
        Node* temp = q->rear;        
        while(temp->next != q->front) {
          temp = temp->next; 
        }

        dqVal = q->front->data;
        free(q->front);
        q->front = temp;
        temp->next = NULL;
    }
  return dqVal;    
}

int front(Queue* q) {
    return (isEmpty(q))? -1:q->front->data;
}

void display(Queue* q) {
    if(isEmpty(q)) { printf("Queue is empty.\n"); }

    else {
        // lazy implementation
    /*
        Node *temp = q->rear;
        for(; temp != NULL; printf("%d -> ", temp->data), temp = temp->next) {}
        printf("NULL\n");
    */

        // flat 3 pls? :DDDDDDDD
        Queue* tempQ = initialize();
        while(!isEmpty(q)) {
            int dqVal = dequeue(q);
            printf("%d -> ", dqVal);
            enqueue(tempQ, dqVal);
        }
        printf("NULL\n");

        while(!isEmpty(tempQ)) {
            enqueue(q, dequeue(tempQ));
        }
        
    free(tempQ);
    }
}