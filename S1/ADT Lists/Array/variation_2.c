#include <stdio.h>
#define MAX 10

/*

STATIC ARRAY ACCESSED BY POINTER
STATIC ARRAY ACCESSED BY POINTER
STATIC ARRAY ACCESSED BY POINTER

*/

typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);


int main() {
    EPtr L = malloc(sizeof(Etype));
    //EPtr L;
    
    //L = &K;
    
    initialize(L);
    insertPos(L, 1, 0);
    insertPos(L, 2, 1);
    insertPos(L, 3, 2);
    insertPos(L, 5, 3);
    //deletePos(L, 2);
    insertSorted(L, 4);
    
    printf("%d", locate(L, 3));
    printf("%d\n", retrieve(L, 1));
    //display(L);
    
    makeNULL(L);
  
    return 0;
}

void initialize(EPtr L) {
    L->count = 0;
    for(int i=0; i<MAX; i++) {
        L->elem[i] = -1;
    }
}

void insertPos(EPtr L, int data, int position) {
    if(position < MAX && L->count != MAX) {
        if(L->elem[position] == -1) {
            L->elem[position] = data;
        } else if (L->elem[position] != -1) {
            for(int i=L->count; i>position; i--) {
                L->elem[i] = L->elem[i-1];
            }
            L->elem[position] = data;
        }
        L->count++;
    }
}

void deletePos(EPtr L, int position) {
    if(position < MAX) {
        for(int i=position; i<L->count; i++) {
            L->elem[i] = L->elem[i+1];
        }
        L->count--;
    }
}

int locate(EPtr L, int data) {
  for(int i=0; i<L->count; i++) {
    if(L->elem[i] == data) { return i; }
  }
  return -1;
}

int retrieve(EPtr L, int position) {
    for(int i=0; i<MAX && position <=L->count; i++) {
        if(position == i) {
            return L->elem[i];
        }
    }
}

void insertSorted(EPtr L, int data) {
    if(L->count != MAX) {
        int pos = 0;
        
        while(pos < L->count && L->elem[pos] < data) {
            pos++;
        }
        
        for(int i=L->count-1; i>=pos; i--) {
            L->elem[i+1] = L->elem[i];
        }
        
        L->elem[pos] = data;
        L->count++;
    }
}

void display(EPtr L) {
    for(int i=0; i<L->count; i++) {
        printf("\n%d", L->elem[i]);
    }
}

void makeNULL(EPtr L) {
    free(L);
}