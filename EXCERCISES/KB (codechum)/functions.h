#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

// initVHeap
void initVHeap(VHeap *V) {
    V->avail = 0;
    int i;
    for(i=0; i<MAX_SIZE-1; i++) {
        V->H[i].next = i+1;
    }
    V->H[i].next = -1;
}

// alloc
int alloc(VHeap *V) {
    int ret = V->avail;
    if(ret != -1) {
        V->avail = V->H[ret].next;
    }
    return ret;
}
// dealloc
void dealloc(VHeap *V, int index) {
    int temp = V->H[index].next;
    V->H[index].next = V->avail;
    V->avail = temp;
}

// insertArticle
int insertArticle(VHeap *V, int *L, Article article, int pos) {
    if(V->avail == -1) {
        printf("Error: Heap is full. Cannot insert new article.\n");
    }
    if(pos == 0) {
        int newCell = alloc(V);
        if(newCell != -1) {
            memcpy(&V->H[newCell].article, &article, sizeof(Article));
            V->H[newCell].next = *L;
        }
        *L = newCell;
    } else if (pos == -1) {
        int newCell = alloc(V);
        if(newCell != -1) {
            memcpy(&V->H[newCell].article, &article, sizeof(Article));
            V->H[newCell].next = -1;
            
            int *trav = L;
            while(*trav != -1) {
                trav = &V->H[*trav].next;
            }
            *trav = newCell;
        }
    } else {
        int newCell = alloc(V);
        if (newCell != -1) {
            memcpy(&V->H[newCell].article, &article, sizeof(Article));

            int *trav = L;
            int count = 0;
            while (*trav != -1 && count < pos - 1) {
                trav = &V->H[*trav].next;
                count++;
            }

            if (*trav != -1) {
                V->H[newCell].next = V->H[*trav].next; 
                V->H[*trav].next = newCell;
            } else {
                V->H[newCell].next = -1;
                *trav = newCell;
            }
        }
    }
}

// viewArticles
void viewArticles(VHeap V, int head) {
    if(head == -1) { return; }
    printf("\n--- List of Articles ---\n");
    while(head != -1) {
        printf("ID: %d | Title: %s\n", V.H[head].article.id, V.H[head].article.title);
        head = V.H[head].next;    
    }
    printf("------------------------\n\n");
}

// searchArticle
void searchArticle(VHeap V, int head, int id) {
    if(head == -1) { return; }
    int isFound = 0;
    while(head != -1) {
        if(V.H[head].article.id == id) {
            isFound = 1;
            break;
        }
        head = V.H[head].next;        
    }
    
    if(isFound == 1) {
        printf("\n--- Article Found ---\n");
        printf("ID: %d\nTitle: %s\nContent: %s\n", V.H[head].article.id, V.H[head].article.title, V.H[head].article.content);
        printf("---------------------\n\n");        
    } else {
        printf("Article with ID %d not found.\n\n", id);
    }

        
}

// deleteArticle
int deleteArticle(VHeap *V, int *L, int id) {
    int *trav, temp;
    trav = L;
    int isFound = 0;
    while(*trav != -1) {
        if(V->H[*trav].article.id == id) {
            isFound = 1;
            break;
        }
        trav = &V->H[*trav].next;
    }
    
    if(*trav != -1 && isFound == 1) {
        temp = *trav;
        dealloc(V, temp);
    } else {
        printf("Article with ID %d not found.\n\n", id);
    }
    
}