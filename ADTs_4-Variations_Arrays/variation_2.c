#include <stdio.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);

int main() {
    Etype K;
    EPtr L;
    
    L = &K;
    
    initialize(L);
    insertPos(L, 1, 0);
    insertPos(L, 2, 1);
    insertPos(L, 3, 2);
    insertPos(L, 5, 1);

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