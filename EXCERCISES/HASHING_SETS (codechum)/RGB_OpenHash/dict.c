#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#include <stdbool.h>
//if allowed hehe

// Write your functions here...
int hashFunction(int rgb[3]) {
    int hash = (rgb[0] * 3 + rgb[1] * 5 + rgb[2] * 7) % PALETTE_SIZE;
    return hash;
}

void createDictionary(Dictionary *dict) {
    for(int i=0; i<PALETTE_SIZE-1; i++) {
        dict->buckets[i] = NULL;
    }
}

Node* createNode(Color newColor) {
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL) { return NULL; }
    
    
    newNode->data = newColor;
    newNode->next = NULL;
    
    return newNode;
}

void insertColor(Dictionary *dict, Color newColor) {
    int hash = hashFunction(newColor.RGBVal);
    
    if(dict->buckets[hash] == NULL) {
        dict->buckets[hash] = createNode(newColor);
    } else {
        Node* nodePTR = createNode(newColor);
        nodePTR->next = dict->buckets[hash];
        dict->buckets[hash] = nodePTR;
    }
    printf("-> Inserted '%s' (RGB: %d, %d, %d) into bucket [%d].\n", newColor.colorName, newColor.RGBVal[0], newColor.RGBVal[1], newColor.RGBVal[2], hash);
}

bool sameRGB(int a[3], int b[3]) {
    return a[0]==b[0] && a[1]==b[1] && a[2]==b[2];
}
//if allowed

Color* searchColor(Dictionary *dict, int rgb[3]) {
    int hash = hashFunction(rgb);
    
    printf("Searching for RGB (%d, %d, %d) in bucket [%d]...\n", rgb[0], rgb[1], rgb[2], hash);
    
    if(dict->buckets[hash] == NULL) { return NULL; }
    
    else {
        Node* trav = dict->buckets[hash];
        Color* colorPTR = NULL;
        while(trav != NULL && !sameRGB(trav->data.RGBVal, rgb)) { 
            trav = trav->next;
        }
        colorPTR = &trav->data;
        return colorPTR;
    }
}