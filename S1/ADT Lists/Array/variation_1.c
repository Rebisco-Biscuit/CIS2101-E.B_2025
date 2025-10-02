#include <stdio.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

int main() {
    List L;
    
    L = initialize(L);
    L.elem[0] = 1;
    L.elem[1] = 2;
    L.elem[2] = 4;
    L.elem[3] = 5;
    L.count = 4;
    
    //L = insertPos(L, 5, 2);
    //L = deletePos(L, 2);
    
    printf("%d\n", locate(L, 5));
    printf("%d", locate(L, 3));
    
   L = insertSorted(L, 3);

    return 0;
}
void display(List L) {
    for(int i=0; i<MAX; i++) {
        printf("%d\n", L.elem[i]);
    }
}

List initialize(List L) {
    for(int i=0; i<MAX; i++) {
        L.elem[i] = -1;
    }
    L.count = 0;
    
    return L;
}

List insertPos(List L, int data, int position) {
    if(position <= L.count && L.count != MAX) {
        if(L.elem[position] == -1) {
            L.elem[position] = data;
        } else if (L.elem[position] != -1) {
            for (int i=L.count; i>position; i--) {
                L.elem[i] = L.elem[i-1];
            }
            L.elem[position] = data;
        }
        L.count++;
    }
    return L;
}

List deletePos(List L, int position) {
    if(position <= L.count) {
        for(int i=position; i<L.count; i++) {
            L.elem[i] = L.elem[i+1];
        }
        L.count--;
    }
    return L;
}

int locate(List L, int data) {
    for(int i=0; i<L.count; i++) {
        if(L.elem[i] == data) {
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, int data) {
    if (L.count != MAX) {
        int pos = 0;

        while (pos < L.count && L.elem[pos] < data) {
            pos++;
        }

        for (int i=L.count-1; i>=pos; i--) {
            L.elem[i+1] = L.elem[i];
        }

        L.elem[pos] = data;
        L.count++;
    }
    return L;
}
