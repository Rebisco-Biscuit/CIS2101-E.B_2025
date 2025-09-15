#include <stdio.h>
#define MAX 4

typedef struct {
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
} Vheap;

typedef int List;

void initialize(Vheap *V);
int allocSpace(Vheap* V);
void insertFirst(int* L, Vheap* V, int elem);
void insertLast(int* L, VHeap* V, int elem);
void deallocSpace(VHeap* V, int index);

int main() {
    List L = -1;
    Vheap vspace;
    initialize(&vspace);
    
    insertFirst(&L, &vspace, 10);
    insertFirst(&L, &vspace, 20);    

    return 0;
}

void initialize(Vheap *V) {
    V->avail = 0;
    List i;
    for(i=0; i<MAX-1; i++) {
        V->H[i].next = i+1;
    }
    V->H[i].next = -1;
}

int allocSpace(Vheap* V) {
    List r = V->avail;
    if(r != -1) {
        V->avail = V->H[r].next;
    }
    return r;
}

void insertFirst(int* L, Vheap* V, int elem) {
    int newCell = allocSpace(V);
    if(newCell != -1) {
        V->H[newCell].elem = elem;
        V->H[newCell].next = *L;
    }
    *L = newCell;
}

void insertLast(int* L, VHeap* V, int elem) {
    int newCell = allocSpace(V);
    if(newCell != -1) {
        V->H[newCell].elem = elem;
        V->H[newCell].next = -1;
    
        int *trav = L;
        while(*trav != -1) {
            trav = &V->H[*trav].next;
        }
        *trav = newCell;
    }
}

void deallocSpace(VHeap* V, int index) {
    
}
