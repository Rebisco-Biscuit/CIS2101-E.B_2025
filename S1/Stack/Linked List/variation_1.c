#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* stak ll */

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

Stack* initialize();
bool isFull(Stack*); //arbitrary, as linked list stack is never full unless memory is exhausted -- return false
bool isEmpty(Stack*);
void push(Stack*, int);
int pop(Stack*);
int peek(Stack*);
void display(Stack*);

int main () {
    Stack *s = initialize();
    push(s, 2);
    push(s, 1);
    push(s, 3);
    peek(s);
    pop(s);
    push(s, 10);
    peek(s);

    display(s);
}

Stack* initialize() {
    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack *s , int value) {
    if(!isFull(s)) { 
        Node *newNode = malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;

        if(s->top == NULL) { s->top = newNode; }

        else {
            newNode->next = s->top;
            s->top = newNode;
        }
    }
}

int pop(Stack* s) {
    if(isEmpty(s)) { return -1; }

    Node *temp = s->top;
    int popped = temp->data;
    s->top = temp->next;

    free(temp);
    return popped;
}

int peek(Stack* s) {
    if(isEmpty(s)) { return -1; }

    return s->top->data;
}

bool isFull(Stack* s) {
    return 0; //return false
}

bool isEmpty(Stack* s) {
    return (s->top == NULL)? 1:0;
}

void display(Stack* s) {
    if(isEmpty(s)) { printf("Stack is empty.\n"); }

    //lazy method
    else {
        printf("top -> ");
        Node *temp = s->top;
        for(; temp != NULL; printf("%d -> ", temp->data), temp = temp->next) {}
        printf("NULL\n");
    }

/* proper implementation... i think

    else {
        Stack *tempStack = initialize();
        while(!isEmpty(s)) {
            int top = pop(s);
            printf("%d -> ", top);
            push(tempStack, top);
        }

        while(!isEmpty(tempStack)) {
            push(s, pop(tempStack));
        }
        
        free(tempStack);
    }

*/
}