#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct  {
    int *elemPtr;
    int count;
    int max;
} List;

void initialize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
int retrieve(List *L, int position);
void display(List *L);
void insertSorted(List *L, int data);

int main() {

    List L;
    
    initialize(&L);
    insertPos(&L, 0, 0);
    insertPos(&L, 2, 1);
    insertPos(&L, 3, 2);
    insertPos(&L, 4, 3);
    insertPos(&L, 1, 1);
    deletePos(&L, 3);
    printf("%d\n", locate(&L, 2));
    printf("%d", retrieve(&L, 2));
    insertSorted(&L, 3);

    return 0;
}

void insertSorted(List *L, int data) {
  int pos=0;
  
  for(int i=0; i<L->count && L->elemPtr[i] < data; i++) {
    pos++;  
  }
  
  insertPos(L, data, pos);
}

void display(List *L) {
  for(int i=0; i<L->max; i++) {
    printf("%d\n", L->elemPtr[i]);
  }
}

int retrieve(List *L, int position) {
  return L->elemPtr[position];
}

int locate(List *L, int data) {
    for(int i=0; i<L->count; i++) {
      if(L->elemPtr[i] == data) { return i; }
    }
    return -1;
}

void initialize(List *L){
    L->elemPtr = malloc(sizeof(int)*(LENGTH));
    L->max = LENGTH;
    L->count = 0;
    
    for(int i=0; i<L->max; i++) { L->elemPtr[i] = -1;  }
}

void insertPos(List *L, int data, int position) {
    if(position <= L->count && L->count != L->max) {
        if(L->elemPtr[position] == -1) {
            //L.elemPtr[position] = data;
        } else if (L->elemPtr[position] != -1) {
            for(int i=L->count; i>=position; i--) {
                L->elemPtr[i] = L->elemPtr[i-1];
            }
        }
        L->elemPtr[position] = data;
        L->count++;
    }
}

void deletePos(List *L, int position) {
    if(position <=L->count) {
        for(int i=position; i<L->count; i++) {
            L->elemPtr[i] = L->elemPtr[i+1];
        }
    }
}

//needs MakeNull & Resize functions