#include <stdlib.h>
#include <stdio.h>
#define LENGTH 10

/*

DYNAMIC ARRAY ACCESSED BY VALUE
DYNAMIC ARRAY ACCESSED BY VALUE
DYNAMIC ARRAY ACCESSED BY VALUE

*/

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List  insertSorted(List L, int data);
void display(List L);
List resize(List L);

int main() {
    List L;
    L = initialize(L);
    
    L = insertPos(L, 1, 0);
    L = insertPos(L, 2, 1);
    L = insertPos(L, 3, 2);
    L = insertPos(L, 5, 3);
    //L = insertPos(L, 10, 1);
    L = deletePos(L, 0);
    
    insertSorted(L, 4);
    
    L = resize(L);
    
    locate(L, 5);

    return 0;
}

void display(List L) {
  for(int i=0; i<L.max; i++) {
    printf("%d\n", L.elemPtr[i]);
  }
}

List initialize(List L) {
    L.elemPtr = malloc(sizeof(int)*(LENGTH));
    
    for(int i=0; i<LENGTH; i++) { L.elemPtr[i] = -1; }
    
    L.max = LENGTH;
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position) {
    if(position <= L.max && L.count != L.max) {
        if(L.elemPtr[position] == -1) {
            L.elemPtr[position] = data;
        } else if (L.elemPtr[position] != -1) {
            for(int i=L.count; i>=position; i--) {
                L.elemPtr[i] = L.elemPtr[i-1]; 
            }
        }
        L.elemPtr[position] = data;
        L.count++;
    }
    return L;
}

List resize(List L) {
  int pmax = L.max;
  L.elemPtr = realloc(L.elemPtr, (L.max*2)*sizeof(L.elemPtr[0]));
  L.max *= 2;
  
  for(int i=pmax; i<L.max; i++) { L.elemPtr[i] = -1; }
  
  return L;
}

List deletePos(List L, int position) {
    if(position <= L.max) {
        for(int i=position; i<L.count; i++) {
            L.elemPtr[i] = L.elemPtr[i+1];
        }
      L.count--;
    }
    return L;
}

int locate(List L, int data) {
    for(int i=0; i<L.count; i++) {
      if(L.elemPtr[i] == data) { return i; }
    }
    return -1;
}

List  insertSorted(List L, int data) {
    if(L.count <= L.max) {
        int pos = 0;
        
        for(int i=0; i<L.count && L.elemPtr[i] < data; i++) {
            pos++;
        }
        
        L = insertPos(L, data, pos);
    }
    return L;
}