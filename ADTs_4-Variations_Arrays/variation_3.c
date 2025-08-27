#include <stdlib.h>
#include <stdio.h>
#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

List initialize(List L);
List insertPos(List L, int data, int position);


int main() {
    List L;
    L = initialize(L);
    
    L = insertPos(L, 1, 0);
    L = insertPos(L, 2, 1);
    L = insertPos(L, 3, 2);
    L = insertPos(L, 5, 3);
    L = insertPos(L, 10, 1);

    return 0;
}

List initialize(List L) {
    L.elemPtr = malloc(sizeof(int)*(LENGTH));
    for(int i=0; i<LENGTH; i++) {
        L.elemPtr[i] = -1;
    }
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