#include <stdio.h>
#include <stdbool.h>

/*

BIT FIELDS
BIT FIELDS
BIT FIELDS

*/

typedef struct {
    unsigned int field : 8;
} Set;

void initialize(Set *set);
void insert(Set *set, int element);
void delete(Set *set, int element);
bool find(Set set, int element);
Set unionSet(Set A, Set B);
Set intersection(Set A, Set B);
Set difference(Set A, Set B);
void display(unsigned char set);

int main () {
    Set A;
    Set B;
    
    initialize(&A);
    initialize(&B);
    
    insert(&B, 1);
    insert(&B, 5);
    insert(&B, 2);
    
    printf("== insertion ==");
    printf("\ninserting 0 to set A"); insert(&A, 0);
    printf("\ninserting 1 to set A"); insert(&A, 1);
    printf("\ninserting 7 to set A"); insert(&A, 7);
    printf("\nset A: "); display(A.field);
    
    printf("\n\n== deletion ==");
    printf("\ndeleting 0 from set A"); delete(&A, 0);    
    printf("\nset A: "); display(A.field);
    
    printf("\n\n== find ==");
    printf("\nfinding 5 from set A");
    printf(": %s", find(A, 5)? "found":"not found");
    printf("\nfinding 1 from set A");
    printf(": %s", find(A, 1)? "found":"not found");
    
    printf("\n\n== union ==");
    printf("\nSet A: "); display(A.field);
    printf("\nSet B: "); display(B.field); 
    printf("\nA | B: "); display(unionSet(A,B).field);
    
    printf("\n\n== intersection ==");
    printf("\nSet A: "); display(A.field);
    printf("\nSet B: "); display(B.field); 
    printf("\nA & B: "); display(intersection(A,B).field);
    
    printf("\n\n== difference ==");
    printf("\nSet A: "); display(A.field);
    printf("\nSet B: "); display(B.field); 
    printf("\nA - B: "); display(difference(A,B).field); 
    printf("\nB - A: "); display(difference(B,A).field);     
}

Set unionSet(Set A, Set B) {
    Set onion;
    initialize(&onion);
    
    onion.field |= (A.field | B.field);
    return onion;
}

Set intersection(Set A, Set B) {
    Set intersect;
    initialize(&intersect);
    
    intersect.field |= (A.field & B.field);
    return intersect;
}

Set difference(Set A, Set B) {
    Set diff;
    initialize(&diff);
    
    diff.field |= (A.field & (~B.field));
    return diff;
}

void display(unsigned char set) {
    bool first = true;
    printf("{");
    for(int i=0; i<8; i++) {
        if(set & (1<<i)) {
            if(!first) printf(", ");
            printf("%d", i);
            first = false;
        }
    }
    printf("}");    
}

bool find(Set set, int element) {
    unsigned char mask = 1 << element;
    return (set.field & mask);
}

void initialize(Set *set) {
    set->field = 0;
}

void insert(Set *set, int element) {
    if(element < 0 || element > 7) return;
    set->field |= (1 << element);
}

void delete(Set *set, int element) {
    if(element < 0 || element > 7) return;
    unsigned char mask = 1 << element;
    set->field &= ~(mask);
}