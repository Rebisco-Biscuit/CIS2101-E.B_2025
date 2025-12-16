#include <stdio.h>
#include <stdbool.h>
#include "bitvector.h"

// write your funcitons here...
void setAnswer(BitVect* profile, int index, int value) {
    profile->answers[index] = (value == '1') ? '1' : '0';
}

int getAnswer(BitVect profile, int index) {
    return (profile.answers[index] == '1') ? 1 : 0;
}

int countYesAnswers(BitVect profile) {
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (profile.answers[i] == '1') count++;
    }
    return count;
}

int compareProfiles(BitVect a, BitVect b) {
    int match = 0;
    for (int i = 0; i < 10; i++) {
        if (a.answers[i] == b.answers[i]) match++;
    }
    return match;
}

void printAnswers(BitVect profile) {
    for(int i=9; i>=0; i--) {
        printf("%c", profile.answers[i]);
    }
    printf("\n");
}

BitVect unionProfiles(BitVect a, BitVect b) {
    BitVect onion;
    for (int i = 0; i < 10; i++) {
        onion.answers[i] = (a.answers[i] == '1' || b.answers[i] == '1') ? '1' : '0';
    }
    return onion;
}

BitVect intersectProfiles(BitVect a, BitVect b) {
    BitVect ab;
    for (int i = 0; i < 10; i++) {
        ab.answers[i] = (a.answers[i] == '1' && b.answers[i] == '1') ? '1' : '0';
    }
    return ab;
}

BitVect differenceProfiles(BitVect a, BitVect b) {
    BitVect diff;
    for (int i = 0; i < 10; i++) {
        diff.answers[i] = (a.answers[i] == '1' && b.answers[i] == '0') ? '1' : '0';
    }
    return diff;
}