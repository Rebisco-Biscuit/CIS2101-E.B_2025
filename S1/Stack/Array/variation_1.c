#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

/* stak var 1 0->n-1 */

typedef struct {
    int items[MAX];
    int top;
} Stack;

Stack* initialize();
void push(Stack*, int);
int pop(Stack*);
int peek(Stack*);
int top(Stack*);
void display(Stack*);
bool isEmpty(Stack*);

int main() {

    Stack *s = initialize();
    push(s, 5);
    push(s, 10);
    push(s, 15);
    pop(s);
    push(s, 15);
    
    //printf("%d", peek(s));
    display(s);

    return 0;
}

int peek(Stack* s) {
    if(isEmpty(s)) { return -1; }
    return s->items[s->top];
}

int top(Stack *s) {
    return s->items[s->top];
}

Stack *initialize() {
    Stack *s = malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

void display(Stack* s) {
    if(isEmpty(s)) { printf ("Stack is empty.\n"); }
    
/* lazy implementation
    Stack tempStack = *s;
    while(!isEmpty(&tempStack)) {
        printf("%d -> ", pop(&tempStack));
    }
*/

    Stack tempStack;
    tempStack.top = -1;
    while(!isEmpty(s)) {
        int top = pop(s);
        printf("%d -> ", top);
        push(&tempStack, top);
    }

    while(!isEmpty(&tempStack)) {
        push(s, pop(&tempStack));
    }

    printf("NULL\n");
}

void push(Stack* s, int value) {
    if(isFull(s)) { 
        printf("Stack is full, cannot push.");
        return; 
    } else {
        s->items[++s->top] = value;
    }
}

int pop(Stack* s) {
    if(isEmpty(s)) {
        printf("Stack is empty, nothing to pop.");
        return -1;
    } else {
        int val = s->items[s->top--];
        return val;
    }
}

bool isFull(Stack *s) {
    return (s->top == MAX-1)? 1:0;
}

bool isEmpty(Stack *s) {
    return (s->top == 0)? 1:0;    
}