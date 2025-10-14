#include <stdio.h>
#include <stdbool.h>

/*

COMPUTER WORD/BITMASK
COMPUTER WORD/BITMASK
COMPUTER WORD/BITMASK

*/

void initialize(unsigned char *set);
void insert(unsigned char *set, int element);
void delete(unsigned char *set, int element);
void display(unsigned char set);
bool find(unsigned char set, int element);
unsigned char unionSet(unsigned char A, unsigned char B);
unsigned char intersection(unsigned char A, unsigned char B);
unsigned char difference(unsigned char A, unsigned char B);

int main() {
  unsigned char A;
  unsigned char B;

  initialize(&A);
  initialize(&B);
  
  insert(&B, 1);
  insert(&B, 5);
  insert(&B, 3);
  
  printf("== inserting ==\n");
  printf("inserting 1 to set A: ");
  insert(&A, 1);
  display(A);
  printf("\ninserting 6 to set A: ");
  insert(&A, 6);
  display(A);
  printf("\ninserting 7 to set A: ");
  insert(&A, 7);
  display(A);  
  
  printf("\n\n== deletion ==");
  printf("\ndeleting 6 from set A: ");
  delete(&A, 6);
  display(A);
  
  printf("\n\n== finding ==");
  printf("\nfinding 6 from set A: ");
  printf("%s", find(A, 6)? "found":"not found");
  printf("\nfinding 1 from set A: ");
  printf("%s", find(A, 1)? "found":"not found");
  
  printf("\n\n== union of both sets A and B == ");
  printf("\nset A: "); display(A);
  printf("\nset B: "); display(B);
  printf("\nunion: "); display(unionSet(A, B));
  
  printf("\n\n== intersection of both sets A and B == ");
  printf("\nset A: "); display(A);
  printf("\nset B: "); display(B);
  printf("\nintersection: "); display(intersection(A, B)); 
  
  printf("\n\n== set difference of A and B (kung unsay wala sa B/A) == ");
  printf("\nset A: "); display(A);
  printf("\nset B: "); display(B);
  printf("\ndifference (A-B): "); display(difference(A, B));   
  printf("\ndifference (B-A): "); display(difference(B, A));    
  
  return 0;
}

void initialize(unsigned char *set) {
  *set = 0;
}

void insert(unsigned char *set, int element) {
  if(element < 0 || element > 7) return;
  *set |= (1 << element);
}

void delete(unsigned char *set, int element) {
  if(element < 0 || element > 7) return;
  unsigned char newSet = 0;
  newSet |= (1<<element);
  *set &= ~(newSet);
}

bool find(unsigned char set, int element) {
  unsigned char newSet = 1<<element;
  return (set & newSet);
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

unsigned char unionSet(unsigned char A, unsigned char B) {
  return (A|B);
}

unsigned char intersection(unsigned char A, unsigned char B) {
  return (A&B);
}

unsigned char difference(unsigned char A, unsigned char B) {
  return (A & (~B));
}
