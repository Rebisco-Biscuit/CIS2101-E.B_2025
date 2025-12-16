#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "set.h"

// write your functions here...
Set* createSet() {
    Set* newSet = malloc(sizeof(Set));
    newSet->head = NULL;
    newSet->size = 0;
    return newSet;
}

bool containsSpell(Set* set, String spell) {
    Node* trav = set->head;
    while (trav != NULL) {
        if (strcmp(trav->spell, spell) == 0) return true;
        trav = trav->next;
    }
    return false;
}

bool addSpell(Set* set, String spell) {
    if (containsSpell(set, spell)) return false;

    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->spell, spell);
    newNode->next = set->head;
    set->head = newNode;
    
    set->size++;
    return true;
}

bool removeSpell(Set** set, String spell) {
    Node** trav = &((*set)->head);
    for(; *trav != NULL && strcmp((*trav)->spell, spell) != 0; trav = &(*trav)->next){}

    if (*trav != NULL) {
        Node* temp = *trav;
        *trav = temp->next;
        free(temp);
        (*set)->size--;
        return true;
    }
    return false;
}

void printSet(Set* set) {
    Node* trav = set->head;
    int i = 1;
    while (trav != NULL && i <= set->size) {
        printf("%3d. %s\n", i++, trav->spell);
        trav = trav->next;
    }
}

void destroySet(Set* set) {
    while (set->head != NULL) {
        removeSpell(&set, set->head->spell);
    }
}

Set* unionSets(Set* set1, Set* set2) {
    Set* newSet = createSet();
    Node* trav;

    for (trav = set1->head; trav != NULL; trav = trav->next)
        addSpell(newSet, trav->spell);

    for (trav = set2->head; trav != NULL; trav = trav->next)
        addSpell(newSet, trav->spell);

    return newSet;
}

Set* intersectSets(Set* set1, Set* set2) {
    Set* newSet = createSet();
    Node* trav;

    for (trav = set1->head; trav != NULL; trav = trav->next) {
        if (containsSpell(set2, trav->spell)) {
            addSpell(newSet, trav->spell);
        }
    }

    return newSet;
}