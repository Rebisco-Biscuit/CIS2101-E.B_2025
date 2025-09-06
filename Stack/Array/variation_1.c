#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

Stack* initialize();
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);


int main() {

    Stack *s = initialize();
    push(s, 5);
    push(s, 10);
    push(s, 15);
    pop(s);
    push(s, 15);
    
    printf("%d", peek(s));
    //display(s);

    return 0;
}
int peek(Stack* s) {
    return s->items[s->top];
}

void display(Stack* s) {
    for(int i=s->top; i>-1; i--) {
        printf("%d\n", s->items[i]);
    }
}

void push(Stack* s, int value) {
    if(s->top == MAX-1) { 
        printf("Stack is full, cannot push.");
        return; 
    } else {
        s->items[++s->top] = value;
    }
}

int pop(Stack* s) {
    if(s->top == -1) {
        printf("Stack is empty, nothing to pop.");
        return -1;
    } else {
        s->top--;
    }
}

Stack *initialize() {
    Stack *s = malloc(sizeof(Stack));
    s->top = -1;
    return s;
}