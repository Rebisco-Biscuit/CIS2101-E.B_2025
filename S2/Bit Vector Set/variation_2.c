#include <stdio.h>

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
Set union(Set A, Set B);
Set intersection(Set A, Set B);
Set difference(Set A, Set B);
void display(unsigned char set);

int main () {

}