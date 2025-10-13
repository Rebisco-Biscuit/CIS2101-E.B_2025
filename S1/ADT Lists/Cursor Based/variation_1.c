#include <stdio.h>
#define MAX 4

// im not even sure if insertPos, insertSorted, deleteAllOccurrence works...

/*

AVAIL STARTS AT 0
AVAIL STARTS AT 0
AVAIL STARTS AT 0

*/

typedef struct {
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
} Vheap;

typedef int List;

//create
void initialize(Vheap*);
int allocSpace(Vheap*);
void insertFirst(int*, Vheap*, int);
void insertLast(int*, Vheap*, int);
void insertPos(int*, Vheap*, int);
void insertSorted(int*, Vheap*, int);

//display
void display(int, Vheap);

//deletion
void delete(int*, Vheap*, int);
void deallocSpace(Vheap*, int);
void deleteAllOccurrence(int*, Vheap*, int);

int main() {
    List L = -1;
    Vheap vspace;
    initialize(&vspace);
    
    insertFirst(&L, &vspace, 10);
    insertFirst(&L, &vspace, 20);
    insertFirst(&L, &vspace, 30);
    delete(&vspace, 20);
    insertFirst(&L, &vspace, 40);


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

void insertPos(int* L, Vheap* V, int elem) {
    int newCell = allocSpace(V);
    if(newCell != -1) {
        V->H[newCell].elem = elem;
        int *trav = L;
        while(*trav != -1) {
            trav = &V->H[*trav].next;
        }
        V->H[newCell].next = *trav;
        *trav = newCell
    }
}

void insertSorted(int* L, Vheap* V, int elem) {
    int newCell - allocSpace(V);
    if(newCell != -1) {
        V->H[newCell].elem = elem;
        int *trav = L;
        while(*trav != -1 && elem > V->H[*trav].elem) {
            trav = &V->H[*trav].next;
        }
        V->H[newCell].next = *trav;
        *trav = newCell;
    }
}

void insertLast(int* L, Vheap* V, int elem) {
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

void deallocSpace(Vheap* V, int index) {
    V->H[index].next = V->avail;
    V->avail = index;
}

void delete(int* L, Vheap* V, int elem) {
    int *trav = *L;
    while(*trav != -1 && V->H[*trav].elem != elem) {
        trav = &V->H[trav].next;
    }

    if(*trav != -1) {
        int temp = *trav;
        *trav = V->H[temp].next;
        deallocSpace(V, temp);
    }
}

void deleteAllOccurrence(int* L, Vheap* V, int elem) {
    int *trav = L;
    while (*trav != -1) {
        if (V->H[*trav].elem == elem) {
            int temp = *trav;
            *trav = V->H[temp].next;
            freeSpace(V, temp);
        } else {
            trav = &V->H[*trav].next;
        }
    }
}