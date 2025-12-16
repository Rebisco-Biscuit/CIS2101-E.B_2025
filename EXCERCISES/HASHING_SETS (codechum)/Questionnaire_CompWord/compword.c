#include <stdio.h>
#include <stdbool.h>
#include "compword.h"

// write your functions here...
void setAnswer(CompWord* profile, int index, int value) {
    short int mask = 1 << index;
    
    if(value == 1) {
        *profile |= mask;
    } else {
        *profile &= mask;
    }
}

int getAnswer(CompWord profile, int index) {
    return (profile >> index) & 1;
}

int countYesAnswers(CompWord profile) {
    short int mask = 1;
    int count = 0;
    
    for(int i=0; i<10; i++){
        if((profile&mask) !=0) count++;
        mask <<= 1;
    }
    
    return count;
}

void printAnswers(CompWord profile) {
    short int mask = 1 << 9;
    while(mask != 0) {
        printf("%d", (profile&mask)? 1:0);
        mask >>= 1;
    }
    printf("\n");
}

int compareProfiles(CompWord a, CompWord b) {
    short int mask = 1 << 9;
    short int ab;
    int match = 0;

    while (mask != 0) {
        int bitA = (a & mask)? 1:0;
        int bitB = (b & mask)? 1:0;

        if (bitA == bitB) match++;
        
        mask >>= 1;
    }
    return match;
}

CompWord unionProfiles(CompWord a, CompWord b) {
    short int onion;
    onion |= a | b;
}

CompWord intersectProfiles(CompWord a, CompWord b) {
    short int ab;
    ab |= a & b;
}

CompWord differenceProfiles(CompWord a, CompWord b) {
    short int diff;
    diff |= a & (~b);
}