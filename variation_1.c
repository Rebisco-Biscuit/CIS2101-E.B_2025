#include <stdio.h>
#define size 10

typedef struct{
    int elem[size];
    int count;
} List;

List L;

List initialize (List L);
List insertPos(List, int, int);
List deletePos(List, int);
int locate(List, int);
List insertSorted(List, int);
void display(List);

int main () {
    L = initialize(L);
    L.elem[0] = 5;
    L.elem[1] = 2;
    L.elem[2] = 3;
    L.count = 3;
    
    L = insertPos(L, 4, 6);
    L = deletePos(L, 2);
    // printf("%d", locate(L, 5));
    L = insertSorted(L, 1);
    
    display(L);
    

   return 0; 
}

List initialize (List L) {
    L.count = 0;
    for(int i=0; i<size; i++) {
        L.elem[i] = -1;
    }
    return L;
}

void display(List L) {
    for(int i=0; i<size; i++) {
        printf("%d\n", L.elem[i]);
    }
}

List insertPos(List L, int data, int position) {
    if(L.elem[position] == -1){
        L.count++;
    }
    
    L.elem[position] = data;

    
    return L;
}

int locate(List L, int data) {
    for(int i=0; i<size; i++) {
        if(L.elem[i] == data) {
            return i;
        }
    }
}

// NEEDS FIXING :(
List insertSorted(List L, int data) {
    for(int i=0; i<size-1; i++) {
        for(int j=1; j<size; j++) {
            if(data < L.elem[j]) {
              int temp = L.elem[j];
                L.elem[j] = data;
                L.elem[j+1] = temp;
            }
        }
    }
}

List deletePos(List L, int position) {
    for(int i=0; i<size; i++){
        if(i == position && L.elem[i] != -1) {
            L.elem[i] = -1;
            L.count--;
        }
    }
    return L;
}