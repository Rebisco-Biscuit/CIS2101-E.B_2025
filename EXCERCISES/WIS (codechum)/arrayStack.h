#include <stdio.h>
#include <stdbool.h>
#include "types.h"

void displayStack(Stack *s) {
    if(isEmpty(s) == 1) {
        printf("\nStack is empty.");
    } else {
        for(int i=s->top; i>=0; i--) {
            printf("\n%d", s->items[i]);
        }
    }
}

int peek(Stack *s) {
    return s->items[s->top];
}

bool findContainer(Stack *s, int num) {
    bool isFound = false;
    int tempStack[MAX];
    int tempTop = -1;

    while(!isEmpty(s)) {
        int value = pop(s);
        if(value == num) {
            isFound = true;
        }
        tempStack[++tempTop] = value;
    }
    
    while(tempTop >= 0) {
        push(s, tempStack[--tempTop]);
    }
    
    return isFound;

}

int pop(Stack *s) {
    if(isEmpty(s) == 1) {
        return -1;
    } else {
        return s->items[s->top--];
    }
}

void push(Stack *s, int value) {
    if(isFull(s) == 1) {
        return;
    } else {
        s->items[++s->top] = value;
    }
    
}

bool isFull(Stack *s) {
    return (s->top == MAX-1)? 1 : 0;
}
bool isEmpty(Stack *s) {
    return (s->top == -1)? 1 : 0;
}

void initializeStack(Stack *s) {
    s->top = -1;
}