#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void initialize(unsigned char *set);
void insert(unsigned char *set, int element);
void delete(unsigned char *set, int element);
void display(unsigned char set);
bool find(unsigned char set, int element);

int main() {
  unsigned char A;

  initialize(&A);
  insert(&A, 1);
  display(A);
  insert(&A, 6);
  printf("\n");
  display(A);

  //printf("\n");
  //delete(&A, 6);
  //display(A);  
  
  return 0;
}

bool find(unsigned char set, int element) {
  int bits = sizeof(unsigned char)*8;
  unsigned int mask = 1 << (bits-1);
  element = pow(2, element);
  bool found = false;
  
  while(mask !=0) {
      if(mask&element)
  }
}

void initialize(unsigned char *set) {
  *set = 0;
}

void insert(unsigned char *set, int element) {
  element = pow(2, element);
  *set |= element;
  
}
void delete(unsigned char *set, int element) {
    element = pow(2, element);
    unsigned char test = 0;
    test = ~(test);
    test ^= element;
    *set &= test;
}

void display(unsigned char set) {
  int bits = sizeof(unsigned char)*8;
  unsigned int mask = 1 << (bits-1);
  
  while(mask != 0) {
    printf("%d ", (set&mask)? 1:0);
    mask >>= 1;
  }
}

