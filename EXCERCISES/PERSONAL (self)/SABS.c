#include <stdio.h>
#include <stdbool.h>
#define MAX 6 // should be 100

/* 

STATIC ARRAY-BASED SET 
STATIC ARRAY-BASED SET
STATIC ARRAY-BASED SET 

*/

typedef struct {
  int Set[MAX];
  int count;
} Set;

Set insert(Set, int);
Set _remove(Set, int);
bool contains(Set, int);
Set _union(Set, Set, Set);
Set intersection(Set, Set, Set);
Set difference(Set, Set, Set);

int main() {
    Set A;
    for(int i=0; i<MAX; i++) { A.Set[i] = -1; }
    A.count = 4;
    A.Set[0] = 1;
    A.Set[1] = 2;
    A.Set[2] = 7;
    A.Set[3] = 5;
    A.Set[4] = 6;    
    
    Set B;
    for(int i=0; i<MAX; i++) { B.Set[i] = -1; }    
    B.count = 4;
    B.Set[0] = 0;
    B.Set[1] = 2;
    B.Set[2] = 7;
    B.Set[3] = 3;
    
    Set C;
    for(int i=0; i<MAX; i++) { C.Set[i] = -1; }    
    C.count = 0;
    C = difference(A, B, C);
}

Set difference(Set a, Set b, Set c) {
  int elem;
  for(int i=0; i<MAX; i++) {
    if((b.Set[i] != -1 || a.Set[i] != -1) && !contains(a, b.Set[i])) { 
      elem = a.Set[i];
      c = insert(c, elem);      
    }
  }
  return c;
}

Set intersection(Set a, Set b, Set c) {
  for(int i=0; i<MAX; i++) {
    if((b.Set[i] != -1 || a.Set[i] != -1) && contains(a, b.Set[i])) { c = insert(c, a.Set[i]); }
  }
  return c;
}

Set _union(Set a, Set b, Set c) {
  for(int i=0; i<MAX; i++) {
    c = insert(c, a.Set[i]);
    c = insert(c, b.Set[i]);
  }
  c.count /= 2;
  return c;
}

bool contains(Set a, int elem) {
  for(int i=0; i<a.count; i++) {
    if(a.Set[i] == elem) { return true; }
  }
  return false;
}

Set _remove(Set a, int elem) {
    if(a.count == 0 || !contains(a, elem)) { return a; }
    
    else {
        int pos=0;
        while(pos < a.count && a.Set[pos] != elem) {
            ++pos;
        }
        
        int i;
        for(i=pos; i<a.count; i++) {
            a.Set[i] = a.Set[i+1];
        }
        a.count--;
    }
    return a;
}

Set insert(Set a, int elem) {
  int pos=0;
  
  if(a.count < MAX) {
    
    if(contains(a, elem)) { return a; }
    
    while(pos < a.count && a.Set[pos] < elem) {
      ++pos;
    }
    
    int i;
    for(i=a.count; i >= pos; i--) {
      a.Set[i] = a.Set[i-1];
    }
    a.Set[pos] = elem;
  }
  
  a.count++;
  return a;
}