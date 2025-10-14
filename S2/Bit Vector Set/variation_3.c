#include <stdio.h>
#include <stdbool.h>
#define ARRAY_SIZE 8

/*

BOOLEAN/ENUM ARRAY
BOOLEAN/ENUM ARRAY
BOOLEAN/ENUM ARRAY

*/

typedef bool Set[ARRAY_SIZE];

void initialize(Set set);
void insert(Set set, int element);
void delete(Set set, int element);
bool find(Set set, int element);
void unionSet(Set A, Set B, Set C);
void intersection(Set A, Set B, Set C);
void difference(Set A, Set B, Set C);
void display(Set set);

int main() {
    Set A;
    Set B;
    Set C;
    
    initialize(C);
    initialize(B);
    initialize(A);
    
    insert(B, 5);
    insert(B, 0);
    insert(B, 6);
    
    printf("== insertion ==");
    printf("\ninserting 1 to set A"); insert(A, 1);
    printf("\ninserting 5 to set A"); insert(A, 5);
    printf("\ninserting 0 to set A"); insert(A, 0);
    printf("\nset A: "); display(A);
    
    printf("\n\n== deletion ==");
    printf("\ndeleting 5 from set A"); delete(A, 5);
    printf("\nset A: "); display(A); 
    
    printf("\n\n== find ==");
    printf("\nfinding 5 from set A");
    printf(": %s", find(A, 5)? "found":"not found");
    printf("\nfinding 0 from set A");
    printf(": %s", find(A, 0)? "found":"not found");   
    
    printf("\n\n== union ==");
    printf("\nSet A: "); display(A);
    printf("\nset B: "); display(B); 
    unionSet(A,B,C);
    printf("\nA | B: "); display(C); 
    
    printf("\n\n== intersection ==");
    printf("\nSet A: "); display(A);
    printf("\nset B: "); display(B); 
    intersection(A,B,C);
    printf("\nA & B: "); display(C);
    
    printf("\n\n== difference ==");
    printf("\nSet A: "); display(A);
    printf("\nset B: "); display(B); 
    difference(A,B,C);
    printf("\nA - B: "); display(C);
    difference(B,A,C);    
    printf("\nB - A: "); display(C);
    
    return 0;
}

void unionSet(Set A, Set B, Set C) {
    for(int i=0; i<ARRAY_SIZE; i++) {
        C[i] = (A[i] | B[i])? 1:0;
    }
}

void intersection(Set A, Set B, Set C) {
    for(int i=0; i<ARRAY_SIZE; i++) {
        C[i] = (A[i] & B[i])? 1:0;
    }
}

void difference(Set A, Set B, Set C) {
    for(int i=0; i<ARRAY_SIZE; i++) {
        C[i] = (A[i] & (~B[i]))? 1:0;
    }
}

bool find(Set set, int element) {
    if(element < 0 || element > ARRAY_SIZE-1) return false;
    return set[element];
}

void delete(Set set, int element) {
    if(element < 0 || element > ARRAY_SIZE-1) return;
    set[element] = false;
}

void insert(Set set, int element) {
    if(element < 0 || element > ARRAY_SIZE-1) return;
    set[element] = true;
}

void display(Set set) {
    printf("{");
    bool first = true;
    for (int i=0; i<ARRAY_SIZE; i++) {
        if (set[i]) {
            if (!first) printf(", ");
            printf("%d", i);
            first = false;
        }
    }
    printf("}");
}

void initialize(Set set) {
    for(int i=0; i<ARRAY_SIZE-1; i++){
        set[i] = false;
    }
}